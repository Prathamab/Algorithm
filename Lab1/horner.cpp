#include <iostream>
using namespace std;

int main() {
    int n, x, result = 0;
    cout << "Enter degree of polynomial: ";
    cin >> n;

    int coeff[n+1];
    cout << "Enter coefficients (highest degree first): ";
    for (int i = 0; i <= n; i++)
        cin >> coeff[i];

    cout << "Enter value of x: ";
    cin >> x;

    result = coeff[0];
    for (int i = 1; i <= n; i++)
        result = result * x + coeff[i];

    cout << "Polynomial value = " << result;
    return 0;
}
