#include <fstream>
#include <iostream>

using namespace std;

int main () {

    fstream donationFile("donation_total.txt", ios_base::app);

    if (donationFile.is_open())
    {
        // File opened OK, so use it…
        cout << "File open" << endl;

        string nameAndAmount;
        cout << "Enter donation name and amount: ";
        cin >> nameAndAmount;

        donationFile << nameAndAmount << endl;

        cout << "You entered: " << nameAndAmount << endl;
        
        // Close the file when we're done.
        donationFile.close();
    }
    else
    {
        cerr << "Couldn't open file" << endl;
    }
    return 0;
}