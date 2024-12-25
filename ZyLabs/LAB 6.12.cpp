// Output numbers in reverse

#include <iostream>
using namespace std;

int main() {
   int numInts;
   cin >> numInts;
   int userInts[numInts];   // An array to hold the user's input integers

   for (int i = 0; i < numInts; i++) {
      cin >> userInts[i];
   }
   
   for (int i = numInts - 1; i >= 0; i--) {
      cout << userInts[i] << " ";
   }
   
   cout << endl;

   return 0;
}
