#include <iostream>
#include <fstream>
#include <ctime>
#include "request.cpp"

void padText(char text[], int textLength, char padCharacter, int padCount) {
    char tempText[textLength];
    char tempChar = text[0];

    for (int i = 0; i < textLength; i++) {
        tempText[i] = text[i];
        if (i < padCount) {
            text[i] = padCharacter;
        }
    }

    for (int i = 0; i < textLength; i++) {
        if (i == textLength - 1) {
            text[i] = '\0';
        } else if (i >= padCount) {
            if (tempText[i - padCount] == '\0') {
                break;
            }
            text[i] = tempText[i - padCount];
        }

    }
}

int main()
{
    get_request("https://api.openweathermap.org/data/2.5/weather?lat=40.002538&lon=-105.1399453&appId=dff9026699f844492353d69afac2caf7");
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    std::string today = std::to_string(now->tm_year + 1900) 
        + '-' + std::to_string(now->tm_mon + 1) 
        + '-' + std::to_string(now->tm_mday);

    char test[] = "tesonetw";
    int length = sizeof(test) / sizeof(char);

    padText(test, length, ' ', 5);

    std::cout << "result: " << test;
    return 0;
}

