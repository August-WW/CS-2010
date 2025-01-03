// Brute force equation solver

#include <iostream>
using namespace std;

int main() {
    int a1;
    int b1; 
    int c1;
    
    int a2;
    int b2;
    int c2;

    cin >> a1; 
    cin >> b1;
    cin >> c1;
    cin >> a2;
    cin >> b2;
    cin >> c2;

    bool foundSolution = false;

    for (int x = -10; x <= 10; ++x) {
        for (int y = -10; y <= 10; ++y) {

            if (a1 * x + b1 * y == c1 && a2 * x + b2 * y == c2) {
                cout << "x = " << x << ", y = " << y << endl;
                foundSolution = true; 
                break;
            }
        }
        if (foundSolution) {
            break;
        }
    }
    if (!foundSolution) {
        cout << "There is no solution" << endl;
    }

    return 0;
}
