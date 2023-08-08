#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void start_display()
{

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        for (;;)
            ;
    }
    delay(2000);
    display.clearDisplay();
    display.invertDisplay(true);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(25, 10);
    // Display static text
    display.println("Thermocouples");
    display.setCursor(60, 20);
    display.println("By");
    display.setCursor(25, 30);
    display.println("BaseEngineering");
    display.display();
}

void display_thermocouple_data(float thermocouple_data[])
{
    uint8_t x = 0;
    uint8_t y = 10;
    display.clearDisplay();
    display.setCursor(20, 0);
    display.print("Thermocouples");
    for (size_t i = 0; i < NUMBER_OF_THERMOCOUPLES; i++)
    {
        if (i % 2 == 0)
        {
            display.setCursor(x, y);
            display.print(i + 1);
            display.print(": ");
            display.print(thermocouple_data[i]);
            display.print(" C");
        }
        else
        {
            display.setCursor(x + 64, y);
            display.print(i + 1);
            display.print(": ");
            display.print(thermocouple_data[i]);
            display.print(" C");
            y += 10;
        }
        delay(100);
    };
    display.display();
}
