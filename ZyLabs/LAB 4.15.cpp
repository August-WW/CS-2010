// Varied amount of input data

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int userInput;
    int maxNum = 0;
    double sum = 0;
    int count = 0;

    while (true) {
        cin >> userInput;
        if (userInput < 0) {
            break;
        }

        if (userInput > maxNum) {
            maxNum = userInput;
        }

        sum = sum + userInput;
        count++;
    }

    double average = sum / count;

    cout << fixed << setprecision(2);
    cout << maxNum << " " << average << endl;

    return 0;
}
