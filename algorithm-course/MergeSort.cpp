#include <iostream>
#include <vector>

using namespace std;

vector<int> combine(vector<int> left, vector<int> right) {
    cout << "...." << endl;
    vector<int> combined;
    
    int l = 0;
    int r = 0;
    
    while (l < left.size() && r < right.size()) {
        if (left[l] <= right[r]) {
            combined.push_back(left[l]);
            l++;
        } else {
            combined.push_back(right[r]);
            r++;
        }
    }
    
    // remaining elements
    while (l < left.size()) {
        combined.push_back(left[l]);
        l++;
    }
    while (r < right.size()) {
        combined.push_back(right[r]);
        r++;
    }
    
    for(int i = 0; i < combined.size(); i++) {
        cout << combined[i] << ", ";
    }
    
    cout << endl << "...." << endl;
    return combined;
}

vector<int> split(vector<int> arrayToSort) {
    for(int i = 0; i < arrayToSort.size(); i++) {
        cout << arrayToSort[i] << ", ";
    }
    cout << endl << "======" << endl;
    
    if (arrayToSort.size() == 1) {
        return arrayToSort;
    } else {
        vector<int> left(arrayToSort.begin(), arrayToSort.begin() + arrayToSort.size()/2);
        vector<int> right(arrayToSort.begin() + arrayToSort.size()/2, arrayToSort.end());
        
        arrayToSort = combine(split(left), split(right));
    }
    
    return arrayToSort;
}



int main() {
    vector<int> testArray = { 4, 6, 9, 2, 1, 8, 10, 3, 88, 4, 6 };
    
    split(testArray);
    
}