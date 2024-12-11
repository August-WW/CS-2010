// Simple statistics

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
   int num1;
   int num2;
   int num3;
   int num4;
   
   int averageNumbers;

   cin >> num1;
   cin >> num2;
   cin >> num3;
   cin >> num4;

   cout << num1 * num2 * num3 * num4;
   
   averageNumbers = (num1 + num2 + num3 + num4) / 4;
   
   cout << " " << averageNumbers << endl;
   
   double num1Double = static_cast<double>(num1);
   double num2Double = static_cast<double>(num2);
   double num3Double = static_cast<double>(num3);
   double num4Double = static_cast<double>(num4);

  double productDouble = num1Double * num2Double * num3Double * num4Double;
   double averageDouble = (num1Double + num2Double + num3Double + num4Double) / 4.0;
   
      cout << fixed << setprecision(3);
   cout << productDouble << " " << averageDouble << endl;

   return 0;
}
