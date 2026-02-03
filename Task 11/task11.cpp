#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <deque>

/* TASK 1: Reverse Print Using Iterator */
void reverse_print(const std::vector<int>& vec)
{
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

/* TASK 2: Multiply All Elements */
void multiply_all(std::vector<int>& vec, int factor)
{
    std::for_each(vec.begin(), vec.end(),
                  [factor](int& x) { x *= factor; });
}

/* TASK 3: Sort Strings by Length */
void sort_by_length(std::vector<std::string>& vec)
{
    std::sort(vec.begin(), vec.end(),
              [](const std::string& a, const std::string& b)
              {
                  return a.length() < b.length();
              });
}

/* TASK 4: Find Maximum Value */
int find_maximum(const std::vector<int>& vec)
{
    int max_value = vec[0];
    std::for_each(vec.begin(), vec.end(),
                  [&max_value](int x)
                  {
                      if (x > max_value)
                          max_value = x;
                  });
    return max_value;
}

/* TASK 5: Calculate Average */
double calculate_average(const std::vector<double>& vec)
{
    double sum = 0.0;
    std::for_each(vec.begin(), vec.end(),
                  [&sum](double x) { sum += x; });
    return sum / vec.size();
}

/* TASK 6: Erase All Negative Numbers */
void erase_negatives(std::vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); )
    {
        if (*it < 0)
            it = vec.erase(it);
        else
            ++it;
    }
}

/* TASK 7: Merge Two Sorted Vectors */
void merge_sorted(std::vector<int>& first, const std::vector<int>& second)
{
    first.insert(first.end(), second.begin(), second.end());
    std::sort(first.begin(), first.end());
}

/* TASK 8: Count Strings Starting With Letter */
int count_starting_with(const std::vector<std::string>& vec, char letter)
{
    int count = 0;
    std::for_each(vec.begin(), vec.end(),
                  [&count, letter](const std::string& s)
                  {
                      if (!s.empty() && s[0] == letter)
                          ++count;
                  });
    return count;
}

/* MAIN FUNCTION - Test Your Solutions */
int main()
{
    // Task 1
    std::vector<int> v1 = {4, 8, 12};
    std::cout << "Task 1 output:" << std::endl;
    reverse_print(v1);

    // Task 2
    std::vector<int> v2 = {2, 4, 6};
    multiply_all(v2, 3);
    std::cout << "Task 2 output:";
    for (int x : v2) std::cout << " " << x;
    std::cout << std::endl;

    // Task 3
    std::vector<std::string> v3 = {"house", "car", "a", "computer"};
    sort_by_length(v3);
    std::cout << "Task 3 output:";
    for (const auto& s : v3) std::cout << " " << s;
    std::cout << std::endl;

    // Task 4
    std::vector<int> v4 = {15, 3, 27, 9};
    std::cout << "Task 4 output: " << find_maximum(v4) << std::endl;

    // Task 5
    std::vector<double> v5 = {1.5, 2.5, 3.5};
    std::cout << "Task 5 output: " << calculate_average(v5) << std::endl;

    // Task 6
    std::vector<int> v6 = {5, -3, 7, -1, 9};
    erase_negatives(v6);
    std::cout << "Task 6 output:";
    for (int x : v6) std::cout << " " << x;
    std::cout << std::endl;

    // Task 7
    std::vector<int> v7a = {1, 4, 7};
    std::vector<int> v7b = {2, 3, 6};
    merge_sorted(v7a, v7b);
    std::cout << "Task 7 output:";
    for (int x : v7a) std::cout << " " << x;
    std::cout << std::endl;

    // Task 8
    std::vector<std::string> v8 = {"Anna", "Bob", "Alex", "alice"};
    std::cout << "Task 8 output: "
              << count_starting_with(v8, 'A') << std::endl;

    return 0;
}
