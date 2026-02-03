#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

/* TASK 1: Print Vector Using Iterator */
void print_vector_with_iterator(const std::vector<int>& vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << std::endl;
    }
}

/* TASK 2: Fill Vector with Sequential Numbers */
void fill_sequential(std::vector<int>& vec, int start_value)
{
    std::iota(vec.begin(), vec.end(), start_value);
}

/* TASK 3: Sort Vector in Descending Order */
void sort_descending(std::vector<double>& vec)
{
    std::sort(vec.begin(), vec.end(), [](double a, double b) { return a > b; });
}

/* TASK 4: Count Elements Greater Than Value */
int count_greater_than(const std::vector<int>& vec, int threshold)
{
    int count = 0;
    std::for_each(vec.begin(), vec.end(), [&count, threshold](int x) {
        if (x > threshold) ++count;
    });
    return count;
}

/* TASK 5: Calculate Sum Using Lambda */
double calculate_sum(const std::vector<double>& vec)
{
    double sum = 0.0;
    std::for_each(vec.begin(), vec.end(), [&sum](double x) { sum += x; });
    return sum;
}

/* TASK 6: Find String by Length */
std::string find_by_length(const std::vector<std::string>& vec, int length)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        if (it->length() == static_cast<size_t>(length))
            return *it;
    }
    return "";
}

/* TASK 7: Insert Elements in Middle */
void insert_in_middle(std::vector<int>& target, const std::vector<int>& source)
{
    auto middle = target.begin() + target.size() / 2;
    target.insert(middle, source.begin(), source.end());
}

/* TASK 8: Filter Even Numbers */
std::vector<int> filter_even(const std::vector<int>& vec)
{
    std::vector<int> result;
    std::for_each(vec.begin(), vec.end(), [&result](int x) {
        if (x % 2 == 0) result.push_back(x);
    });
    return result;
}

/* MAIN FUNCTION - Test Your Solutions */
int main()
{
    // Task 1
    std::vector<int> vec1 = {7, 14, 21};
    std::cout << "Task 1 output:" << std::endl;
    print_vector_with_iterator(vec1);

    // Task 2
    std::vector<int> vec2(4);
    fill_sequential(vec2, 50);
    std::cout << "Task 2 output:";
    for (int x : vec2) std::cout << " " << x;
    std::cout << std::endl;

    // Task 3
    std::vector<double> vec3 = {9.1, 3.7, 5.6};
    sort_descending(vec3);
    std::cout << "Task 3 output:";
    for (double x : vec3) std::cout << " " << x;
    std::cout << std::endl;

    // Task 4
    std::vector<int> vec4 = {12, 5, 8, 20, 3};
    std::cout << "Task 4 output: " << count_greater_than(vec4, 3) << std::endl;

    // Task 5
    std::vector<double> vec5 = {2.5, 4.5, 1.0};
    std::cout << "Task 5 output: " << calculate_sum(vec5) << std::endl;

    // Task 6
    std::vector<std::string> vec6 = {"apple", "kiwi", "banana","fig"};
    std::cout << "Task 6 output: " << find_by_length(vec6, 3) << std::endl;

    // Task 7
    std::vector<int> vec7_target = {100, 200, 300, 400};
    std::vector<int> vec7_source = {555, 666};
    insert_in_middle(vec7_target, vec7_source);
    std::cout << "Task 7 output:";
    for (int x : vec7_target) std::cout << " " << x;
    std::cout << std::endl;

    // Task 8
    std::vector<int> vec8 = {11, 22, 33, 44, 55, 66};
    std::vector<int> even_vec = filter_even(vec8);
    std::cout << "Task 8 output:";
    for (int x : even_vec) std::cout << " " << x;
    std::cout << std::endl;

    return 0;
}
