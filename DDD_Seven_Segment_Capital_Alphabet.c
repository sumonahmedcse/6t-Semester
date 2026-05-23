//8051 Dynamic Digital Tube Display show Capital alphabet
#include "reg52.h"

// Data type define
typedef unsigned int u16;
typedef unsigned char u8;

// 74HC138 control pins
sbit LSA = P2^2;
sbit LSB = P2^3;
sbit LSC = P2^4;

// Seven Segment Codes for A B C D E F G H
u8 code smgduan[8] =
{
    0x77, // A
    0x7C, // B
    0x39, // C
    0x5E, // D
    0x79, // E
    0x71, // F
    0x3D, // G
    0x76  // H
};

// Delay Function
void delay(u16 i)
{
    while(i--);
}

// Dynamic Display Function
void DigDisplay()
{
    u8 i;

    for(i=0; i<8; i++)
    {
        // Select Display Position
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

        // Send Alphabet Data
        P0 = smgduan[i];

        // Small Delay
        delay(100);

        // Clear Display
        P0 = 0x00;
    }
}

// Main Function
void main()
{
    while(1)
    {
        DigDisplay();
    }
}
