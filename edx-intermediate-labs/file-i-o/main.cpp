#include <fstream>
#include <iostream>

using namespace std;

int main () {

    fstream *donationFile = new fstream("donation_total.txt", fstream::app | fstream::in | fstream::out); // ios_base::app does not allow seekg to beginning.

    if (donationFile->is_open())
    {
        // File opened OK, so use it…
        cout << "File open" << endl;

        string name;
        double amount;
        cout << "Enter donation name and amount: ";
        cin >> name >> amount;

        *donationFile << amount << endl;

        cout << "Previous donations:" << endl;

        donationFile->clear();
        donationFile->seekg(0, ios::beg);

        string line;
        double total;
        while (getline(*donationFile, line)) {
            total += stod(line);
            cout << line << endl;
        }

        cout << "Total now is: " << total << endl;
        cout << "----------------------------------" << endl;
        
        // Close the file when we're done.
        donationFile->close();
    }
    else
    {
        cerr << "Couldn't open file" << endl;
    }
    return 0;
}