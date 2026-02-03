#include <iostream>
#include <cmath>
#include <random>
#include <chrono>
#include <numbers>

using namespace std;

/* ----------------------------------------------------------
   TASK 1: Function — Sum of 3 Nbrs
   ---------------------------------------------------------- */
double sum3(double a, double b, double c) {
    return a + b + c;
}

/* ----------------------------------------------------------
   TASK 2: Stars with a Twist_print_stars_advanced
   ---------------------------------------------------------- */
void print_stars_advanced(int s, char symbol) {
    cout << "[";
    for (int i = 0; i < s; i++) {
        cout << symbol;
    }
    cout << "]" << endl;
}

/* ----------------------------------------------------------
   TASK 3: Recursion Practice — Factorial
   ---------------------------------------------------------- */
int factorial(int n) {
    if (n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

/* ----------------------------------------------------------
   TASK 4: Monte Carlo π Approximation
   ---------------------------------------------------------- */
double estimate_pi(int shots) {
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    uniform_real_distribution<double> distribution(-1.0, 1.0);

    int inside = 0;
    for (int i = 0; i < shots; i++) {
        double x = distribution(generator);
        double y = distribution(generator);
        if (x * x + y * y < 1.0)
            inside++;
    }

    return 4.0 * inside / shots;
}

/* ----------------------------------------------------------
   TASK 5: Inline Function — Minimum of Two Numbers
   ---------------------------------------------------------- */
inline double minimum(double a, double b) {
    return (a < b) ? a : b;
}

/* ----------------------------------------------------------
   MAIN FUNCTION
   ---------------------------------------------------------- */
int main() {
    cout << "== Function Practice Tasks ==" << endl;

    // TASK 1 test
    cout << "\n-- TASK 1: sum3() --" << endl;
    cout << "Sum of three (1.2, 2.3, 3.4): " << sum3(1.2, 2.3, 3.4) << endl;
    cout << "Sum of three (5.0, 4.1, 3.0): " << sum3(5.0, 4.1, 3.0) << endl;

    // TASK 2 test
    cout << "\n-- TASK 2: print_stars_advanced() --" << endl;
    print_stars_advanced(5, '*');
    print_stars_advanced(10, '$');

    // TASK 3 test
    cout << "\n-- TASK 3: factorial() --" << endl;
    cout << "Factorial of 5 = " << factorial(5) << endl;

    // TASK 4 test
    cout << "\n-- TASK 4: estimate_pi() --" << endl;
    cout << "Estimated π (10000 shots): " << estimate_pi(10000) << endl;

    // TASK 5 test
    cout << "\n-- TASK 5: minimum() --" << endl;
    cout << "Minimum of 10 and 3.14: " << minimum(10, 3.14) << endl;
    cout << "Minimum of 5.3 and 2.1: " << minimum(5.3, 2.1) << endl;
    cout << "Minimum of 1.2 and 2.1: " << minimum(1.2, 2.1) << endl;

    return 0;
}
