#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Admission prices
    const double PLATINUMPRICE = 230.00;
    const double GOLDPRICE = 135.00;
    const double TWODAYPRICE = 70.00;
    const double DAYPRICE = 45.00;

    // Meal prices
    const double ALLDAYMEALPRICE = 31.55;
    const double SINGLEMEALPRICE = 14.95;
    const double ENTREEMEALPRICE = 8.25;
    const double NOMEALPRICE = 0.00;

    // Other charges, rates, and discounts
    const double DEFAULTPARKINGCHARGE = 20.00;
    const double FIFTEENPERCENTDISCOUNT = 0.15;
    const double TENPERCENTDISCOUNT = 0.10;
    const double FIVEPERCENTDISCOUNT = 0.05;
    const double TAXRATE = 0.07;

    string admissionType;
    string mealType;
    int admissionNumber;
    int mealNumber = 0; // 0 is default if no meal option is selected

    // Getting user input
    cout << "enter your admission choice(platinum, gold, twoday or day): ";
    cin >> admissionType;
    if (admissionType != "platinum" && admissionType != "gold" && admissionType != "twoday" && admissionType != "day") {
        cout << "Invalid Admission Entry" << endl;
        return 1;
    }

    cout << "how many " << admissionType << ": ";
    cin >> admissionNumber;
    if (admissionNumber <= 0) {
        cout << "Invalid Ticket Entry";
        return 1;
    }

    cout << "enter your meal choice(allday, single, entree or none): ";
    cin >> mealType;
    if (mealType != "allday" && mealType != "single" && mealType != "entree" && mealType != "none") {
        cout << "Invalid Meal Type";
        return 1;
    }

    if (mealType != "none") {       // This will not be visible to the user if no meal plan was selected
        cout << "how many " << mealType << ": ";
        cin >> mealNumber;
        if (mealNumber <= 0) {
            cout << "Invalid Meal Entry";
            return 1;
        }
    }

    // Calculate admission cost
    double admissionCost = 0.0;     // Initial cost is $0 before any calculations
    if (admissionType == "platinum") {
        admissionCost = PLATINUMPRICE * admissionNumber;
    }
    else if (admissionType == "gold") {
        admissionCost = GOLDPRICE * admissionNumber;
    }
    else if (admissionType == "twoday") {
        admissionCost = TWODAYPRICE * admissionNumber;
    }
    else if (admissionType == "day") {
        admissionCost = DAYPRICE * admissionNumber;
    }

    // Calculate meal cost
    double mealCost = 0.0;      // Initial cost is $0 before any calculations
    if (mealType == "allday") {
        mealCost = ALLDAYMEALPRICE * mealNumber;
    }
    else if (mealType == "single") {
        mealCost = SINGLEMEALPRICE * mealNumber;
    }
    else if (mealType == "entree") {
        mealCost = ENTREEMEALPRICE * mealNumber;
    }

    // Calculate parking cost
    double PARKINGCOST;   // Seperate variable for calculating gold and platinum admission parking

    if (admissionType == "platinum" || admissionType == "gold") {
        PARKINGCOST = 0.0; // Platinum and Gold admissions park for free
    }
    else {
        PARKINGCOST = DEFAULTPARKINGCHARGE;
    }

    // Apply discounts
    double discount = 0.0;
    if (admissionCost >= 1000) {
        discount = FIFTEENPERCENTDISCOUNT;
    }
    else if (admissionCost >= 500) {
        discount = TENPERCENTDISCOUNT;
    }
    else if (admissionCost >= 100) {
        discount = FIVEPERCENTDISCOUNT;
    }
    double discountAmount = admissionCost * discount;

    // Calculate subtotal
    double subtotal = admissionCost + mealCost + PARKINGCOST - discountAmount;

    // Calculate tax
    double tax = subtotal * TAXRATE;

    // Calculate total price
    double total = subtotal + tax;

    // Print receipt
    cout << fixed << setprecision(2);   // Outputs 2 digits after the decimal point (cents)
    cout << setfill('-') << setw(35) << "-";
    cout << setfill(' ');
    cout << endl << "Cedar Point:" << endl;
    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' '); 

    cout << left << setw(19) << "Admission" << ":" << left << setw(3) << admissionNumber << left << setw(10) << admissionType << endl;
    cout << left << setw(19) << "Meal" << ":" << left << setw(3) << mealNumber << left << setw(10) << mealType << endl;

    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');

    cout << left << setw(15) << "Admission Cost" << right << setw(5) << "$" << setw(10) << admissionCost << endl;
    cout << left << setw(15) << "Meal Cost" << right << setw(5) << "$" << setw(10) << mealCost << endl;
    cout << left << setw(15) << "Parking" << right << setw(5) << "$" << setw(10) << PARKINGCOST << endl;
    cout << left << setw(15) << "Admission Discount" << right << setw(2) << "$" << setw(10) << discountAmount << endl;
    cout << left << setw(15) << "Subtotal" << right << setw(5) << "$" << setw(10) << subtotal << endl;

    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');

    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');

    cout << left << setw(15) << "Tax" << right << setw(5) << "$" << setw(10) << tax << endl;
    cout << setfill('-') << setw(35) << "-" << endl;
    cout << setfill(' ');
    cout << left << setw(15) << "Final Total" << right << setw(5) << "$" << setw(10) << total << endl;

    return 0;
}
