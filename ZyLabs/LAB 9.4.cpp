// Number pattern

#include <iostream>

using namespace std;

void PrintNumPattern(int currNum, int rateOfChange, int originalNum, bool NumDecreasing = true) {
   cout << currNum << " ";

   if (!NumDecreasing && currNum == originalNum) {
      return;
   }

   if (NumDecreasing) {
      if (currNum - rateOfChange < 0) {
         PrintNumPattern(currNum - rateOfChange, rateOfChange, originalNum, false);
      } else {
         PrintNumPattern(currNum - rateOfChange, rateOfChange, originalNum, true);
      }
   } else {
      PrintNumPattern(currNum + rateOfChange, rateOfChange, originalNum, false);
   }
}

void PrintNumPattern(int currNum, int rateOfChange) {
   PrintNumPattern(currNum, rateOfChange, currNum, true);
}

int main() {
   int num1;
   int num2;

   cin >> num1;
   cin >> num2;

   PrintNumPattern(num1, num2);

   return 0;
}
