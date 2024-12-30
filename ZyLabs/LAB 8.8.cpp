// Descending selection sort with output during execution

#include <iostream>
using namespace std;

// TODO: Write a void function SelectionSortDescendTrace() that takes
//       an integer array and the number of elements in the array as arguments,
//       and sorts the array into descending order.
void SelectionSortDescendTrace(int numbers[], int numElements) {
   for (int i = 0; i < numElements - 1; ++i) {
      int maxNum = i;
      for (int j = i + 1; j < numElements; ++j) {
         if (numbers[j] > numbers[maxNum]) {
            maxNum = j;
         }
      }
      
      int temp = numbers[i];
      numbers[i] = numbers[maxNum];
      numbers[maxNum] = temp;
      
      for (int k = 0; k < numElements; ++k) {
         cout << numbers[k] << " ";
      }
      cout << endl;
   }
}


int main() {
   int input = 0;
   int i = 0;
   int numElements = 0;
   int numbers[10];

   // TODO: Read in a list of up to 10 positive integers; stop when
   //       -1 is read. Then call SelectionSortDescendTrace() function.

   while (i < 10) {
      cin >> input;
      if (input == -1) {
         break;
      }
      numbers[i] = input;
      ++i;
   }
   
   SelectionSortDescendTrace(numbers, i);

  return 0;
}