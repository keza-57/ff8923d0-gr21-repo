#include <iostream>

// ============================================================================
// TASK 1
// ============================================================================
void swap_values(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ============================================================================
// TASK 2
// ============================================================================
int find_max(int* array, int size)
{
    int max = *array;

    for (int i = 1; i < size; i++)
    {
        if (*(array + i) > max)
            max = *(array + i);
    }
    return max;
}

// ============================================================================
// TASK 3
// ============================================================================
void redirect_pointer(int** ptr, int* new_target)
{
    *ptr = new_target;
}

// ============================================================================
// TASK 4
// ============================================================================
void print_value(const int* ptr)
{
    std::cout << "Value: " << *ptr << "\n";
}

void increment_value(int* const ptr)
{
    (*ptr)++;
}

void display_value(const int* const ptr)
{
    std::cout << "Displayed value: " << *ptr << "\n";
}

// ============================================================================
// TASK 5
// ============================================================================
void reverse_array(int* array, int size)
{
    int* start = array;
    int* end = array + size - 1;

    while (start < end)
    {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

// ============================================================================
// TASK 6
// ============================================================================
int sum_range(int* begin, int* end)
{
    int sum = 0;

    while (begin < end)
    {
        sum += *begin;
        begin++;
    }
    return sum;
}

// ============================================================================
// TASK 7
// ============================================================================
struct Point
{
    double x, y;
};

void move_point(Point* p, double dx, double dy)
{
    p->x += dx;
    p->y += dy;
}

void print_point(const Point* p)
{
    std::cout << "(" << p->x << ", " << p->y << ")\n";
}

// ============================================================================
// TASK 8
// ============================================================================
void analyze_array(int* array, int size, int* min, int* max,
                   int* sum, double* avg)
{
    *min = *max = array[0];
    *sum = 0;

    for (int i = 0; i < size; i++)
    {
        if (array[i] < *min) *min = array[i];
        if (array[i] > *max) *max = array[i];
        *sum += array[i];
    }

    *avg = static_cast<double>(*sum) / size;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main()
{
    std::cout << "POINTER TASKS - PRACTICE SESSION\n";
    std::cout << "=================================\n\n";

    // TASK 1:swap_values
    {
        std::cout << "TASK 1: Swap Values\n";
        std::cout << "-------------------\n";
        int a = 5, b = 10;
        std::cout << "Before: a=" << a << " b=" << b << "\n";
        swap_values(&a, &b);
        std::cout << "After:  a=" << a << " b=" << b << "\n\n";
        std::cout << "Expected: a = 10, b = 5\n\n";
    }

    // TASK 2:find_max
    {
        std::cout << "TASK 2: Find Maximum\n";
        std::cout << "--------------------\n";
        int arr[] = {3, 7, 2, 9, 1, 5};
         int size = 6;
        int max = find_max(arr, size);
        std::cout << "Array: {3, 7, 2, 9, 1, 5}\n";
        std::cout << "Maximum: " << max << "\n";
        std::cout << "Expected: 9\n\n";
    }

    // TASK 3: redirect_pointer
    {
        std::cout << "TASK 3: Redirect Pointer\n";
        std::cout << "------------------------\n";
        int a = 10, b = 20;
        int* p = &a;
        std::cout << "Before: *p = " << *p << " (pointing to a)\n";
        redirect_pointer(&p, &b);
        std::cout << "After:  *p = " << *p << " (pointing to b)\n";
        std::cout << "Expected: *p = 20\n\n";
        
    }

    // TASK 4:const pointers
    {
        std::cout << "TASK 4: Const Pointers\n";
        std::cout << "----------------------\n";
        int value = 42;
        std::cout << "Original value: " << value << "\n";
        print_value(&value);
        increment_value(&value);
        std::cout << "After increment: " << value << "\n";
        display_value(&value);
        std::cout << "\n";
    }

    // TASK 5 : reverse_array
    {
         std::cout << "TASK 5: Reverse Array\n";
        std::cout << "---------------------\n";
        int arr[] = {1, 2, 3, 4, 5};
        int size = 5;
        std::cout << "Before: ";
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        
        reverse_array(arr, size);
        
        std::cout << "After:  ";
        for (int i = 0; i < size; ++i)
            std::cout << arr[i] << " ";
        std::cout << "\n";
        std::cout << "Expected: 5 4 3 2 1\n\n";
        
    }

    // TASK 6 :  sum_range
    {
        std::cout << "TASK 6: Sum Range\n";
        std::cout << "-----------------\n";
        int arr[] = {10, 20, 30, 40, 50};
        int sum = sum_range(arr,arr+5);
        std::cout << "Array: {10, 20, 30, 40, 50}\n";
        std::cout << "Sum: " << sum << "\n";
        std::cout << "Expected: 150\n\n";
    }

    // TASK 7: Point structure
    {
        std::cout << "TASK 7: Point Structure\n";
        std::cout << "-----------------------\n";
        Point p = {3.0, 4.0};
        std::cout << "Initial point: ";
        print_point(&p);
        move_point(&p, 2.5, -1.5);
        std::cout << "After moving by (2.5, -1.5): ";
        print_point(&p);
        std::cout << "Expected: (5.5, 2.5)\n\n";
    }

    // TASK 8: analyze_array
    {
        std::cout << "TASK 8: Analyze Array\n";
        std::cout << "---------------------\n";
        int arr[] = {5, 2, 8, 1, 9, 3};
        int size = 6;
        int min, max, sum;
        double avg;
        analyze_array(arr, 6, &min, &max, &sum, &avg);
        std::cout << "Array: {5, 2, 8, 1, 9, 3}\n";
        std::cout << "Minimum: " << min << "\n";
        std::cout << "Maximum: " << max << "\n";
        std::cout << "Sum: " << sum << "\n";
        std::cout << "Average: " << avg << "\n";
        std::cout << "Expected: min=1, max=9, sum=28, avg=4.666...\n\n";
    }
    std::cout << "=================================\n";
    std::cout << "All tasks completed!\n";

    return 0;
}
