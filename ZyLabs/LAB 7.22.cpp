// Count characters - functions

#include <iostream>
using namespace std;

int CalcNumCharacters(string userString, char userChar) {
    int count = 0;
    for (char ch : userString) {
        if (ch == userChar) {
            count++;
        }
    }
    return count;
}

int main() {
   char inputChar;
   string inputString;

   cin >> inputChar;
   cin.ignore(); 
   getline(cin, inputString); 

   int count = CalcNumCharacters(inputString, inputChar);

   if (count == 1) {
        cout << count << " " << inputChar << endl;
    } 
   else {
        cout << count << " " << inputChar << "'s" << endl;
    }

   return 0;
}
