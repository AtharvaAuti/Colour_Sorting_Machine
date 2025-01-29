# Colour_Sorting_Machine
A color sorting machine using Arduino Uno and TCS3200 sensor that automatically detects and sorts objects by red, green and blue colors using servo motors. The system displays real-time color counts on an OLED screen. Applications include industrial sorting and quality control.



## Features
- Color detection for red, green, and blue objects
- Automated sorting into separate bins
- Real-time count display on OLED screen
- 5V regulated power supply
- Servo-controlled sorting mechanism
- User-friendly interface

## Hardware Components
- Arduino Uno
- TCS3200 Color Sensor
- 2x SG90 Servo Motors
- 128x64 OLED Display
- 5V Regulated Power Supply
- Connecting Wires
- Structure and sorting bins

## Technical Specifications
### Color Sensor (TCS3200)
- Operating voltage: 2.7V to 5.5V
- Interface: Digital TTL
- Working temperature: -40°C to 85°C
- High-resolution conversion of light intensity to frequency

### Servo Motors (SG90)
- Weight: 9g
- Operating voltage: 4.8V (~5V)
- Operating speed: 0.1s/60 degree
- Stall torque: 1.8 kgf·cm

### OLED Display
- Resolution: 128x64 pixels
- Interface: I2C/SPI
- Operating voltage: 3.3V-5V
- Screen size: 0.96 inch

## Setup Instructions
1. Connect the components according to the following pin configuration:
   - TCS3200 sensor: Pins S0-S3 to Arduino digital pins 1-4
   - Output pin to Arduino digital pin 5
   - Top servo motor to pin 6
   - Bottom servo motor to pin 7
   - OLED display: SDA and SCL pins to A4 and A5

2. Power supply connections:
   - Connect 5V regulated power supply
   - Ensure proper grounding of all components

3. Upload the provided Arduino code to the board

## Usage
1. Power on the system
2. Place colored objects (red, green, or blue) in the input tube
3. The system will automatically:
   - Detect the color
   - Sort the object into the appropriate bin
   - Update the count on the OLED display

## Working Process
1. Top servo positions object under color sensor
2. TCS3200 sensor detects color
3. Bottom servo rotates to correct bin position
4. Top servo drops object into sorting chute
5. Count updates on OLED display
6. System returns to starting position

## Applications
- Industrial quality control
- Manufacturing sorting processes
- Recycling industry
- Educational purposes
- Small-scale sorting operations

## Future Improvements
- Add weight measurement capabilities
- Increase sorting speed
- Expand color detection range
- Implement quality control features
- PLC integration for industrial applications
- Enhanced user interface

## Troubleshooting
- Ensure proper lighting conditions for accurate color detection
- Check power supply stability
- Verify servo motor positions and alignment
- Confirm proper I2C connection for OLED display

