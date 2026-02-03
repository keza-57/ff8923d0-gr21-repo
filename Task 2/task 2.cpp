#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << "TASK 1:\n";

    double val = 0.1;
    cout << "Default precision: " << val << endl;
    cout << "High precision (30): " << setprecision(30) << val << endl;

    int a = 7, b = 3;
    cout << "\nInteger division (7 / 3): " << a / b << endl;
    cout << "Floating-point division (7.0 / 3.0): " << 7.0 / 3.0 << endl;

    cout << "\nCasting int(a) to double before division:" << endl;
    cout << "double(a) / b = " << static_cast<double>(a) / b << endl;

    cout << "\nExplanation:" << endl;
    cout << "- Integer division (7 / 3) only keeps the whole number part. Imagine dividing 7 apples among 3 friends: each friend gets 2 apples, remainder ignored.\n";
    cout << "- Floating-point division (7.0 / 3.0) keeps the decimal. Same 7 apples among 3 friends: each gets 2.333 apples. Decimals are preserved.\n\n";

    cout << "TASK 2:\n";

    int num;
    cout << "Enter an integer: ";
    cin >> num;
    if (num % 2 == 0)
        cout << num << " is even.\n";
    else
        cout << num << " is odd.\n";

    int absValue = (num < 0) ? -num : num;
    cout << "Absolute value : " << absValue << "\n\n";
    cout << "TASK 3:\n";

    cout << "While loop (5 to 1): ";
    int i = 5;
    while (i >= 1)
    {
        cout << i-- << " ";
    }
    cout << endl;

    cout << "Do-while loop (1 to 5): ";
    i = 1;
    do
    {
        cout << i++ << " ";
    } while (i <= 5);
    cout << endl;

    cout << "For loop (even numbers 0 to 10): ";
    for (int j = 0; j <= 10; ++j)
    {
        if (j % 2 == 0)
            cout << j << " ";
    }
    cout << endl;

    cout << "\n Difference between Pre increment and  Post increment :\n";
    int x = 5;
    cout << "Initial x = " << x << endl;
    cout << "Post-increment x++ gives: " << x << endl;
x++;
cout << "(then x = " << x << ")\n";
++x;
cout << "Pre-increment ++x gives: " << x << " (x becomes " << x << " immediately)\n\n";

   cout << "TASK 4:\n";

int sum = 0;
for (int k = 1; k <= 100; ++k)
{
    sum += k;
}
cout << "1.Sum of numbers from 1 to 100: " << sum << endl;

cout << "\n2.Enter numbers (0 to stop):\n";
int input;
while (true)
{
    cout << "> ";
    if (!(cin >> input)) 
    {
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();              
        cin.ignore(10000, '\n');  
        continue;                  
    }

    if (input == 0)
        break;

    cout << ((input > 0) ? "Positive\n" : "Negative\n");
}

cout << "\nFirst 10 squares: ";
for (int n = 1; n <= 10; ++n)
{
    cout << n * n << " ";
}
cout << endl;

cout << "\nRectangle (4 rows, 6 columns):\n";
for (int row = 0; row < 4; ++row)
{
    for (int col = 0; col < 6; ++col)
    {
        if(col>=0) 
        cout << "* ";
        else cout<<" ";
    }
    cout << endl;

}
cout << "\nAll tasks are done!!\n";
return 0;
}