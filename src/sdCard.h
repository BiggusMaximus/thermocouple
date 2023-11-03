#include <SD.h>
// #include "rtc.h"

int csPin = 4;
File dataFile;

void Initialize_SDcard()
{
    if (!SD.begin(csPin))
    {
        Serial.println("Card failed, or not present");
        return;
    }
    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile)
    {
        dataFile.println("T1,T2,T3,T4,T5,T6,T7,T8,T9,T10"); //Write the first row of the excel file
        dataFile.close();
    }
    // rtc_innit();
}

void Write_SDcard(float read_temperature[])
{
    // DateTime time = rtc.now();
    // Full Timestamp
    // Serial.println(String(time.timestamp(DateTime::TIMESTAMP_TIME)));

    File dataFile = SD.open("datalog.txt", FILE_WRITE);
    if (dataFile)
    {
        // dataFile.print(String(time.timestamp(DateTime::TIMESTAMP_TIME)));
        // dataFile.print(",");
        for(size_t i = 0; i < 10; i++)
        {
            dataFile.print(read_temperature[i]);
            dataFile.print(",");
        }
        dataFile.println();
        dataFile.close();
    }
    else
    {
        Serial.println("SD card writing failed");
    }
}