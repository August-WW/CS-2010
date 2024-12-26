// People's weights

#include <iostream>
#include <iomanip>              // For setprecision
using namespace std;

int main() {

   double weightOne, weightTwo, weightThree, weightFour, weightFive;
   double totalWeight;
   double averageWeight;
   double maxWeight;
   
   cout << fixed << setprecision(2);
   
   cout << "Enter weight 1:" << endl;
   cin >> weightOne;
   
   cout << "Enter weight 2:" << endl;
   cin >> weightTwo;
   
   cout << "Enter weight 3:" << endl;
   cin >> weightThree;
   
   cout << "Enter weight 4:" << endl;
   cin >> weightFour;
   
   cout << "Enter weight 5:" << endl;
   cin >> weightFive;
   
   cout << "You entered: " << weightOne << " " << weightTwo << " " << weightThree << " " << weightFour << " " << weightFive << " " << endl;
   
   totalWeight = weightOne + weightTwo + weightThree + weightFour + weightFive;
   averageWeight = (totalWeight / 5);
   
   maxWeight = weightOne;
   
   if (weightTwo > maxWeight) {
      maxWeight = weightTwo;
   }
   if (weightThree > maxWeight) {
      maxWeight = weightThree;
   }
   if (weightFour > maxWeight) {
      maxWeight = weightFour;
   }
   if (weightFive > maxWeight) {
      maxWeight = weightFive;
   }
   
   cout << "\nTotal weight: " << totalWeight;
   cout << "\nAverage weight: " << averageWeight;
   cout << "\nMax weight: " << maxWeight;
   cout << endl;
   
   return 0;
}