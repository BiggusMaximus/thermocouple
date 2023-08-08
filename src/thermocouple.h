#include "max6675.h"
const int NUMBER_OF_THERMOCOUPLES = 10;
float C[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int PIN_THERMOCOUPLE[10][3] = {
    // CLK, CS, SO
    {52, 50, 48},
    {53, 51, 49},
    {47, 45, 43},
    {A13, A14, A15},
    {A10, A11, A12},
    {A7, A8, A9},
    {A4, A5, A6},
    {A0, A1, A2},
    {46, 44, 42},
    {40, 38, 36}};

// CLK | cs | DO
MAX6675 thermocouple1(PIN_THERMOCOUPLE[0][0], PIN_THERMOCOUPLE[0][1], PIN_THERMOCOUPLE[0][2]);
MAX6675 thermocouple2(PIN_THERMOCOUPLE[1][0], PIN_THERMOCOUPLE[1][1], PIN_THERMOCOUPLE[1][2]);
MAX6675 thermocouple3(PIN_THERMOCOUPLE[2][0], PIN_THERMOCOUPLE[2][1], PIN_THERMOCOUPLE[2][2]);
MAX6675 thermocouple4(PIN_THERMOCOUPLE[3][0], PIN_THERMOCOUPLE[3][1], PIN_THERMOCOUPLE[3][2]);
MAX6675 thermocouple5(PIN_THERMOCOUPLE[4][0], PIN_THERMOCOUPLE[4][1], PIN_THERMOCOUPLE[4][2]);
MAX6675 thermocouple6(PIN_THERMOCOUPLE[5][0], PIN_THERMOCOUPLE[5][1], PIN_THERMOCOUPLE[5][2]);
MAX6675 thermocouple7(PIN_THERMOCOUPLE[6][0], PIN_THERMOCOUPLE[6][1], PIN_THERMOCOUPLE[6][2]);
MAX6675 thermocouple8(PIN_THERMOCOUPLE[7][0], PIN_THERMOCOUPLE[7][1], PIN_THERMOCOUPLE[7][2]);
MAX6675 thermocouple9(PIN_THERMOCOUPLE[8][0], PIN_THERMOCOUPLE[8][1], PIN_THERMOCOUPLE[8][2]);
MAX6675 thermocouple10(PIN_THERMOCOUPLE[9][0], PIN_THERMOCOUPLE[9][1], PIN_THERMOCOUPLE[9][2]);

void calibrate_thermocouples()
{
    // c = 25 -26 =
    C[0] = C[0] + 0.834 * thermocouple1.readCelsius() + 4.2562 - SUHU;
    C[1] = C[1] + 0.9227 * thermocouple2.readCelsius() + 1.5337 - SUHU;
    C[2] = C[2] + 0.9925 * thermocouple3.readCelsius() + 0.756 - SUHU;
    C[3] = C[3] + 0.9559 * thermocouple4.readCelsius() + 0.0025 - SUHU;
    C[4] = C[4] + 1.0334 * thermocouple5.readCelsius() + 3.5729 - SUHU;
    C[5] = C[5] + 0.959 * thermocouple6.readCelsius() + 0.033 - SUHU;
    C[6] = C[6] + 0.9656 * thermocouple7.readCelsius() + 0.5489 - SUHU;
    C[7] = C[7] + 0.8171 * thermocouple8.readCelsius() + 5.215 - SUHU;
    C[8] = C[8] + 1.0114 * thermocouple9.readCelsius() + 1.1183 - SUHU;
    C[9] = C[9] + 0.953 * thermocouple10.readCelsius() + 0.5772 - SUHU;
}

void show_thermocouples_pin()
{
    for (size_t i = 0; i < NUMBER_OF_THERMOCOUPLES; i++)
    {
        if (i % 2 == 0)
        {
            Serial.print("Thermocouple ");
            Serial.print(i + 1);
            Serial.print(" CLK : " + String(PIN_THERMOCOUPLE[i][0]) + " CS : " + String(PIN_THERMOCOUPLE[i][1]) + " SO : " + String(PIN_THERMOCOUPLE[i][2]));
        }
        else
        {
            Serial.print("      | Thermocouple ");
            Serial.print(i + 1);
            Serial.println(" CLK : " + String(PIN_THERMOCOUPLE[i][0]) + " CS : " + String(PIN_THERMOCOUPLE[i][1]) + " SO : " + String(PIN_THERMOCOUPLE[i][2]));
        }
    }
}
float *read_temperatures()
{
    static float data[NUMBER_OF_THERMOCOUPLES] = {
        -C[0] + 0.834 * thermocouple1.readCelsius() + 4.2562,
        -C[1] + 0.9227 * thermocouple2.readCelsius() + 1.5337,
        -C[2] + 0.9925 * thermocouple3.readCelsius() + 0.7563,
        -C[3] + 0.9559 * thermocouple4.readCelsius() + 0.0025,
        -C[4] + 1.0334 * thermocouple5.readCelsius() + 3.5729,
        -C[5] + 0.959 * thermocouple6.readCelsius() + 0.033,
        -C[6] + 0.9656 * thermocouple7.readCelsius() + 0.5489,
        -C[7] + 0.8171 * thermocouple8.readCelsius() + 5.215,
        -C[8] + 1.0114 * thermocouple9.readCelsius() + 1.1183,
        -C[9] + 0.953 * thermocouple10.readCelsius() + 0.5772};

    return data;
}

void show_thermocouple_data(float thermocouple_data[])
{
    for (size_t i = 0; i < NUMBER_OF_THERMOCOUPLES; i++)
    {
        if (i % 2 == 0)
        {
            Serial.print("Thermocouple ");
            Serial.print(i + 1);
            Serial.print(" temperature: ");
            Serial.print(thermocouple_data[i]);
            Serial.print(" °C");
        }
        else
        {
            Serial.print("      | Thermocouple ");
            Serial.print(i + 1);
            Serial.print(" temperature: ");
            Serial.print(thermocouple_data[i]);
            Serial.println(" °C");
        }
    };
    Serial.println("===========================================================================");
}