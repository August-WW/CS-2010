#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Prices of ice cream
const double ROCKYPRICE = 2.50;
const double STORMYPRICE = 3.25;
const double BLIZZARDPRICE = 3.75;
const double SUPERCELLPRICE = 4.25;

int IceCreamChoice;
double IceCreamPrice = 0.0; // $0 before an ice cream is chosen
string IceCream;
string coneType;

// Payment
double paymentAmount = 0.0;
double paymentAdditional;

int main() {
    while (true) {
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');
        // Ice cream menu
        cout << fixed << setprecision(2);
        cout << left << setw(11) << "1. Rocky" << right << setw(5) << "$" << ROCKYPRICE << endl;
        cout << left << setw(11) << "2. Stormy" << right << setw(5) << "$" << STORMYPRICE << endl;
        cout << left << setw(11) << "3. Blizzard" << right << setw(5) << "$" << BLIZZARDPRICE << endl;
        cout << left << setw(11) << "4. Supercell" << right << setw(4) << "$" << SUPERCELLPRICE << endl;
        cout << "5. Quit" << endl;

        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');

        cout << "Enter your choice of ice cream: ";
        cin >> IceCreamChoice;
        // Exit the program
        if (IceCreamChoice == 5) {
            cout << "Goodbye!" << endl;
            system("pause"); // Prompts "Press any key to continue..." before doing anything else
            break;
        }
        // If the user enters an option that is not 1, 2, 3, 4, or 5
        if (IceCreamChoice < 1 || IceCreamChoice > 5) {
            cout << "Invalid choice, please re-enter: " << endl;
            continue;
        }
        // Ice cream choices for when the user enters 1, 2, 3, or 4. The price of the ice cream selected will be the value of IceCreamPrice
        switch (IceCreamChoice) {
            case 1:
                IceCream = "Rocky";
                IceCreamPrice = ROCKYPRICE;
                break;
            case 2:
                IceCream = "Stormy";
                IceCreamPrice = STORMYPRICE;
                break;
            case 3:
                IceCream = "Blizzard";
                IceCreamPrice = BLIZZARDPRICE;
                break;
            case 4:
                IceCream = "Supercell";
                IceCreamPrice = SUPERCELLPRICE;
                break;
        }

        // Customer chooses type of cone for their ice cream
        while (true) {
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');

        cout << "Waffle" << endl;
        cout << "Sugar" << endl;
        
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');

        cout << "Enter your choice of cones: ";
        cin >> coneType;

        if (coneType != "Waffle" && coneType != "Sugar") {
            cout << "Invalid choice, please re-enter: " << endl;
            continue;
        }
        else {
            break;
        }
    }
        // Outputs the customer's choice of ice cream, type of cone, and the price
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');
        cout << "You have ordered a " << endl << coneType << " Cone " << IceCream << " ice cream." << endl;
        cout << "That will be $" << IceCreamPrice << endl;
        
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');

        // Customer enters payment
        cout << "Enter the amount to pay: ";
        cin >> paymentAmount;

        // If the customer's payment is insufficient
        while (paymentAmount < IceCreamPrice) {
            cout << "You still owe: $" << (IceCreamPrice - paymentAmount) << endl;
            cout << "Enter additional payment: ";
            cin >> paymentAdditional;
            paymentAmount += paymentAdditional;
        }

        double change = paymentAmount - IceCreamPrice; // Change if the customer goes over the required payment

        // Final receipt
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');
        cout << "Here is your:" << endl;
        cout << coneType << " Cone " << IceCream << " ice cream!" << endl;
        cout << left << setw(11) << "Cost: " << right << setw(5) << "$" << IceCreamPrice << endl;
        cout << left << setw(11) << "Paid: " << right << setw(5) << "$" << paymentAmount << endl;
        
        // A new line on the receipt will print if the user has change. Otherwise, this line will not display in the program.
        if (change > 0) {
            cout << left << setw(11) << "Change Back: " << right << setw(3) << "$" << change << endl;
        }
        
        cout << setfill('-') << setw(37) << "-" << endl;
        cout << setfill(' ');

        system("pause"); // Pausing before the ice cream menu outputs again
    }

    return 0;
}
