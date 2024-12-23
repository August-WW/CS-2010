// Password modifier

#include <iostream>
#include <string>
using namespace std;

int main() {
   
   string password;
   cin >> password;
   
       for (char &c : password) {
        switch (c) {
            case 'i':
                c = '1';
                break;
            case 'a':
                c = '@';
                break;
            case 'm':
                c = 'M';
                break;
            case 'B':
                c = '8';
                break;
            case 's':
                c = '$';
                break;
        }
    }
    
    password += '!';
    
    cout << password << endl;

   return 0;
}