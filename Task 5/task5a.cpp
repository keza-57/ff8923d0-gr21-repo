#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

// TASK 1: constexpr Power Function
constexpr long int power(const int base, const int exponent) {
    long int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

// Declare an array with size power(2,4) to verify compile-time evaluation
constexpr int array_size = power(2, 4);
int compile_time_array[array_size]; // Should compile successfully

// TASK 2: consteval Fibonacci
constexpr long int fibonacci(const int n) {    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// TASK 3: Static Counter with Reset
int& get_counter_ref() {
    static int count = 0;
    return count;
}

int counter() {
    auto& count = get_counter_ref();
    return ++count;
}

void reset_counter() {
    auto& count = get_counter_ref();
    count = 0;
}

// TASK 4: Function with Default Parameters
void print_grade(const std::string& name, int score, 
                 const std::string& course = "Programming", 
                 const std::string& semester = "Fall 2025") {
    std::cout << name << " scored " << score << " in " << course << " (" << semester << ")\n";
}

// TASK 5: Array Statistics Functions
double find_max(const double array[], const int length) {
    double max_val = array[0];
    for (int i = 1; i < length; ++i) {
        if (array[i] > max_val) max_val = array[i];
    }
    return max_val;
}

double find_min(const double array[], const int length) {
    double min_val = array[0];
    for (int i = 1; i < length; ++i) {
        if (array[i] < min_val) min_val = array[i];
    }
    return min_val;
}

double calculate_average(const double array[], const int length) {
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += array[i];
    }
    return sum / length;
}

// TASK 6: Vector Manipulation
void remove_negatives(std::vector<int>& vec) {
    std::vector<int> new_vec;
    for (int v : vec) {
        if (v >= 0) new_vec.push_back(v);
    }
    vec = new_vec;
}

int sum_elements(const std::vector<int>& vec) {
    int sum = 0;
    for (int v : vec) sum += v;
    return sum;
}

// TASK 7: String Vector Operations
void print_strings(const std::vector<std::string>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << i << ": " << vec[i] << "\n";
    }
}

std::string find_longest(const std::vector<std::string>& vec) {
    size_t max_len = 0;
    std::string longest;
    for (const auto& str : vec) {
        if (str.size() > max_len) {
            max_len = str.size();
            longest = str;
        }
    }
    return longest;
}

// TASK 8: Temperature Statistics
void add_temperature(std::vector<double>& temps, double temp) {
    temps.push_back(temp);
}

void print_statistics(const std::vector<double>& temps) {
    if (temps.empty()) {
        std::cout << "No temperature readings.\n";
        return;
    }
    double max_temp = *std::max_element(temps.begin(), temps.end());
    double min_temp = *std::min_element(temps.begin(), temps.end());
    double sum = 0;
    for (double t : temps) sum += t;
    double avg = sum / temps.size();

    std::cout << "Number of readings: " << temps.size() << "\n";
    std::cout << "Highest temperature: " << max_temp << "\n";
    std::cout << "Lowest temperature: " << min_temp << "\n";
    std::cout << "Average temperature: " << avg << "\n";
}

int main() {
    std::cout << "=== FUNDAMENTALS OF COMPUTER PROGRAMMING - PRACTICE TASKS ===\n\n";

    // TASK 1
    std::cout << "TASK 1: constexpr Power Function\n";
    std::cout << "2^10 = " << power(2,10) << "\n";
    std::cout << "5^3 = " << power(5,3) << "\n";
    std::cout << "3^0 = " << power(3,0) << "\n";

    int arr[power(2,4)]; // compile-time array
    std::cout << "Array size with power(2,4): " << sizeof(arr)/sizeof(arr[0]) << "\n\n";

    // TASK 2
    std::cout << "TASK 2: consteval Fibonacci\n";
    constexpr long int fib0 = fibonacci(0);
    constexpr long int fib10 = fibonacci(10);
    constexpr long int fib15 = fibonacci(15);
    std::cout << "fibonacci(0) = " << fib0 << "\n";
    std::cout << "fibonacci(10) = " << fib10 << "\n";
    std::cout << "fibonacci(15) = " << fib15 << "\n";

    int runtime_input = 5;
    // Uncommenting the following line will cause compile-time error because fibonacci is consteval
    // long int fib_runtime = fibonacci(runtime_input);

    // TASK 3
    std::cout << "\nTASK 3: Static Counter with Reset\n";
    std::cout << "Counter calls:\n";
    for (int i = 0; i < 5; ++i) {
        std::cout << "counter() = " << counter() << "\n";
    }
    reset_counter();
    std::cout << "After reset:\n";
    for (int i = 0; i < 3; ++i) {
        std::cout << "counter() = " << counter() << "\n";
    }

    // TASK 4
    std::cout << "\nTASK 4: Function with Default Parameters\n";
    print_grade("Alice", 95, "Math", "Spring 2026");
    print_grade("Bob", 88);
    print_grade("Charlie", 92, "History");

    // TASK 5
    std::cout << "\nTASK 5: Array Statistics\n";
    double data[] = {23.5, 67.8, 12.3, 89.1, 45.6, 34.2};
    int len = sizeof(data)/sizeof(data[0]);
    std::cout << "Max: " << find_max(data, len) << "\n";
    std::cout << "Min: " << find_min(data, len) << "\n";
    std::cout << "Average: " << calculate_average(data, len) << "\n";

    // TASK 6
    std::cout << "\nTASK 6: Vector Manipulation\n";
    std::vector<int> vec = {10, -5, 20, -15, 30, -25, 40};
    std::cout << "Before removing negatives: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\nSum before: " << sum_elements(vec) << "\n";

    remove_negatives(vec);
    std::cout << "After removing negatives: ";
    for (int v : vec) std::cout << v << " ";
    std::cout << "\nSum after: " << sum_elements(vec) << "\n";

    // TASK 7
    std::cout << "\nTASK 7: String Vector Operations\n";
    std::vector<std::string> languages = {"C++", "Python", "JavaScript", "Go", "Rust", "Assembly"};
    print_strings(languages);
    std::cout << "Longest string: " << find_longest(languages) << "\n";

    // TASK 8
    std::cout << "\nTASK 8: Temperature Statistics\n";
    std::vector<double> temps;
    add_temperature(temps, 20.5);
    add_temperature(temps, 22.3);
    add_temperature(temps, 19.8);
    add_temperature(temps, 23.1);
    add_temperature(temps, 21.7);
    add_temperature(temps, 18.9);
    add_temperature(temps, 24.2);
    print_statistics(temps);

    return 0;
}