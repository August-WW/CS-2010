#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// File limits
const int MAX_ROWS = 20;
const int MAX_COLUMNS = 2;

// Functions
void ShowMenu() {
    cout << "What to do [L(ook up), A(dd), S(how), D(one)]? ";
}

int ReadData(string filename, string AryName[], int AryQuantity[][MAX_COLUMNS]) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: File " << filename << " could not be opened." << endl;
        return 0;
    }

    int count = 0;
    while (count < MAX_ROWS && file >> AryName[count] >> AryQuantity[count][0] >> AryQuantity[count][1]) {
        for (char &c : AryName[count]) {
            c = tolower(c); // Convert names to lowercase
        } 
        count++;
    }
    file.close();

    if (count == 0) {   // No animals in the file
        cout << "There is no data in the file." << endl;
    }

    return count;
}

void SortData(string AryName[], int AryQuantity[][MAX_COLUMNS], int itemCount) {
    for (int i = 0; i < itemCount - 1; ++i) {
        for (int j = 0; j < itemCount - i - 1; ++j) {
            if (AryName[j] > AryName[j + 1]) {
                // Swap names
                string tempName = AryName[j];
                AryName[j] = AryName[j + 1];
                AryName[j + 1] = tempName;

                // Swap quantities
                int tempMales = AryQuantity[j][0];
                int tempFemales = AryQuantity[j][1];
                AryQuantity[j][0] = AryQuantity[j + 1][0];
                AryQuantity[j][1] = AryQuantity[j + 1][1];
                AryQuantity[j + 1][0] = tempMales;
                AryQuantity[j + 1][1] = tempFemales;
            }
        }
    }
}

// When the user selects "L"
int FindAnimal(string AryName[], string animal, int itemCount) {
    int left = 0, right = itemCount - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (AryName[mid] == animal) {
            return mid;
        } else if (AryName[mid] < animal) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

// When the user selects "A"
void AddEditAnimal(string AryName[], int AryQuantity[][MAX_COLUMNS], int& itemCount) {
    if (itemCount >= MAX_ROWS) {
        cout << ">>> Cannot add more animals. Array is at full capacity." << endl;
        return;
    }

    string animal;
    int males, females;

    cout << "Name to add? ";
    cin >> animal;
    for (char &c : animal) {
        c = tolower(c); // Convert input to lowercase
    } 

    int index = FindAnimal(AryName, animal, itemCount);

    cout << "Number of males? ";
    cin >> males;
    cout << "Number of females? ";
    cin >> females;

    if (males < 0 || females < 0) {
        cout << ">>> Error: Negative quantities are not allowed." << endl;
        return;
    }

    if (index == -1) { // Add new animal
        AryName[itemCount] = animal;
        AryQuantity[itemCount][0] = males;
        AryQuantity[itemCount][1] = females;
        itemCount++;
    } 
    else { // Update existing animal
        AryQuantity[index][0] = males;
        AryQuantity[index][1] = females;
    }

    SortData(AryName, AryQuantity, itemCount);
    ofstream file("animals.txt");
    cout << ">>> The number of " << animal << " has been updated." << endl;

    // Add new entry to animals.txt
    for (int i = 0; i < itemCount; ++i) {
        file << AryName[i] << " " << AryQuantity[i][0] << " " << AryQuantity[i][1] << endl;
    }
    file.close();
}

// When the user selects "S"
void ShowAll(string AryName[], int AryQuantity[][MAX_COLUMNS], int itemCount) {
    if (itemCount == 0) {
        cout << ">>> No animals to display." << endl;
        return;
    }

    cout << "Animals in ascending order:" << endl;
    for (int i = 0; i < itemCount; ++i) {
        cout << i + 1 << ": " << AryName[i] << ": " << AryQuantity[i][0] << " males, and " << AryQuantity[i][1] << " females" << endl;
    }
}

void ProcessUserChoice(string AryName[], int AryQuantity[][MAX_COLUMNS], int& itemCount, char choice) {
    switch (choice) {
        case 'l': { // Lookup
            string animal;
            cout << "Name to look up? ";
            cin >> animal;
            for (char &c : animal) {
                c = tolower(c); // Convert input to lowercase
            } 
            int index = FindAnimal(AryName, animal, itemCount);
            if (index == -1) {
                cout << ">>> There is no data in the array for " << animal << endl;
            } 
            else {
                cout << ">>> There are " << AryQuantity[index][0] << " male and " << AryQuantity[index][1] << " female " << animal << endl;
            }
            break;
        }
        case 'a': { // Add
            AddEditAnimal(AryName, AryQuantity, itemCount);
            break;
        }
        case 's': { // Show (sorted)
            ShowAll(AryName, AryQuantity, itemCount);
            break;
        }
        case 'd': // Terminate program
            break;
        default:
            cout << ">>> " << choice << " is an invalid option. Please enter again." << endl;
    }
}

int main() {
    string AryName[MAX_ROWS];
    int AryQuantity[MAX_ROWS][MAX_COLUMNS] = {0};
    int itemCount = 0;

    // Initialize the program by reading data from the file
    itemCount = ReadData("animals.txt", AryName, AryQuantity);

    // Sort the data after reading the file. Will show when the user enters "S"
    SortData(AryName, AryQuantity, itemCount);

    // Main program loop
    char choice;
    do {
        ShowMenu();
        cin >> choice;
        choice = tolower(choice); // Normalize input
        ProcessUserChoice(AryName, AryQuantity, itemCount, choice);
    } while (choice != 'd');

    return 0;
}
