// Exact change

#include <iostream>
using namespace std;

int main() {

   int change;
   cin >> change;
   
   if (change <= 0) {
      cout << "No change" << endl;
   }
   else {
      int dollars = change / 100;
      change = change % 100;
      
      int quarters = change / 25;
      change = change % 25;
      
      int dimes = change / 10;
      change = change % 10;

      int nickels = change / 5;
      change = change % 5;
      
      int pennies = change;
      
      if (dollars > 0) {
         if (dollars == 1) {
            cout << dollars << " Dollar" << endl;
         } 
         else {
            cout << dollars << " Dollars" << endl;
         }
      }
      
      if (quarters > 0) {
            if (quarters == 1) {
                cout << quarters << " Quarter" << endl;
            } 
            else {
                cout << quarters << " Quarters" << endl;
            }
        }

        if (dimes > 0) {
            if (dimes == 1) {
                cout << dimes << " Dime" << endl;
            } 
            else {
                cout << dimes << " Dimes" << endl;
            }
        }

        if (nickels > 0) {
            if (nickels == 1) {
                cout << nickels << " Nickel" << endl;
            } 
            else {
                cout << nickels << " Nickels" << endl;
            }
        }

        if (pennies > 0) {
            if (pennies == 1) {
                cout << pennies << " Penny" << endl;
            } 
            else {
                cout << pennies << " Pennies" << endl;
            }
        }
    }


   return 0;
}