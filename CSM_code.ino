#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64
#define S0 1
#define S1 2
#define S2 3
#define S3 4
#define sensorOut 5

Servo topServo;
Servo bottomeServo;
int frequency = 0;
int color = 0;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
    Serial.begin(115200);
    
    // Initialize OLED display
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    
    delay(2000);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    
    // Display title
    display.setCursor(50, 0);
    display.println("Colour");
    display.setCursor(50, 10);
    display.println("Sorting");
    display.setCursor(50, 20);
    display.println("Machine");
    
    // Display color labels
    display.setTextColor(BLACK, WHITE);
    display.setCursor(0, 35);
    display.println("Red");
    display.setCursor(50, 35);
    display.println("Green");
    display.setCursor(100, 35);
    display.println("Blue");
    display.display();
    
    // Configure color sensor pins
    pinMode(S0, OUTPUT);
    pinMode(S1, OUTPUT);
    pinMode(S2, OUTPUT);
    pinMode(S3, OUTPUT);
    pinMode(sensorOut, INPUT);
    digitalWrite(S0, HIGH);
    digitalWrite(S1, HIGH);
    
    // Attach servo motors
    topServo.attach(6);
    bottomeServo.attach(7);
}

void loop() {
    // Initial position
    topServo.write(115);
    delay(500);
    
    // Move object under sensor
    for(int i = 115; i > 60; i--) {
        topServo.write(i);
        delay(5);
    }
    delay(1000);
    
    // Read and process color
    color = readColor();
    delay(100);
    
    // Sort based on color
    switch(color) {
        case 1:
            bottomeServo.write(25);
            Serial.println("RED");
            break;
        case 2:
            bottomeServo.write(100);
            Serial.println("GREEN");
            break;
        case 3:
            bottomeServo.write(175);
            Serial.println("BLUE");
            break;
        case 0:
            break;
    }
    
    delay(1000);
    
    // Drop object
    for(int i = 60; i > 25; i--) {
        topServo.write(i);
        delay(5);
    }
    delay(200);
    
    // Return to start position
    for(int i = 25; i < 115; i++) {
        topServo.write(i);
        delay(5);
    }
    color = 0;
}

// Color detection function
int readColor() {
    // Read Red
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    frequency = pulseIn(sensorOut, LOW);
    int R = frequency;
    Serial.print("R= ");
    Serial.print(frequency);
    Serial.print(" ");
    delay(20);
    
    // Read Green
    digitalWrite(S2, HIGH);
    digitalWrite(S3, HIGH);
    frequency = pulseIn(sensorOut, LOW);
    int G = frequency;
    Serial.print("G= ");
    Serial.print(frequency);
    Serial.print(" ");
    delay(50);
    
    // Read Blue
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    frequency = pulseIn(sensorOut, LOW);
    int B = frequency;
    Serial.print("B= ");
    Serial.print(frequency);
    Serial.println(" ");
    delay(50);
    
    // Determine color
    if(R < G && R < B) {
        color = 1; // Red
        updateDisplayCount(0, 50); // Update red count
    }
    else if(G < R && G < B) {
        color = 2; // Green
        updateDisplayCount(60, 50); // Update green count
    }
    else if(B < R && B < G) {
        color = 3; // Blue
        updateDisplayCount(105, 50); // Update blue count
    }
    
    return color;
}

// Helper function to update display count
void updateDisplayCount(int x, int y) {
    for (int i = 1; i <= 20; i++) {
        display.setTextColor(WHITE);
        display.setCursor(x, y);
        display.println(i);
        display.display();
        delay(2000);
        display.fillRect(x, y, 20, 30, BLACK);
        display.display();
    }
}