#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_STATES = 50;  // Maximum capacity

int main() {
    // Arrays for storing state data
    string stateName[MAX_STATES];
    int statePopulation[MAX_STATES];
    double stateBudget[MAX_STATES];
    double stateRevenue[MAX_STATES];

    // Open input and output files
    ifstream infile("pgm5.txt");
    ofstream outfile("report5.txt");

    // Calculation variables. Everything starts at 0 before any data is read
    double totalBudget = 0;
    int numStates = 0;
    int lowestPopulationIndex = 0;
    int highestBudgetIndex = 0;
    int highestSurplusIndex = 0;

    // Reading data
    while (!infile.eof() && numStates < MAX_STATES) {
        getline(infile, stateName[numStates]);  // Read state name
        if (stateName[numStates].empty()) {
            break; // If no more data
            }
        
        infile >> statePopulation[numStates];  // Read population
        infile >> stateBudget[numStates];     // Read budget
        infile >> stateRevenue[numStates];   // Read revenue
        infile.ignore();  // Required in order to move to the next state

        // Calculating the total state budget
        totalBudget += stateBudget[numStates];

        // Find state with the lowest population
        if (statePopulation[numStates] < statePopulation[lowestPopulationIndex]) {
            lowestPopulationIndex = numStates;
        }
        // Find state with the highest budget
        if (stateBudget[numStates] > stateBudget[highestBudgetIndex]) {
            highestBudgetIndex = numStates;
        }
        // Find state with the highest surplus
        if ((stateRevenue[numStates] - stateBudget[numStates]) > (stateRevenue[highestSurplusIndex] - stateBudget[highestSurplusIndex])) {
            highestSurplusIndex = numStates;
        }

        numStates++;  // Read the next state
    }

    // Calculate the average state budget
    double averageBudget = totalBudget / numStates;

    // Writing results to output file
    outfile << fixed << setprecision(2);

    outfile << left << setw(5) << "#" << setw(15) << "Name" << right << setw(16) << "Population" << setw(10) << "Budget" << setw(10) << "Revenue" << endl;
    outfile << "-    ----                 ----------    ------   -------" << endl;

    // Output the number, state name, state population, state budget, and state revenue
    for (int i = 0; i < numStates; i++) {
        outfile << left << setw(5) << (i + 1) << setw(15) << stateName[i] << right << setw(16) << statePopulation[i] << setw(10) << stateBudget[i] << setw(10) << stateRevenue[i] << endl;
    }

    outfile << "\n\nThe average state budget is $" << averageBudget << " billion.\n";
    outfile << stateName[highestBudgetIndex] << " has the highest budget: " << "$" << stateBudget[highestBudgetIndex] << " billion.\n";
    outfile << stateName[highestSurplusIndex] << " has with the highest surplus: " << "$" << (stateRevenue[highestSurplusIndex] - stateBudget[highestSurplusIndex]) << " billion.\n";
    outfile << stateName[lowestPopulationIndex] << " has with the lowest population: " << statePopulation[lowestPopulationIndex] << " people.\n";

    // Close files
    infile.close();
    outfile.close();

    return 0;
}
