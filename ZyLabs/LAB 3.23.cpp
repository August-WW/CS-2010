// Login name

#include <iostream>
#include <string>
using namespace std;

int main() {
	string login;
	string first;
	string last;
	int number;

   cin >> first;
   cin >> last;
   cin >> number;
	
	string first_part = first.substr(0, 6);
	
	char last_initial = last[0];
	
	int last_digit = number % 10;
	
	login = first_part + last_initial + "_" + to_string(last_digit);
	
	cout << "Your login name: " << login << endl;
	
	return 0;
}