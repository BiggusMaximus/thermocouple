#include "stdio.h"

int PIN_THERMOCOUPLE[8][3] = {
    {22, 24, 26},
    {21, 23, 25},
    {28, 30, 32},
    {27, 29, 31},
    {34, 36, 38},
    {33, 35, 37},
    {40, 42, 44},
    {39, 41, 43},
};

int main()
{
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 3; j++)
        {
            printf("%d \n", PIN_THERMOCOUPLE[i][j]);
        }
    }
}