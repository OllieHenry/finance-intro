#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double S0, U, D, R;

    // entering data
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter U:  "; cin >> U;
    cout << "Enter D:  "; cin >> D;
    cout << "Enter R:  "; cin >> R;

    // verify S0 > 0, -1 < D < U, and R > -1
    if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0)
    {
        cout << "verify S0 > 0, -1 < D < U, and R > -1" << endl;
        return 1;
    }

    // check for arbitrage
    if (U <= R || R <= D)
    {
        cout << "U <= R || R <= D. Check for arbitrage." << endl;
        return 1;
    }

    // compute RNP
    cout << "q = " << (R-D)/(U-D) << endl;

    // compute stock price at node (n,i)
    int n, i;
    cout << "Enter n:  "; cin >> n;
    cout << "Enter i:  "; cin >> i;
    cout << "S(n,i) = " << S0 * pow(1+U, i) * pow(1+D, n-i) << endl;

    return 0;
}
