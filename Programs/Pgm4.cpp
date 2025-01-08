#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // For colors

using namespace std;

// File variables
int fileSelection;
int values;
int invalidValues = 0;
string fileName;

// Bar graph variables
const int sentinelValue = 9999;
const char barChar = 'X'; // Character used to represent the number in the file for each line
const int maxBarLength = 112;
const int WHITE = 7; // Default console text color
int lineNumber = 1; // For Y-axis

// Handling values (colors)
bool isNegative; // If true for a negative value, it will make the line blue
bool isTooLarge; // Will make the line red if value reaches sentinel value and beyond
HANDLE hConsole; // Color handling

int originalValue; // Used to compare to output final calculations

int firstLargestNum = -1;
int secondLargestNum = -1;
int thirdLargestNum = -1;

int firstSmallestNum = 1000;
int secondSmallestNum = 1000;
int thirdSmallestNum = 1000;

int main() {

    // Color changes
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    // Prompt the user to select a file
    do {
        cout << "Select file to process:\n";
        cout << "1. mixed.txt\n";
        cout << "2. valid.txt\n";
        cout << "3. three.txt\n";
        cout << "4. missing.txt\n";
        cout << "\nChoice: ";
        cin >> fileSelection;
    } while (fileSelection < 1 || fileSelection > 4);

    // Set the file name based on user input
    switch (fileSelection) {
        case 1: fileName = "mixed.txt"; 
            break;
        case 2: fileName = "valid.txt"; 
            break;
        case 3: fileName = "three.txt"; 
            break;
        case 4: cout << "ERROR: Data file not found."; 
            return 0;
    }
    // Open the selected file
    ifstream DataFS(fileName);
    cout << "\n\nBar graph for data contained in " << fileName << " file.\n\n";

    // Read values from the selected file and process each value
    while (DataFS >> values && values != sentinelValue) {
        isNegative = false;
        isTooLarge = false;
        originalValue = values;  // Store original value for comparisons

        // Handle negative values for the bar graph
        if (values < 0) {
            values = -values;  // Convert negative to positive for graph display
            isNegative = true;
            invalidValues++;
        }
        // Handle values exceeding the maximum bar length
        if (values > maxBarLength) {
            values = maxBarLength;  // Cap the bar length at maxBarLength
            isTooLarge = true;
            invalidValues++;
        }
        // Find and update largest values using originalValue
        if (originalValue > firstLargestNum) {
            thirdLargestNum = secondLargestNum;
            secondLargestNum = firstLargestNum;
            firstLargestNum = originalValue;
        } else if (originalValue > secondLargestNum) {
            thirdLargestNum = secondLargestNum;
            secondLargestNum = originalValue;
        } else if (originalValue > thirdLargestNum) {
            thirdLargestNum = originalValue;
        }
        // Find and update smallest values using originalValue
        if (originalValue < firstSmallestNum) {
            thirdSmallestNum = secondSmallestNum;
            secondSmallestNum = firstSmallestNum;
            firstSmallestNum = originalValue;
        }
        else if (originalValue < secondSmallestNum) {
            thirdSmallestNum = secondSmallestNum;
            secondSmallestNum = originalValue;
        }
        else if (originalValue < thirdSmallestNum) {
            thirdSmallestNum = originalValue;
        }

        // Format and print the Y-axis label (line number)
        if (lineNumber < 10) {
            cout << " " << lineNumber << " | ";  // For alignning single digit Y-axis labels
        } else {
            cout << lineNumber << " | ";  // For double digit Y-axis labels
        }

        // Set console color based on the value type
        if (isNegative) {
            SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE);  // Blue for negative
        } else if (isTooLarge) {
            SetConsoleTextAttribute(hConsole, BACKGROUND_RED);   // Red for too large
        } else {
            SetConsoleTextAttribute(hConsole, WHITE);            // Default color
        }

        // Print the 'X's for the bar graph
        for (int i = 0; i < values; i++) {
            cout << barChar;
        }

        // Reset the color and print a newline
        SetConsoleTextAttribute(hConsole, WHITE);
        cout << "\n";
        lineNumber++;
    }
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    // Print the X-axis (from 1 to 112)
    cout << "    ";  // Align with Y-axis labels
    cout << " 1         ";
    for (int i = 10; i <= maxBarLength; i += 10) {
        cout << i;
        if (i < 100) cout << "        ";  // Spacing for numbers <100
        else cout << "       ";           // Adjust spacing for numbers >100
    }
    cout << "\n";
    // Output smallest and largest values
    cout << "\nSMALLEST\n========\n";
    cout << "The smallest value: " << firstSmallestNum << "\n";
    cout << "2nd smallest value: " << secondSmallestNum << "\n";
    cout << "3rd smallest value: " << thirdSmallestNum << "\n";

    cout << "\nLARGEST\n=======\n";
    cout << "The largest value: " << firstLargestNum << "\n";
    cout << "2nd largest value: " << secondLargestNum << "\n";
    cout << "3rd largest value: " << thirdLargestNum << "\n";

    // Output the number of invalid values
    cout << "\nINVALID\n=======\n";
    cout << "There are " << invalidValues << " invalid values in the data.\n";

    // Close the file
    DataFS.close();
    return 0;
}
