#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>

// Forward declarations
double add(const double l, const double p);
double subtract(const double l, const double p);
double multiply(const double l, const double p);
bool greater_than(double a, double b);

/* TASK 1 ... */


/* TASK 1: Apply Operation Using Function Pointer */
double apply_operation(double a, double b,
                       double (*op)(const double, const double))
{
    return op(a, b);
}

/* TASK 2: Array of Function Pointers */
std::vector<double> all_operations(double a, double b)
{
    double (*operations[])(const double, const double) =
    {
        add,
        subtract,
        multiply
    };

    std::vector<double> results;
    for (auto op : operations)
    {
        results.push_back(op(a, b));
    }
    return results;
}

/* TASK 3: Transform Array Using Function Pointer */
void transform_array(double* begin, double* past_the_last,
                     double (*transform_func)(double))
{
    for (double* ptr = begin; ptr != past_the_last; ++ptr)
    {
        *ptr = transform_func(*ptr);
    }
}

/* TASK 4: Custom Operation with Lambda */
int custom_calc(int a, int b)
{
    std::function<int(int, int)> calc =
        [](int x, int y)
        {
            return (x * y) + (x - y);
        };
    return calc(a, b);
}

/* TASK 5: Filter Array Using Pointer Arithmetic */
int count_above_threshold(double* arr, int size, double threshold)
{
    int count = 0;
    for (double* ptr = arr; ptr < arr + size; ++ptr)
    {
        if (*ptr > threshold)
            ++count;
    }
    return count;
}

/* TASK 6: Typedef for Function Pointer */
typedef double (*operation_func)(const double, const double);

double double_operation(double a, double b, operation_func op)
{
    return op(a, b) * 2;
}

/* TASK 7: Find Maximum Using Custom Comparator */
double find_max_with_compare(double* arr, int size,
                             bool (*compare)(double, double))
{
    double max_value = *arr;
    for (double* ptr = arr + 1; ptr < arr + size; ++ptr)
    {
        if (compare(*ptr, max_value))
            max_value = *ptr;
    }
    return max_value;
}

/* HELPER FUNCTIONS */

double add(const double l, const double p) { return l + p; }
double subtract(const double l, const double p) { return l - p; }
double multiply(const double l, const double p) { return l * p; }

bool greater_than(double a, double b) { return a > b; }

/* MAIN FUNCTION */
int main()
{
    // TASK 1
    std::cout << "TASK 1: Apply Operation\n";
    std::cout << apply_operation(12.0, 4.0, subtract) << std::endl;

    // TASK 2
    std::cout << "\nTASK 2: All Operations\n";
    auto results = all_operations(6.0, 3.0);
    for (double x : results) std::cout << x << " ";
    std::cout << std::endl;

    // TASK 3
    std::cout << "\nTASK 3: Transform Array\n";
    double arr1[] = {2.0, 4.0, 6.0};
    transform_array(arr1, arr1 + 3,
                    [](double x) { return x * 3; });
    for (double x : arr1) std::cout << x << " ";
    std::cout << std::endl;

    // TASK 4
    std::cout << "\nTASK 4: Custom Calculation\n";
    std::cout << custom_calc(7, 2) << std::endl;

    // TASK 5
    std::cout << "\nTASK 5: Count Above Threshold\n";
    double arr2[] = {1.2, 5.4, 3.3, 0.9};
    std::cout << count_above_threshold(arr2, 4, 2.0) << std::endl;

    // TASK 6
    std::cout << "\nTASK 6: Double Operation\n";
    std::cout << double_operation(3.0, 5.0, multiply) << std::endl;

    // TASK 7
    std::cout << "\nTASK 7: Find Maximum\n";
    double arr3[] = {8.1, 2.4, 9.7, 4.6};
    std::cout << find_max_with_compare(arr3, 4, greater_than) << std::endl;

    return 0;
}
