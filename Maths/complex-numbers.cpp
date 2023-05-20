#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0); // not understood !

int main() {
    complex<double> num1(2, 3); // 2 + 3i
    std::cout << num1.real() << "+" << num1.imag() << "i\n"; // 2 + 3i

    complex<double> num2(1, 1);
    cout << "Modulus = " << abs(num2) << '\n'; // r = 1.41421
    cout << "Argument = " << arg(num2) << '\n'; // theta radian
    cout << "Angle = " << arg(num2) * 180 / PI << '\n'; // theta degree
    cout << "Norm = " << norm(num2) << '\n'; // 2 (1*1 + 1*1) // not understood!

    // we can use 'polar' with r and theta
    double r = abs(num2), theta = arg(num2);
    complex<double> num3 = polar(r, theta);
    cout << "From polar = " << num3 << '\n';

    // parameters are 0 by default
    complex<double> xPart = 11; // (11, 0)

    // operations are very similar EXCEPT multiplication
    complex<double> a(1, 2), b(3, 4);
    cout << a + b << '\n'; // (4, 6)
    cout << a - b << '\n'; // (-2, -2)
    cout << b * 2.0 << '\n'; // (6, 8)
    cout << a / 2.0 << '\n'; // (0.5, 1)

    // conjugate: negate the imag part
    cout << conj(a) << endl; // (1, -2)

    return 0;
}