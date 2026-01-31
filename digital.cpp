#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <limits>
using namespace std;

// STUDENT CLASS
// ====================================
class Student {
private:
    int id;
    string name;
    string password;
    map<string, int> grades; // ONE grade per subject

public:
    Student() {}

    Student(int i, string n, string p, const vector<string>& subjects)
        : id(i), name(n), password(p)
    {
        // auto-fill subjects (-1 = no grade yet)
        for (auto& s : subjects)
            grades[s] = -1;
    }

    int getId() { return id; }
    string getName() { return name; }
    string getPassword() { return password; }
    map<string,int>& getGrades() { return grades; }

    void setGrade(const string& subject, int grade) {
        grades[subject] = grade;
    }

    double average() {
        int total = 0, count = 0;
        for (auto& g : grades) {
            if (g.second != -1) {
                total += g.second;
                count++;
            }
        }
        return (count == 0) ? 0 : (double)total / count;
    }

    void display() {
        cout << "\n=== Report for " << name 
             << " (ID: " << setw(4) << setfill('0') << id << ") ===\n";

        for (auto& g : grades) {
            cout << "  " << g.first << ": ";
            if (g.second == -1) cout << "No grade\n";
            else cout << g.second << "\n";
        }

        cout << fixed << setprecision(2);
        cout << "  Average: " << average() << "\n";
    }

    // saves student to file
    void save(ofstream& out) {
        out << setw(4) << setfill('0') << id 
            << ";" << name << ";" << password;

        for (auto& g : grades) {
            out << ";" << g.first << ":";
            if (g.second != -1)
                out << g.second;
        }
        out << "\n";
    }

    // Load student from file
    void load(string line) {
        grades.clear();
        stringstream ss(line);
        string part;

        getline(ss, part, ';');
        id = stoi(part);

        getline(ss, name, ';');
        getline(ss, password, ';');

        // remaining are subject:grade
        while (getline(ss, part, ';')) {
            size_t pos = part.find(":");
            if (pos != string::npos) {
                string sub = part.substr(0, pos);
                string g = part.substr(pos + 1);

                if (g == "") grades[sub] = -1;
                else grades[sub] = stoi(g);
            }
        }
    }
};

// GLOBAL DATA
// ====================================
vector<Student> students;
vector<string> subjects;
int nextID = 1;

void loadSubjects() {
    subjects.clear();
    ifstream in("subjects.txt");
    string line;
    while (getline(in, line)) {
        if (!line.empty())
            subjects.push_back(line);
    }
    in.close();
}

void saveSubjects() {
    ofstream out("subjects.txt");
    for (auto& s : subjects)
        out << s << "\n";
    out.close();
}

void loadStudents() {
    students.clear();
    ifstream in("students.txt");
    string line;
    while (getline(in, line)) {
        if (line.empty()) continue;

        Student s;
        s.load(line);
        students.push_back(s);

        if (s.getId() >= nextID)
            nextID = s.getId() + 1;
    }
}

void saveStudents() {
    ofstream out("students.txt");
    for (auto& s : students)
        s.save(out);
    out.close();
}

Student* findStudent(int id) {
    for (auto& s : students)
        if (s.getId() == id)
            return &s;
    return nullptr;
}

void addStudent() {
    string name, password;

    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, name);

    cout << "Enter password: ";
    getline(cin, password);

    students.push_back(Student(nextID, name, password, subjects));

    cout << "Student added with ID: " 
         << setw(4) << setfill('0') << nextID << "\n";

    nextID++;
    saveStudents();
}

void removeStudent() {
    int id;
    cout << "Enter student ID to remove: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            students.erase(students.begin() + i);
            cout << "Student removed.\n";
            saveStudents();
            return;
        }
    }
    cout << "Student not found.\n";
}

void addSubject() {
    string s;
    cout << "Enter new subject: ";
    cin.ignore();
    getline(cin, s);

    subjects.push_back(s);


    for (auto& st : students)
        st.getGrades()[s] = -1;

    saveSubjects();
    saveStudents();
    cout << "Subject added.\n";
}

void removeSubject() {
    cout << "\nSubjects:\n";
    for (int i = 0; i < subjects.size(); i++)
        cout << i+1 << ". " << subjects[i] << "\n";

    int choice;
    cout << "Enter number to remove: ";
    cin >> choice;

    if (choice < 1 || choice > subjects.size()) {
        cout << "Invalid.\n";
        return;
    }

    string toRemove = subjects[choice - 1];

    subjects.erase(subjects.begin() + choice - 1);

    for (auto& s : students)
        s.getGrades().erase(toRemove);

    saveSubjects();
    saveStudents();
}

void addGrade() {
    int id, grade;
    cout << "Enter student ID: ";
    cin >> id;

    Student* s = findStudent(id);
    if (!s) {
        cout << "Not found.\n";
        return;
    }

    cout << "\nSubjects:\n";
    for (int i = 0; i < subjects.size(); i++)
        cout << i+1 << ". " << subjects[i] << "\n";

    int choice;
    cout << "Choose subject: ";
    cin >> choice;

    if (choice < 1 || choice > subjects.size()) {
        cout << "Invalid.\n";
        return;
    }

    string subject = subjects[choice - 1];

    cout << "Enter grade: ";
    cin >> grade;

    s->setGrade(subject, grade);
    saveStudents();

    cout << "Grade saved.\n";
}


bool adminLogin() {
    string u, p;
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    return (u == "admin" && p == "1234");
}

Student* studentLogin() {
    int id;
    string p;

    cout << "ID: ";
    cin >> id;
    cout << "Password: ";
    cin >> p;

    Student* s = findStudent(id);

    if (s && s->getPassword() == p)
        return s;

    cout << "Invalid.\n";
    return nullptr;
}

void adminMenu() {
    int ch;
    do {
        cout << "\n=== ADMIN MENU ===\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Add Subject\n";
        cout << "4. Remove Subject\n";
        cout << "5. Add/Change Grade\n";
        cout << "6. View Students\n";
        cout << "7. Logout\n";
        cout << "Choice: ";
        cin >> ch;

        switch(ch) {
            case 1: addStudent(); break;
            case 2: removeStudent(); break;
            case 3: addSubject(); break;
            case 4: removeSubject(); break;
            case 5: addGrade(); break;
            case 6:
                for (auto& s : students) s.display();
                break;
        }
    } while (ch != 7);
}

void studentMenu(Student* s) {
    int ch;
    do {
        cout << "\n=== STUDENT MENU ===\n";
        cout << "1. View Report\n";
        cout << "2. Logout\n";
        cout << "Choice: ";
        cin >> ch;

        if (ch == 1)
            s->display();

    } while (ch != 2);
}

int main() {
    loadSubjects();
    loadStudents();

    int ch;
    do {
        cout << "\n=== DIGITAL GRADEBOOK ===\n";
        cout << "1. Admin Login\n";
        cout << "2. Student Login\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> ch;

        if (ch == 1) {
            if (adminLogin()) adminMenu();
            else cout << "Wrong login.\n";
        }
        else if (ch == 2) {
            Student* s = studentLogin();
            if (s) studentMenu(s);
        }

    } while (ch != 3);

    saveStudents();
    saveSubjects();
    return 0;
}
