#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

int main()
{
   string name;
    int age;
    cout << "enter ur name: ";
    cin >> name;
    cout << "enter ur age: ";
    cin >> age;
    cout << "Hello, " << name << "You are " << age << " years old." << endl;

    double l, k;
    cout << "enter two numbers (l and k): ";
    cin >> l >> k;
    cout << fixed << setprecision(3);
    cout << "sum = " << l + k << endl;
    cout << "difference = " << l - k << endl;
    cout << "product = " << l * k << endl;
    if (k != 0) cout << "division = " << l / k << endl;

    double a, b;
    cout << "enter coefficients a and b: ";
    cin >> a >> b;
    if (a == 0)
    {
        if (a == 0) cout << "equation always true." << endl;
        else cout << "no solution." << endl;
    }
    else
    {
        double x = -a / b;
        cout << "solution: x = " << x << endl;
    }


    bool lighton;
    cout << "Type 1 for 'light on' or 0 for 'light off': ";
    cin >> lighton;
    if (lighton) cout << "The room is bright!" << endl;
    else cout << "It's dark in here." << endl;

    return 0;
}
