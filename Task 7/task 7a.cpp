#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// ========================
// TASK 1 – Absolute Value
// ========================
int absolute(const int value) {
    return (value < 0) ? -value : value;
}

double absolute(const double value) {
    return (value < 0) ? -value : value;
}

void absolute(vector<int> &vec) {
    for (int &x : vec) {
        if (x < 0) x = -x;
    }
}

// ========================
// TASK 2 – File Writing
// ========================
bool write_students(const string &filename,
                    const vector<string> &names,
                    const vector<int> &scores)
{
    if (names.size() != scores.size()) return false;

    ofstream file(filename);
    if (!file) return false;

    for (size_t i = 0; i < names.size(); i++) {
        file << "Name: " << names[i]
             << ", Score: " << scores[i] << endl;
    }

    return true;
}

// ========================
// TASK 3 – File Reading
// ========================
vector<double> read_numbers(const string &filename) {
    vector<double> numbers;
    ifstream file(filename);
    if (!file) return numbers;

    double num;
    while (file >> num) {
        numbers.push_back(num);
    }
    return numbers;
}

int count_positive(const vector<double> &numbers) {
    int count = 0;
    for (double x : numbers) if (x > 0) count++;
    return count;
}

int count_negative(const vector<double> &numbers) {
    int count = 0;
    for (double x : numbers) if (x < 0) count++;
    return count;
}

// ========================
// TASK 4 – References
// ========================
void sort_three(int &a, int &b, int &c) {
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);  
}

void increment_all(int &a, int &b, int &c, const int value) {
    a += value;
    b += value;
    c += value;
}

void make_equal(int &a, int &b, int &c) {
    int avg = (a + b + c) / 3;
    a = b = c = avg;
}

// ========================
// TASK 5 – String Streams
// ========================
vector<int> parse_integers(const string &text) {
    vector<int> result;
    stringstream ss(text);
    string word;

    while (ss >> word) {
        stringstream inner(word);
        int x;
        if (inner >> x) result.push_back(x);
    }
    return result;
}

string join_strings(const vector<string> &words, const string &delimiter) {
    string result = "";
    for (size_t i = 0; i < words.size(); i++) {
        result += words[i];
        if (i + 1 < words.size()) result += delimiter;
    }
    return result;
}

int count_tokens(const string &text) {
    stringstream ss(text);
    int count = 0;
    string token;
    while (ss >> token) count++;
    return count;
}

// ========================
// TASK 6 – Recursion
// ========================
int array_sum_recursive(const int array[], const int length, const int index = 0) {
    if (index >= length) return 0;
    return array[index] + array_sum_recursive(array, length, index + 1);
}

int find_max_recursive(const int array[], const int length, const int index = 0) {
    if (index == length - 1) return array[index];
    int max_rest = find_max_recursive(array, length, index + 1);
    return max(array[index], max_rest);
}

// ========================
// TASK 7 – Multi-File Processing
// ========================
struct DataSummary {
    string filename;
    int line_count;
    int word_count;
    int char_count;
};

DataSummary analyze_file(const string &filename) {
    DataSummary summary{filename, 0, 0, 0};
    ifstream file(filename);
    if (!file) return summary;

    string line;
    while (getline(file, line)) {
        summary.line_count++;
        summary.char_count += line.size();

        stringstream ss(line);
        string word;
        while (ss >> word) summary.word_count++;
    }
    return summary;
}

void print_summary(const DataSummary &summary) {
    cout << "File: " << summary.filename << endl;
    cout << "Lines: " << summary.line_count << endl;
    cout << "Words: " << summary.word_count << endl;
    cout << "Characters: " << summary.char_count << endl << endl;
}

void compare_files(const string &file1, const string &file2) {
    DataSummary a = analyze_file(file1);
    DataSummary b = analyze_file(file2);

    cout << "Comparing " << file1 << " and " << file2 << ":\n\n";

    cout << "More lines: "
         << ((a.line_count > b.line_count) ? file1 : file2) << endl;

    cout << "More words: "
         << ((a.word_count > b.word_count) ? file1 : file2) << endl;

    cout << "More characters: "
         << ((a.char_count > b.char_count) ? file1 : file2) << endl;
}

// ========================
// MAIN – DEMONSTRATION
// ========================
int main() {

    // ---- TASK 1 TEST ----
    cout << "TASK 1:\n";
    cout << absolute(-42) << endl;
    cout << absolute(-3.14) << endl;

    vector<int> v = {-5, 10, -15, 20};
    cout << "Before vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    absolute(v);

    cout << "After vector: ";
    for (int x : v) cout << x << " ";
    cout << "\n\n";

    // ---- TASK 2 TEST ----
    cout << "TASK 2:\n"; 
    vector<string> names = {"Anna", "Ben", "Caro", "Dani", "Elvis"};
    vector<int> scores = {90, 85, 78,88,92};

    if (write_students("students.txt", names, scores))
        cout << "Student file written successfully.\n\n";
    else
        cout << "Failed to write student file!\n\n";

    // ---- TASK 3 TEST ----
    vector<double> nums = read_numbers("numbers.txt");

    cout << "TASK 3:\n";
    cout << "Total numbers: " << nums.size() << endl;
    cout << "Positive: " << count_positive(nums) << endl;
    cout << "Negative: " << count_negative(nums) << endl;
    cout << "Zero: " << count(nums.begin(), nums.end(), 0.0) << "\n\n";

    // ---- TASK 4 TEST ----
    cout << "TASK 4:\n";
    int a = 45, b = 12, c = 33;

    sort_three(a, b, c);
    cout << "Sorted: " << a << " " << b << " " << c << endl;

    increment_all(a, b, c, 5);
    cout << "Incremented: " << a << " " << b << " " << c << endl;

    make_equal(a, b, c);
    cout << "Equalized: " << a << " " << b << " " << c << "\n\n";

    // ---- TASK 5 TEST ----
    cout << "TASK 5:\n";
    string text = "The year 2024 has 366 days";
    vector<int> parsed = parse_integers(text);

    cout << "Parsed ints: ";
    for (int x : parsed) cout << x << " ";
    cout << endl;

    cout << join_strings({"Hello", "World", "!"}, ", ") << endl;
    cout << "Token count: " << count_tokens("one two three four") << "\n\n";

    // ---- TASK 6 TEST ----
    cout << "TASK 6:\n";
    int arr[] = {34, 67, 12, 89, 45, 23, 78};
    int len = 7;

    cout << "Sum (recursive): " << array_sum_recursive(arr, len) << endl;
    cout << "Max (recursive): " << find_max_recursive(arr, len) << "\n\n";

    // ---- TASK 7 TEST ----
    cout << "TASK 7:\n";
    DataSummary s1 = analyze_file("file1.txt");
    DataSummary s2 = analyze_file("file2.txt");

    print_summary(s1);
    print_summary(s2);

    compare_files("file1.txt", "file2.txt");

    return 0;
}
