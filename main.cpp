// Lab 1. Variant 59. Student: Zahar Tiko, group PI-53.
// Lab 1. Variant 59. Approximate roots (sqrtHeron, cubeRoot).
#include <iostream>
#include <cmath>
using namespace std;

// Square root by Heron's method
double sqrtHeron(double x) {
    if (x < 0) return -1.0;
    if (x == 0.0) return 0.0;
    double prev = x;
    double next = (prev + x / prev) / 2.0;
    const double eps = 1e-9;
    while (fabs(next - prev) > eps) {
        prev = next;
        next = (prev + x / prev) / 2.0;
    }
    return next;
}

// Cube root by Newton's method
double cubeRoot(double x) {
    if (x == 0.0) return 0.0;
    double sign = (x < 0) ? -1.0 : 1.0;
    double ax = fabs(x);
    double prev = ax;
    double next = (2.0 * prev + ax / (prev * prev)) / 3.0;
    const double eps = 1e-9;
    while (fabs(next - prev) > eps) {
        prev = next;
        next = (2.0 * prev + ax / (prev * prev)) / 3.0;
    }
    return sign * next;
}

int main() {
    int choice;
    double x;
    do {
	cout << "Welcome to the approximate roots calculator!\n";
        cout << "\n== Variant 59: approximate roots ==\n";
        cout << "1. Square root (Heron's method)\n";
        cout << "2. Cube root\n";
        cout << "0. Exit\n";
        cout << "Choose item: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter x (x >= 0): ";
                cin >> x;
                if (x < 0) {
                    cout << "Error: x must be non-negative.\n";
                } else {
                    cout << "sqrt(" << x << ") = " << sqrtHeron(x) << "\n";
                }
                break;
            case 2:
                cout << "Enter x: ";
                cin >> x;
                cout << "cbrt(" << x << ") = " << cubeRoot(x) << "\n";
                break;
            case 0:
                cout << "Work finished.\n";
                break;
            default:
                cout << "No such item.\n";
        }
    } while (choice != 0);
    return 0;
}
