#include <iostream>
#include <array>

using namespace std;

int inputNumbers[] = { 2, 2, 5, 10, 3, 12, 1, 9 };

int main() {
    int arraySize = sizeof(inputNumbers)/sizeof(inputNumbers[0]);
    
    // Get highest value in array
    int max = 0;
    for (int i = 0; i < arraySize; i++) {
        if (inputNumbers[i] > max) {
            max = inputNumbers[i];
        }
    }

    int countArrayLength = max + 1;
    // Create an array of size equal to max value in original array
    int countArray[countArrayLength];
    // initialize array
    for (int i = 0; i < countArrayLength; i++) {
        countArray[i] = 0;
    }

    for (int i = 0; i < arraySize; i++) {
        countArray[inputNumbers[i]]++;
    }

    for (int i = 0; i < countArrayLength; i++) {
        cout << countArray[i] << ", ";
    }

    cout << endl;
    
    // Output sorted array
    for (int i = 0; i < countArrayLength; i++) {
        if (countArray[i] > 0) {
            for (int j = 0; j < countArray[i]; j++) {
                cout << i << ",";
            }
        }
    }
    
}
