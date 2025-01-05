#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    string movieTitle;    
    int adultTicketsSold;
    int childTicketsSold;
    double adultTicketPrice;
    double childTicketPrice;
    double PERCENT_PROFIT = 0.8;
    double PERCENT_DISTRIBUTOR_FEE;
    double grossSales;
    double netProfit;
    double distributorPayment;

    // User input for movie name and ticket sales
    cout << "Enter the movie title: ";
    cin >> movieTitle;
    cout << "How many adult tickets were sold: ";
    cin >> adultTicketsSold;
    cout << "How many children's tickets were sold: ";
    cin >> childTicketsSold;

    // User input for ticket prices
    cout << "Enter the price of an adult ticket: $";
    cin >> adultTicketPrice;
    cout << "Enter the price of a child ticket: $";
    cin >> childTicketPrice;

    // Calculating gross ticket sales (amount before distributor deduction)
    grossSales = (adultTicketsSold * adultTicketPrice) + (childTicketsSold * childTicketPrice);

    // Calculating the theater's profit from ticket sales
    netProfit = grossSales * PERCENT_PROFIT;

    // Calculate percentage to determine how much is owed to the movie distributor
    PERCENT_DISTRIBUTOR_FEE = 1.00 - PERCENT_PROFIT;

    // Amount owed to distributor
    distributorPayment = grossSales * PERCENT_DISTRIBUTOR_FEE;

    // Output the results
    cout << fixed << setprecision(2); // Outputs result as $xx.xx
    cout << "Gross Ticket Sales for '" << movieTitle << "': $" << grossSales << endl;
    cout << "Theater Net Profit: $" << netProfit << endl;
    cout << "Amount Paid to Distributor: $" << distributorPayment << endl;

    return 0;
}
