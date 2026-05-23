#include "reg52.h"

// Data type define
typedef unsigned int u16;
typedef unsigned char u8;

// 74HC138 control pins
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

// Seven segment codes
u8 code smgduan[10] =
{
    0x3f, //0
    0x06, //1
    0x5b, //2
    0x4f, //3
    0x66, //4
    0x6d, //5
    0x7d, //6
    0x07, //7
    0x7f, //8
    0x6f  //9
};

// Delay function
void delay(u16 i)
{
    while(i--);
}

// Dynamic display function
void DigDisplay()
{
    u8 i;

    for(i=0; i<8; i++)
    {
        switch(i)
        {
            case(0):
                LSA=0; LSB=0; LSC=0;
                break;

            case(1):
                LSA=1; LSB=0; LSC=0;
                break;

            case(2):
                LSA=0; LSB=1; LSC=0;
                break;

            case(3):
                LSA=1; LSB=1; LSC=0;
                break;

            case(4):
                LSA=0; LSB=0; LSC=1;
                break;

            case(5):
                LSA=1; LSB=0; LSC=1;
                break;

            case(6):
                LSA=0; LSB=1; LSC=1;
                break;

            case(7):
                LSA=1; LSB=1; LSC=1;
                break;
        }

        // Show 4 and 7 in last 2 displays
        if(i == 6)
            P0 = smgduan[4];

        else if(i == 7)
            P0 = smgduan[7];

        else
            P0 = 0x00;

        delay(100);

        P0 = 0x00;
    }
}

// Main function
void main()
{
    while(1)
    {
        DigDisplay();
    }
}
