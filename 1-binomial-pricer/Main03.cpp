#include <iostream>
#include <cmath>
using namespace std;

// compute RNP
double RiskNeutProb(double U, double D, double R)
{
    return (R-D)/(U-D);
}

// compute stick price at node (n,i)
double S(double S0, double U, double D, int n, int i)
{
    return S0 * pow(1+U, i) * pow(1+D, n-i);
}

// input, display and check model data
int GetInputData(double& S0, double& U, double& D, double& R)
{
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

    return 0;

}

int main() {
    double S0, U, D, R;

    if (GetInputData(S0, U, D, R) == 1) {
        return 1;
    }

    cout << "q = " << RiskNeutProb(U, D, R) << endl;

    int n, i;
    cout << "Enter n: "; cin >> n;
    cout << "Enter i: "; cin >> i;
    cout << "S(n,i) = " << S(S0, U, D, n, i) << endl;

    return 0;
}
