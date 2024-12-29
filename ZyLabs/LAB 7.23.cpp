// Convert to binary - functions

#include <iostream>
using namespace std;

string IntToReverseBinary(int integerValue) {
   string binaryStr;
   
   while (integerValue > 0) {
      binaryStr += to_string(integerValue % 2);
      integerValue = integerValue / 2;
   }
   
   return binaryStr;
}

string StringReverse(string userString) {
   string reversedStr;
   
   for (int i = userString.length() - 1; i >= 0; --i) {
      reversedStr += userString[i];
   }
   
   return reversedStr;
}

int main() {
   int inputValue;
   
   cin >> inputValue;
   
   string reversedBinary = IntToReverseBinary(inputValue);
   string correctBinary = StringReverse(reversedBinary);
   
   cout << correctBinary << endl;
      

   return 0;
}
