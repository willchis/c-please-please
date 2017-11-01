#include <iostream>
#include <vector>

// NOTE: this is also saved in a repl.it example.

using namespace std;

vector<int> mergeSort(vector<int> arrayToSort) {
    for(int i = 0; i < arrayToSort.size(); i++) {
        cout << arrayToSort[i] << ", ";
    }
    cout << endl << "======" << endl;
    
    if (arrayToSort.size() == 1) {
        return arrayToSort;
    } else {
        vector<int> left(arrayToSort.begin(), arrayToSort.begin() + arrayToSort.size()/2);
        vector<int> right(arrayToSort.begin() + arrayToSort.size()/2, arrayToSort.end());
        mergeSort(left);
        mergeSort(right);
    }
    
    return arrayToSort;
}

int main() {
    vector<int> testArray = { 4, 6, 9, 2, 1, 8 };
    
    mergeSort(testArray);
    
}
