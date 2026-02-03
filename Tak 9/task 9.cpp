/** @file */

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <array>
#include <utility>

// ---------- Task 1 ----------
struct book
{
    std::string title;
    std::string author;
    int year;
    int pages;
};

// ---------- Task 2 ----------
std::pair<int, double> sumAndAverage(const std::vector<int>& numbers)
{
    int sum = 0;
    for (int n : numbers)
    {
        sum += n;
    }
    double average = static_cast<double>(sum) / numbers.size();
    return {sum, average};
}

// ---------- Task 5 ----------
struct student
{
    std::string name;
    int id;
    std::vector<double> grades;
};

// ---------- Task 6 ----------
struct processor
{
    std::string manufacturer;
    std::string model;
    double speedGHz;
};

struct computer
{
    std::string brand;
    std::string model;
    processor cpu;
};

int main()
{
    // Task 1: Books
    std::vector<book> books = {
        {"1984", "George Orwell", 1949, 328},
        {"The Hobbit", "J.R.R. Tolkien", 1937, 310},
        {"Dune", "Frank Herbert", 1965, 412}
    };

    std::cout << "Author of second book: " << books[1].author << "\n\n";

    // Task 2: Sum and average
    std::vector<int> numbers = {12, 45, 67, 23, 89, 34};
    auto result = sumAndAverage(numbers);

    std::cout << "Sum: " << result.first << "\n";
    std::cout << "Average: " << result.second << "\n\n";

    // Task 3: Temperatures
    std::array<double, 5> temperatures = {21.5, 18.2, 30.1, 25.6, 16.9};

    double minTemp = temperatures[0];
    double maxTemp = temperatures[0];

    for (double temp : temperatures)
    {
        if (temp < minTemp) minTemp = temp;
        if (temp > maxTemp) maxTemp = temp;
    }

    std::cout << "Lowest temperature: " << minTemp << " C\n";
    std::cout << "Highest temperature: " << maxTemp << " C\n\n";

    // Task 4: Phone book
    std::map<std::string, std::string> phoneBook;
    phoneBook["Alice"] = "123-4567";
    phoneBook["Bob"] = "234-5678";
    phoneBook["Charlie"] = "345-6789";
    phoneBook["Diana"] = "456-7890";

    std::cout << "Bob's phone number: " << phoneBook["Bob"] << "\n\n";

    std::cout << "Phone book entries:\n";
    for (const auto& entry : phoneBook)
    {
        std::cout << entry.first << ": " << entry.second << '\n';
    }
    std::cout << '\n';

    // Task 5: Students and grades
    student s1{"Emma", 1001, {85.5, 90.0, 78.5}};
    student s2{"Liam", 1002, {88.0, 92.5, 81.0, 95.0}};

    auto calculateAverage = [](const student& s)
    {
        double sum = 0.0;
        for (double g : s.grades)
        {
            sum += g;
        }
        return sum / s.grades.size();
    };

    std::cout << s1.name << " average grade: " << calculateAverage(s1) << '\n';
    std::cout << s2.name << " average grade: " << calculateAverage(s2) << "\n\n";

    // Task 6: Computer with nested processor
    computer pc{
        "Dell",
        "XPS 15",
        {"Intel", "Core i7-12700H", 2.7}
    };

    std::cout << "Computer details:\n";
    std::cout << "Brand: " << pc.brand << '\n';
    std::cout << "Model: " << pc.model << '\n';
    std::cout << "CPU Manufacturer: " << pc.cpu.manufacturer << '\n';
    std::cout << "CPU Model: " << pc.cpu.model << '\n';
    std::cout << "CPU Speed: " << pc.cpu.speedGHz << " GHz\n\n";

    // Task 7: Character frequency
    std::string text = "programming is fun and challenging";
    std::map<char, int> charCount;

    for (char c : text)
    {
        if (c != ' ')
        {
            charCount[c]++;
        }
    }

    std::cout << "Character counts:\n";
    for (const auto& entry : charCount)
    {
        std::cout << entry.first << ": " << entry.second << '\n';
    }

    return 0;
}
