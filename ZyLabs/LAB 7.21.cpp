// Swapping variables

#include <iostream>
using namespace std;

void SwapValues(int& userVal1, int& userVal2, int& userVal3, int& userVal4) {
   // First and second value swap
   int temp = userVal1;
   userVal1 = userVal2;
   userVal2 = temp;
   
   // Third and forth value swap
   temp = userVal3;
   userVal3 = userVal4;
   userVal4 = temp;
}

int main() {
   int val1;
   int val2;
   int val3;
   int val4;
   
   cin >> val1;
   cin >> val2;
   cin >> val3;
   cin >> val4;
   
   SwapValues(val1, val2, val3, val4);
   
   cout << val1 << " " << val2 << " " << val3 << " " << val4 << endl;

   return 0;
}