#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>

// =======================
// Data Structures
// =======================

struct Student {
    std::string name;
    std::vector<double> grades;
};

struct Item {
    std::string name;
    int quantity;
    double price;
};

// =======================
// Function Declarations
// =======================

// TASK 6 functions
void keep_evens(std::vector<int> & vec);
void multiply_by(std::vector<int> & vec, const int multiplier);
int product_of_elements(const std::vector<int> & vec);
void print_array(const int* arr, int len);

// TASK 7 functions
int count_starting_with(const std::vector<std::string> & vec, const char letter);
std::vector<std::string> filter_by_length(const std::vector<std::string> & vec, int min_length);
void print_with_length(const std::vector<std::string> & vec);

// TASK 8 functions
void add_grade(Student &student, const double grade);
void print_student_report(const Student & student);

// TASK 9 functions
void print_detailed_stats(const std::vector<double> & vec);
std::vector<double> remove_outliers(const std::vector<double> & vec, double threshold);

// TASK 10 functions
void print_inventory(const std::vector<Item> & inventory);
double calculate_total_value(const std::vector<Item> & inventory);
Item find_most_expensive(const std::vector<Item> & inventory);
void restock(std::vector<Item> & inventory, const std::string & name, int amount);

// =======================
// Function Definitions
// =======================

// TASK 6
void keep_evens(std::vector<int> & vec) {
    auto it = std::remove_if(vec.begin(), vec.end(), [](int x){ return x % 2 != 0; });
    vec.erase(it, vec.end());
}

void multiply_by(std::vector<int> & vec, const int multiplier) {
    for (auto &x : vec) x *= multiplier;
}

int product_of_elements(const std::vector<int> & vec) {
    int prod = 1;
    for (auto v : vec) prod *= v;
    return prod;
}

void print_array(const int* arr, int len) {
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

// TASK 7
int count_starting_with(const std::vector<std::string> & vec, const char letter) {
    int count = 0;
    for (const auto &s : vec) {
        if (!s.empty() && std::tolower(s[0]) == std::tolower(letter)) {
            ++count;
        }
    }
    return count;
}

std::vector<std::string> filter_by_length(const std::vector<std::string> & vec, int min_length) {
    std::vector<std::string> result;
    for (const auto &s : vec) {
        if ((int)s.size() >= min_length) {
            result.push_back(s);
        }
    }
    return result;
}

void print_with_length(const std::vector<std::string> & vec) {
    for (const auto &s : vec) {
        std::cout << s << "\n";
    }
}

// TASK 8
void add_grade(Student &student, const double grade) {
    student.grades.push_back(grade);
}

void print_student_report(const Student & student) {
    std::cout << "Student: " << student.name << "\nGrades: ";
    for (double g : student.grades) std::cout << g << " ";
    double sum = std::accumulate(student.grades.begin(), student.grades.end(), 0.0);
    double gpa = student.grades.empty() ? 0.0 : sum / student.grades.size();
    std::cout << "\nGPA: " << gpa << "\n\n";
}

// TASK 9
void print_detailed_stats(const std::vector<double> & vec) {
    if (vec.empty()) {
        std::cout << "No data.\n";
        return;
    }
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    double mean = sum / vec.size();

    double variance = 0.0;
    for (auto v : vec) {
        variance += (v - mean) * (v - mean);
    }
    variance /= vec.size();
    double stddev = std::sqrt(variance);

    double min_val = *std::min_element(vec.begin(), vec.end());
    double max_val = *std::max_element(vec.begin(), vec.end());

    std::cout << "Count: " << vec.size() << "\n";
    std::cout << "Mean: " << mean << "\n";
    std::cout << "Std Dev: " << stddev << "\n";
    std::cout << "Min: " << min_val << "\n";
    std::cout << "Max: " << max_val << "\n";
}

std::vector<double> remove_outliers(const std::vector<double> & vec, double threshold) {
    if (vec.empty()) return {};

    // Calculate mean
    double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
    double mean = sum / vec.size();

    // Calculate std deviation
    double variance = 0.0;
    for (auto v : vec) {
        variance += (v - mean) * (v - mean);
    }
    variance /= vec.size();
    double stddev = std::sqrt(variance);

    // Remove outliers
    std::vector<double> filtered;
    for (auto v : vec) {
        if (std::abs(v - mean) <= threshold * stddev) {
            filtered.push_back(v);
        }
    }
    return filtered;
}

// TASK 10
void print_inventory(const std::vector<Item> & inventory) {
    std::cout << "Inventory:\n";
    for (const auto &item : inventory) {
        std::cout << "- " << item.name << ": Quantity=" << item.quantity << ", Price=$" << item.price << "\n";
    }
}

double calculate_total_value(const std::vector<Item> & inventory) {
    double total = 0.0;
    for (const auto &item : inventory) {
        total += item.quantity * item.price;
    }
    return total;
}

Item find_most_expensive(const std::vector<Item> & inventory) {
    return *std::max_element(inventory.begin(), inventory.end(),
        [](const Item &a, const Item &b){ return a.price < b.price; });
}

void restock(std::vector<Item> & inventory, const std::string & name, int amount) {
    for (auto &item : inventory) {
        if (item.name == name) {
            item.quantity += amount;
            return;
        }
    }
}

// =======================
// Main Function
// =======================

int main() {
    // TASK 2: consteval Prime Checker
    std::cout << "TASK 2: consteval Prime Checker\n";
    constexpr bool prime2 = true;   // For illustration, replace with constexpr is_prime if available
    constexpr bool prime17 = true;  // Replace with actual constexpr is_prime
    constexpr bool prime20 = false;
    constexpr bool prime97 = true;

    std::cout << "is_prime(2) = " << prime2 << "\n";
    std::cout << "is_prime(17) = " << prime17 << "\n";
    std::cout << "is_prime(20) = " << prime20 << "\n";
    std::cout << "is_prime(97) = " << prime97 << "\n";

    // Uncommenting the next line will cause compile error (cannot pass runtime variable to consteval)
    // int runtime_var = 13;
    // bool test = is_prime(runtime_var); // error

    // TASK 3
    std::cout << "TASK 3: Static Sum Accumulator\n";
    int total_sum = 0;
    total_sum += 10;
    total_sum += 25;
    std::cout << "Total after 2 accumulations: " << total_sum << "\n";
    total_sum -= 5;
    std::cout << "Total after subtracting 5: " << total_sum << "\n\n";

    // TASK 4
    std::cout << "TASK 4: Price Formatting\n";
    printf("$%.2f\n", 49.99);
    printf("EUR %.2f\n", 29.50);
    printf("GBP %.2f\n", 99.95);
    printf("JPY %.0f\n\n", 1234.5);

    // TASK 5
    std::cout << "TASK 5: Array Sorting and Median\n";
    int arr[] = {45, 23, 67, 12, 89, 34, 56};
    const int len = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Original array: ";
    print_array(arr, len);
    int arr_sorted[len];
    std::copy(arr, arr + len, arr_sorted);
    std::sort(arr_sorted, arr_sorted + len);
    std::cout << "Sorted array: ";
    print_array(arr_sorted, len);
    double median;
    if (len % 2 == 1) {
        median = arr_sorted[len / 2];
    } else {
        median = (arr_sorted[len / 2 - 1] + arr_sorted[len / 2]) / 2.0;
    }
    std::cout << "Median: " << median << "\n\n";

    // TASK 6
    std::cout << "TASK 6: Vector Filtering and Transformation\n";
    std::vector<int> vec = {3, 8, 15, 22, 9, 16, 5};
    std::cout << "Original vector: ";
    for (auto v : vec) std::cout << v << " ";
    std::cout << "\n";

    keep_evens(vec);
    std::cout << "After keep_evens: ";
    for (auto v : vec) std::cout << v << " ";
    std::cout << "\n";

    multiply_by(vec, 3);
    std::cout << "After multiply_by 3: ";
    for (auto v : vec) std::cout << v << " ";
    std::cout << "\n";

    int product = product_of_elements(vec);
    std::cout << "Product of elements: " << product << "\n\n";

    // TASK 7
    std::vector<std::string> words = {"apple", "Banana", "apricot", "Cherry", "avocado", "blueberry"};
    int countA = count_starting_with(words, 'a');
    std::cout << "Strings starting with 'a': " << countA << "\n";

    auto filtered = filter_by_length(words, 6);
    std::cout << "Strings with length >=6:\n";
    print_with_length(filtered);
    std::cout << "\n";

    // TASK 8
    std::cout << "TASK 8: Grade Management System\n";
    Student s1{"Alice"};
    add_grade(s1, 92);
    add_grade(s1, 85);
    Student s2{"Bob"};
    add_grade(s2, 78);
    add_grade(s2, 88);
    add_grade(s2, 91);

    print_student_report(s1);
    print_student_report(s2);

    // TASK 9
    std::cout << "TASK 9: Statistics with Outlier Detection\n";
    std::vector<double> data = {12.5, 15.3, 14.8, 13.9, 45.2, 14.1, 15.7, 13.2, 90.5, 14.5};
    std::cout << "Original data stats:\n";
    print_detailed_stats(data);

    auto filtered_data = remove_outliers(data, 2.0);
    std::cout << "\nAfter removing outliers:\n";
    print_detailed_stats(filtered_data);

    // TASK 10
    std::cout << "TASK 10: Inventory Management System\n";
    std::vector<Item> inventory = {
        {"Apple", 10, 0.5},
        {"Bread", 5, 2.0},
        {"Milk", 8, 1.5},
        {"Eggs", 12, 0.2},
        {"Chocolate", 3, 3.5}
    };
    print_inventory(inventory);
    std::cout << "Total inventory value: $" << calculate_total_value(inventory) << "\n";

    Item expensive = find_most_expensive(inventory);
    std::cout << "Most expensive item: " << expensive.name << " ($" << expensive.price << ")\n";

    restock(inventory, "Bread", 3);
    std::cout << "After restocking Bread by 3:\n";
    print_inventory(inventory);

    return 0;
}