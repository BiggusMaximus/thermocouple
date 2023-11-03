#include "max6675.h"
const int NUMBER_OF_THERMOCOUPLES = 10;
float C[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int PIN_THERMOCOUPLE[10][3] = {
    // CLK, CS, SO
    {26, 24, 22},
    {27, 25, 23},
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
    // C[0] = C[0] + 1.3473 * thermocouple1.readCelsius() - 6.3064 - SUHU;
    // C[1] = C[1] + 1.3609 * thermocouple2.readCelsius() - 6.2511 - SUHU;
    // C[2] = C[2] + 1.3038 * thermocouple3.readCelsius() - 5.2852 - SUHU;
    // C[3] = C[3] + 1.3178 * thermocouple4.readCelsius() - 6.2457 - SUHU;
    // C[4] = C[4] + 1.1365 * thermocouple5.readCelsius() - 2.38   - SUHU;
    // C[5] = C[5] + 1.3133 * thermocouple6.readCelsius() - 6.6797 - SUHU;
    // C[6] = C[6] + 1.3211 * thermocouple7.readCelsius() - 6.6039 - SUHU;
    // C[7] = C[7] + 1.2534 * thermocouple8.readCelsius() - 5.0308 - SUHU;
    // C[8] = C[8] + 1.3168 * thermocouple9.readCelsius() - 5.65   - SUHU;
    // C[9] = C[9] + 1.223 * thermocouple10.readCelsius() - 4.4037 - SUHU;

    C[0] = thermocouple1.readCelsius();
    C[1] = thermocouple2.readCelsius();
    C[2] = thermocouple3.readCelsius();
    C[3] = thermocouple4.readCelsius();
    C[4] = thermocouple5.readCelsius();
    C[5] = thermocouple6.readCelsius();
    C[6] = thermocouple7.readCelsius();
    C[7] = thermocouple8.readCelsius();
    C[8] = thermocouple9.readCelsius();
    C[9] = thermocouple10.readCelsius();
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
    static float data[NUMBER_OF_THERMOCOUPLES] = 
    {
        // -C[0] + 1.3473 * thermocouple1.readCelsius() - 6.3064,
        // -C[1] + 1.3609 * thermocouple2.readCelsius() - 6.2511,
        // -C[2] + 1.3038 * thermocouple3.readCelsius() - 5.2852,
        // -C[3] + 1.3178 * thermocouple4.readCelsius() - 6.2457,
        // -C[4] + 1.1365 * thermocouple5.readCelsius() - 2.38,
        // -C[5] + 1.3133 * thermocouple6.readCelsius() - 6.6797,
        // -C[6] + 1.3211 * thermocouple7.readCelsius() - 6.6039,
        // -C[7] + 1.2534 * thermocouple8.readCelsius() - 5.0308,
        // -C[8] + 1.3168 * thermocouple9.readCelsius() - 5.65,
        // -C[9] + 1.223 * thermocouple10.readCelsius() - 4.4037

        thermocouple1.readCelsius(),
        thermocouple2.readCelsius(),
        thermocouple3.readCelsius(),
        thermocouple4.readCelsius(),
        thermocouple5.readCelsius(),
        thermocouple6.readCelsius(),
        thermocouple7.readCelsius(),
        thermocouple8.readCelsius(),
        thermocouple9.readCelsius(),
        thermocouple10.readCelsius()
    };
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