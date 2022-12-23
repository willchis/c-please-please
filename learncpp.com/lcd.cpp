#include <stdlib.h>
#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>
#include <pcf8574.h>
#include <lcd.h>
#include <time.h>
#include <string>
#include <iostream>
#include <cstring>

int pcf8574_address = 0x27;        // PCF8574T:0x27, PCF8574AT:0x3F
#define BASE 64         // BASE any number above 64
//Define the output pins of the PCF8574, which are directly connected to the LCD1602 pin.
#define RS      BASE+0
#define RW      BASE+1
#define EN      BASE+2
#define LED     BASE+3
#define D4      BASE+4
#define D5      BASE+5
#define D6      BASE+6
#define D7      BASE+7

int lcdhd;// used to handle LCD
int position = 0;
int maxWidth = 16;

void padAndClear(std::string &str, const size_t padSize, const size_t maxWidth, const char paddingChar = ' ')
{
    str.insert(0, padSize, paddingChar);
    if (str.length() > maxWidth) {
        str.resize(maxWidth);
    }
}

void pad(char *s, int padCount, char padChar) {
    char *p = s + padCount - strlen(s);
    strcpy(p, s);
    p--;
    while (p >= s) {
        p[0] = padChar;
        p--;
    }
}

void printWeather(std::string weather) {
    lcdPosition(lcdhd, 0, 0);
    lcdPrintf(lcdhd, "%s", weather);
}

void printCPUTemperature() {// sub function used to print CPU temperature
    FILE *fp;
    char str_temp[15];
    float CPU_temp;
    // CPU temperature data is stored in this directory.
    fp=fopen("/sys/class/thermal/thermal_zone0/temp","r");
    fgets(str_temp, 15, fp);      // read file temp
    CPU_temp = atof(str_temp)/1000.0;   // convert to Celsius degrees
    printf("CPU's temperature : %.2f \n", CPU_temp);
    lcdPosition(lcdhd, position, 0);     // set the LCD cursor position to (0,0)
    position += 1;
    if (position > maxWidth) {
        position = 0;
     }
      char buff[16];
      //snprintf(buff, sizeof(buff), "CPU: %.2fC", CPU_temp);
      std::string buffAsStdStr = buff;
      pad(str_temp, position, ' ');
   // std::cout << buffAsStdStr;
    lcdPrintf(lcdhd, "%s", str_temp);// Display CPU temperature on LCD
    fclose(fp);
}

void printDataTime() {//used to print system time 
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);// get system time
    timeinfo = localtime(&rawtime);//convert to local time
    printf("%s \n",asctime(timeinfo));
    lcdPosition(lcdhd, 0, 1);// set the LCD cursor position to (0,1) 
    lcdPrintf(lcdhd,"Time:%02d:%02d:%02d",timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec); //Display system time on LCD
}

int detectI2C(int addr) {
    int _fd = wiringPiI2CSetup (addr);   
    if (_fd < 0) {		
        printf("Error address : 0x%x \n",addr);
        return 0 ;
    } 
    else {	
        if (wiringPiI2CWrite(_fd,0) < 0) {
            printf("Not found device in address 0x%x \n",addr);
            return 0;
        }
        else {
            printf("Found device in address 0x%x \n",addr);
            return 1 ;
        }
    }
}
void setupAndPrint(std::string output) {
    int i;

    printf("Program is starting ...\n");

    wiringPiSetup();  
    if (detectI2C(0x27)) {
        pcf8574_address = 0x27;
    } else if (detectI2C(0x3F)) {
        pcf8574_address = 0x3F;
    } else {
        printf("No correct I2C address found, \n"
        "Please use command 'i2cdetect -y 1' to check the I2C address! \n"
        "Program Exit. \n");
        return;
    }
    pcf8574Setup(BASE, pcf8574_address);//initialize PCF8574
    for (i = 0; i < 8; i++) {
        pinMode(BASE + i,OUTPUT);     //set PCF8574 port to output mode
    }
    digitalWrite(LED, HIGH);     //turn on LCD backlight
    digitalWrite(RW, LOW);       //allow writing to LCD
	lcdhd = lcdInit(2,16,4,RS,EN,D4,D5,D6,D7,0,0,0,0);// initialize LCD and return “handle” used to handle LCD
    
    if (lcdhd == -1) {
        printf("lcdInit failed !");
        return;
    }
    while (1) {
        // printCPUTemperature();//print CPU temperature
        // printDataTime();        // print system time
        printWeather(output);
        delay(1000);
    }
}
