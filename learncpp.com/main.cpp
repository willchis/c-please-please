#include <iostream>
#include <fstream>
#include <ctime>

int main()
{
    int x = 5;
    std::string userText; 
    std::cout << x << ">>"; // print value of x (5) to console
    std::cin >> userText;

    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday
         << "\n";
         

    return 0;
}