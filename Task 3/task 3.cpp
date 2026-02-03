#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cout << "TASK 1:\n";
    cout << "Dice Simulation with switch statement\n";

    int number;
    cout << "Enter a number between 1 and 6: ";
    cin >> number;

    switch (number)
    {
        case 1: cout << "*"; break;
        case 2: cout << "**"; break;
        case 3: cout << "***"; break;
        case 4: cout << "****"; break;
        case 5: cout << "*****"; break;
        case 6: cout << "******"; break;
        default: cout << "invalid input"; break;
    }
    cout << "\n\n";





    cout << "TASK 2:\n";
    cout << "Array Initialization and Printing\n";

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = i * 2;
    }

    cout << "Array elements: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n\n";





    cout << "TASK 3:\n";
    cout << "Average of 5 Numbers\n";

    double nums[5];
    double sum = 0;

    cout << "Enter 5 numbers: ";
    for (int i = 0; i < 5; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    double average = sum / 5.0;
    cout << "Average = " << average << "\n\n";




    cout << "TASK 4:\n";
    cout << "Reverse an array\n";

    int arr2[6] = {1, 2, 3, 4, 5, 6};

    cout << "Before: ";
    for (int i = 0; i < 6; i++) {
        cout << arr2[i] << " ";
    }

    int start = 0, end = 5;
    while (start < end) {
        int temp = arr2[start];
        arr2[start] = arr2[end];
        arr2[end] = temp;
        start++;
        end--;
    }

    cout << "\nAfter:  ";
    for (int i = 0; i < 6; i++) {
        cout << arr2[i] << " ";
    }
    cout << "\n\n";



    cout << "TASK 5:\n";
    cout << "2D Array _ Spiral Filling (4x4)\n";

    const int n = 4;
    int spiral[n][n];
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int value = 0;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
            spiral[top][i] = value++;
        top++;


        for (int i = top; i <= bottom; i++)
            spiral[i][right] = value++;
        right--;


        for (int i = right; i >= left; i--)
            spiral[bottom][i] = value++;
        bottom--;

    
        for (int i = bottom; i >= top; i--)
            spiral[i][left] = value++;
        left++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << spiral[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nAll tasks are done!!\n";
    return 0;
}
