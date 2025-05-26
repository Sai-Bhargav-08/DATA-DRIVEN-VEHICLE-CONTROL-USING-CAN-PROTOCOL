 **🚗 CAN-Based Vehicle Control System (LPC2129)**

> A compact vehicle control system using CAN protocol on the LPC2129 ARM7 microcontroller. It monitors engine temperature, provides a reverse alert, and shows window position—all coordinated over a CAN bus using MCP2551 transceivers.

--------------------------------------------------------------------------------------------------------------
**🔧 Key Features**
> 
 🌡️ Engine Temperature Monitoring
 
>   DS18B20 digital sensor (1-Wire)
> 
>  Real-time temperature on LCD & CAN broadcast

🔙 Reverse Parking Alert

> Sharp GP2D12 IR sensor (10–80 cm range)
> 
> Buzzer & LCD warning if object <1 cm when reversing

🪟 Window Position Display

> Window level (0–8) via CAN

 Displayed as:

> Bar graph on 8 LEDs
> 
> Custom CGRAM icon on 16×2 LCD

📶 CAN Bus Communication

> MCP2551 transceiver (1 Mb/s, ISO-11898)
> 
> Reliable, noise-resistant 2-wire CAN network (CANH/CANL)

--------------------------------------------------------------------------------------------------------------
**🛠️ Hardware Components**

🎛️ LPC2129 Microcontroller

> ARM7TDMI core with dual CAN controllers (10–60 MHz operation). Handles all sensing, processing, and communication.

🔄 MCP2551 CAN Transceiver

> ISO-11898 compliant high-speed CAN PHY. Buffers the LPC2129’s TX/RX logic to the CANH/CANL lines (1 Mb/s, fault-tolerant).

🌡️ DS18B20 Temperature Sensor

> Digital thermometer (9–12 bit resolution) on a 1-Wire bus. Requires a 4.7 kΩ pull-up resistor and supports parasite power mode.

🔭 Sharp GP2D12 IR Distance Sensor

> Analog distance sensor (~10–80 cm range). Output voltage decreases with distance and is connected to LPC’s ADC input.

📟 16×2 LCD Module (HD44780)

> Used for real-time status display. Custom 5×8 CGRAM characters are defined to show window graphics.

💡 Indicator LEDs (×8)

> Active-low green LEDs used to display window position (0–8) as a bar-graph.

🔔 Buzzer

> Piezo sounder activated by reverse alert logic when an obstacle is detected.

⚡ Power Supply & Miscellaneous

> 5 V regulator for logic and sensors, 4.7 kΩ pull-up for 1-Wire, buttons for reverse gear input, and 120 Ω CAN bus terminators.

--------------------------------------------------------------------------------------------------------------
**💻 Software & Firmware**
> Embedded C (Keil µVision)
> Handles:
> 
> 1-Wire comm (DS18B20)
> 
> ADC reads (GP2D12)
> 
> CGRAM characters on LCD
> 
> CAN setup & messaging
> 
> Flashing via Flash Magic
> 
> Uses UART ISP mode (via COM port)
> 
> Uploads HEX file to LPC2129 flash

--------------------------------------------------------------------------------------------------------------
**🔁 System Logic**
 
🌡️Engine Temp:

> DS18B20 → LPC2129 → LCD & CAN
> 
> Uses parasite power mode

🔙Reverse Alert:

> Reverse switch triggers ADC read (GP2D12)
> 
> If distance <15 cm → Buzzer ON + LCD “WARNING”

🪟 Window Display:

> Main Node sends 0–8 level via CAN
> 
> Window Node lights 0–8 LEDs
> 
> LCD shows matching icon (custom CGRAM)
>
📶CAN Communication:

> MCP2551 handles bus signaling
> 
> LPC2129 CAN controller manages frames
--------------------------------------------------------------------------------------------------------------
**✅ Testing Checklist**
> 
> ✅ Power on → LCD boots
> 
> ✅ Temp appears and changes with heat
> 
> ✅ Reverse + Object <15 cm → Buzzer + LCD alert
> 
> ✅ Send window level via CAN → LED bar & LCD update

--------------------------------------------------------------------------------------------------------------
> **📚 References**

> NXP LPC2129 Datasheet
> 
> DS18B20 1-Wire Protocol (Maxim/Analog Devices)
> 
> MCP2551 CAN Transceiver (Microchip)
> 
> Bosch CAN Protocol 2.0
> 
> PhiloHome GP2D12 Guide
> 
> Controllerstech – LCD CGRAM Tutorial
