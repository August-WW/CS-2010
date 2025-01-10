#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int MAX_STATE = 18;
const string DATA_FILE = "pgm6.txt";
const string STATE_LOOKUP_FILE = "statelookup.txt";
const string OUT_FILE = "out.txt";

// File stream
ifstream pgm6;
ofstream out;

// Function definitions
int readHurricaneData(string stateAbbr[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num, string fName);
int readStateLookUpTable(string stateAbbr[], string stateNames[], int num, string fName);
int mostHitState(int numHur[], int num);
void statesHitByCat5Hur(string stateNames[], int cat5Hur[], int num);
void printHurricaneData(string stateNames[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num);
void printHurricaneData(string stateNames[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num, string fName);

int main() {
    // Parallel arrays
    string stateAbbr[MAX_STATE];
    string stateNames[MAX_STATE];
    int numHur[MAX_STATE];
    int cat3Hur[MAX_STATE], cat4Hur[MAX_STATE], cat5Hur[MAX_STATE];
    int cntCat3AndAbove[MAX_STATE];

    // Reading data from files and error handling
    int numState = readHurricaneData(stateAbbr, numHur, cat3Hur, cat4Hur, cat5Hur, MAX_STATE, DATA_FILE);
    if (numState == -1) {
        cout << "Error! Could not the hurricane data." << endl;
        return 1;
    }

    int lookupResult = readStateLookUpTable(stateAbbr, stateNames, numState, STATE_LOOKUP_FILE);
    if (lookupResult == -1) {
        cout << "Error! Could not read statelookup.txt" << endl;
        return 1;
    }

    // Output hurricane data to console
    printHurricaneData(stateNames, numHur, cat3Hur, cat4Hur, cat5Hur, numState);

    // State with the most hits
    int mostHitsIndex = mostHitState(numHur, numState);
    cout << "The state with the most hurricane hits is " << stateNames[mostHitsIndex] << " with " << numHur[mostHitsIndex] << " hits." << endl;

    // States with Category 5 hits
    statesHitByCat5Hur(stateNames, cat5Hur, numState);

    // Write hurricane data to file
    printHurricaneData(stateNames, numHur, cat3Hur, cat4Hur, cat5Hur, numState, OUT_FILE);

    return 0;
}

// Functions
int readHurricaneData(string stateAbbr[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num, string fName) {
    ifstream inFile(fName);
    if (!inFile) {
        return -1;
    }
    
    int i = 0;
    while (inFile >> stateAbbr[i] >> numHur[i] >> cat3Hur[i] >> cat4Hur[i] >> cat5Hur[i]) {
        if (++i >= num) {
            break;
        }
    }
    inFile.close();
    return i;
}

int readStateLookUpTable(string stateAbbr[], string stateNames[], int num, string fName) {
    ifstream inFile(fName);
    if (!inFile) {
        return -1;
    }
    
    string abbr, name, additional;
    int i = 0;
    while (inFile >> abbr) {
        if (abbr[0] == 'N' || abbr[0] == 'R' || abbr[0] == 'S') { // Handling states with names that have two words
            inFile >> name >> additional;
            name += " " + additional;
        } 
        else {
            inFile >> name;
        }
        for (int j = 0; j < num; ++j) {
            if (stateAbbr[j] == abbr) {
                stateNames[j] = name;
                break;
            }
        }
        i++;
    }
    inFile.close();
    return i;
}

int mostHitState(int numHur[], int num) {
    int maxIndex = 0;
    for (int i = 1; i < num; i++) {
        if (numHur[i] > numHur[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void statesHitByCat5Hur(string stateNames[], int cat5Hur[], int num) {
    int cntState = 0;
    int indexOfStateHitByCat5Hur[MAX_STATE];
    int mostCat5Index = -1, mostCat5Hits = 0;

    cout << "Among the 18 states, " << "\033[1m3\033[0m" << " states were hit by Category 5 hurricanes between 1900 and 2000:" << endl;
    for (int i = 0; i < num; i++) {
        if (cat5Hur[i] > 0) {
            indexOfStateHitByCat5Hur[cntState++] = i;
            cout << "- " << "\033[1m" << stateNames[i] << "\033[0m" << " with " << cat5Hur[i] << " Category 5 hurricane(s)" << endl;
            if (cat5Hur[i] > mostCat5Hits) {
                mostCat5Hits = cat5Hur[i];
                mostCat5Index = i;
            }
        }
    }
    if (mostCat5Index != -1) {
        cout << "\033[1m" << stateNames[mostCat5Index] << "\033[0m" << " was hit by the most Category 5 hurricanes during this period." << endl;
    }
}

// Output to the terminal
void printHurricaneData(string stateNames[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num) {
    cout << string(70, '=') << endl;
    cout << left << setw(20) << "State Name" << setw(20) << "Hurricane Hits" << setw(10) << "CAT3" << setw(10) << "CAT4" << setw(10) << "CAT5" << endl;
    for (int i = 0; i < num; i++) {
        cout << left << setw(20) << stateNames[i] << setw(20) << numHur[i] << setw(10) << cat3Hur[i] << setw(10) << cat4Hur[i] << setw(10) << cat5Hur[i] << endl;
    }
    cout << string(70, '=') << endl;
}

// Output to out.txt
void printHurricaneData(string stateNames[], int numHur[], int cat3Hur[], int cat4Hur[], int cat5Hur[], int num, string fName) {
    ofstream out(fName);
    if (!out) {
        return;
    }

    out << left << setw(20) << "State Name" << setw(30) << "Total Hurricane Hits" << setw(10) << "Major Hurricane Hits (Category 3 and Above)" << endl;
    for (int i = 0; i < num; i++) {
        int majorHits = cat3Hur[i] + cat4Hur[i] + cat5Hur[i];
        out << left << setw(20) << stateNames[i] << setw(30) << numHur[i] << setw(10) << majorHits << endl;
    }
    out.close();
}
