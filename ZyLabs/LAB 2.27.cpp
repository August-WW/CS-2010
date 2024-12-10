// Phone number breakdown

#include <iostream>
using namespace std;

int main() {
   long long phoneNumber;

   cin >> phoneNumber;
   
   int areaCode = phoneNumber / 10000000;
   int middle = (phoneNumber / 10000) % 1000;
   int lastfour = phoneNumber % 10000;

   cout << "(" << areaCode << ") " << middle << "-" << lastfour << endl;
   
   return 0;
}
