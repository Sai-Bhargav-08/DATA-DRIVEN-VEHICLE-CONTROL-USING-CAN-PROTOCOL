> **🚙 DATA-DRIVEN-VEHICLE-CONTROL-USING-CAN-PROTOCOL**

> CAN-based vehicle control system developed for the LPC2129.  Features include engine temperature display (DS18B20), reverse alert (GP2D12), and window control.  Software implemented in Embedded-C using Keil and Flash Magic. Hardware includes MCP2551 CAN transceivers.

> **🚗 CAN-based Vehicle Control System**
> 
This project implements a vehicle control system on an NXP LPC2129 microcontroller, coordinating multiple subsystems over a CAN bus. It features: engine coolant temperature monitoring, a reverse parking alert, and a window position display. Engine temperature is measured by a DS18B20 digital sensor (using Maxim’s 1-Wire protocol) and the data can be shown on the LCD or sent via CAN.
> 
> A Sharp GP2D12 IR sensor provides distance readings (8–85 cm range) for the reverse alert, sounding a buzzer and LCD warning if an obstacle is within 15 cm. Window glass position (0–8 levels) is received via CAN messages and visualized both on 8 LEDs and a 16×2 LCD using custom characters. The CAN network (twisted-pair CANH/CANL) allows these modules to communicate reliably.
> 
> The firmware is written in Embedded C (Keil µVision) and programmed into the LPC2129 flash via Flash Magic. Overall, this README outlines the hardware, software, and protocols used, with emphasis on clarity and detail for each component.

--------------------------------------------------------------------------------------------------------------
> **🔧 Features**
> 
> 🌡️ Engine Temperature Monitoring – Uses a DS18B20 1-Wire digital sensor for real-time coolant temperature.
> 
> 🔙 Reverse Parking Alert – Sharp GP2D12 IR distance sensor detects rear obstacles. If a parked object is closer than ~15 cm in reverse gear, a buzzer sounds and the LCD displays a warning.
> 
> 🪟 Window Position Display – 8 active-low LEDs form a bar-graph for window level (closed→open). The 16×2 LCD shows a custom “window” icon (CGRAM graphic) matching the position.
> 
> 📶 CAN Bus Communication – System modules share data over a two-wire CAN network (CANH/CANL) with priority-based messaging. An MCP2551 transceiver interfaces the MCU to the differential CAN bus.

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
> **💾 Software Implementation**

💻 Embedded C (Keil µVision)
> Firmware is written in C using the Keil MDK-ARM toolchain. It manages sensor I/O, ADC reads, LCD updates, and CAN messaging.

📤 Flash Magic
> Used to flash the LPC2129 via UART (ISP mode). Transfers the compiled HEX file from PC to MCU.

📚 Drivers & Libraries
> Includes routines for:
> 
> 1-Wire communication (DS18B20)
> 
> ADC reading (GP2D12)
> 
> LCD character writing & CGRAM updates
> 
> CAN controller setup (baud rate, filters)

🔁 Control Logic
> The main loop or interrupts periodically:
> 
> Poll sensors
> 
> Detect reverse mode and read distance
> 
> Handle window position messages from CAN
> 
> Update LEDs and LCD accordingly

--------------------------------------------------------------------------------------------------------------
> **🚀 System Operation**

🌡️ Engine Temperature Monitoring
> The DS18B20 communicates via a 1-Wire bus with a pull-up resistor.
> 
> Each sensor has a unique 64-bit ID, allowing multiple sensors on the same bus.
> 
> The LPC2129 sends reset and read time slots to get temperature data.
> 
> Temperature is displayed on the LCD and optionally broadcast via CAN.
> 
> Parasite power mode allows powering DS18B20 through the data line, minimizing wiring.
--------------------------------------------------------------------------------------------------------------
**🔙 Reverse Parking Alert**

> The Sharp GP2D12 outputs an analog voltage based on obstacle distance.
> 
> When reverse gear is active, LPC2129 reads the voltage via its ADC.
> 
> If distance <15 cm, the buzzer is activated and a warning appears on the LCD.
> 
> The sensor effectively covers 10–80 cm, ideal for parking safety.
> 
> Only active when reverse switch is pressed (interrupt driven).

--------------------------------------------------------------------------------------------------------------
> **🪟 Window Position Display**

> Main Node sends window position data (0–8) via CAN.
> 
> 0 = Fully Open (0 LEDs ON)
> 
> 8 = Fully Closed (8 LEDs ON)
> 
> At Window Node (Node 2):
> 
> LEDs display window position using a bar-graph.
> 
> More LEDs ON = more closed.
> 
> At Main Node LCD:
> 
> A custom CGRAM symbol in the last column of line 2 represents window height.
> 
> As value increases, lower pixels fill to indicate more closure.

--------------------------------------------------------------------------------------------------------------
> **📡 CAN Communication (and MCP2551)**
 
> The LPC2129’s CAN controller manages all data framing.
> 
> Nodes connect to a two-wire twisted pair (CANH & CANL).
> 
> The MCP2551 transceiver translates TTL signals to differential CAN voltages.
> 
> Supports CAN 2.0B, ISO-11898, and speeds up to 1 Mb/s.
> 
> Provides short-circuit protection, thermal shutdown, and fail-safe states.
> 
> Ensures reliable communication even in noisy environments.
> 
> Highest-priority messages win arbitration.
> 
> 120 Ω terminators at each bus end prevent signal reflections.

--------------------------------------------------------------------------------------------------------------
> **🔌 Protocol Details**

> 🧵 1-Wire Protocol (DS18B20)

> Uses one signal wire + ground, with a 4.7 kΩ pull-up resistor.
> 
> Master initiates communication with reset pulse and time slots.
> 
> Each device has a unique 64-bit ROM code.
> 
> Multiple DS18B20s can be used on the same line.
> 
> Supports parasite power by charging an internal capacitor.
> 
> Offers CRC validation and long-range communication reliability.

--------------------------------------------------------------------------------------------------------------
> **📶 CAN Bus & MCP2551 Transceiver**
 
> CAN is a multi-master, differential bus developed by Bosch.
> 
> MCP2551 connects the MCU’s CAN TX/RX pins to the CANH/CANL lines.
> 
> Converts logic levels to dominant/recessive signals on the bus.
> 
> ISO-11898 compliant; handles 5 V systems, up to 1 Mb/s data rates.
> 
> Maintains signal integrity during faults or interference.
> 
> Enables reliable, fast communication across all modules on the bus.

--------------------------------------------------------------------------------------------------------------
> **⚙️ Programming and Setup**
 
> 💻 Developing Firmware
 
> Write C code in Keil uVision (ARM MDK). Configure LPC2129 clock, peripheral pins, and CAN baud rate.
> 
> Implement sensor read routines (1-Wire, ADC), LCD updates, and CAN frame handling.


> 📥 Flashing the MCU
 
> Use Flash Magic (Windows PC) with the LPC’s UART.
> 
> Set correct COM port, baud rate (e.g. 9600 or 7200), and device settings.
> 
> Flash Magic uploads the compiled HEX file via the LPC’s built-in ISP bootloader.


> 🔌 Wiring
 
> Connect DS18B20 with a 4.7 kΩ pull-up resistor on its data line.
> 
> GP2D12 analog output → LPC ADC pin .
> 
> CANH/CANL lines pass through the MCP2551 (follow high-speed CAN wiring and grounding rules).
> 
> Place 120 Ω termination resistors at both ends of the CAN bus (some MCP2551 modules have built-in terminators).
> 
> Ensure LCD (RS, RW, E, D4–D7) lines are correctly wired to LPC GPIOs.
> 
> LEDs use current-limiting resistors and are driven by GPIOs (active LOW).
> 
> Reverse switch should pull a GPIO pin to ground when engaged.


> 🧪 Testing
 
> Power the system with 5 V and observe the LCD startup screen.
> 
> Confirm engine temperature is displayed and updates with actual changes.
> 
> Engage reverse gear and place an object <15 cm behind — the buzzer should sound and LCD display “WARNING”.
> 
> Send a test CAN frame with a window position value and verify LED bar and LCD update accordingly.


> ⚠️ Safety Note

> Verify all power connections and ensure a common ground across modules.
> 
> Check that the MCP2551 is powered with 5 V.
> 
> The LPC2129 operates at 3.3 V, so use a series resistor or logic level shifter if needed, unless the transceiver supports 3.3 V logic. 

--------------------------------------------------------------------------------------------------------------
> **📚 References**

> This system is based on widely used standard components and communication protocols. Key technical references include:

> LPC2129 Microcontroller Datasheet – ARM7-based MCU featuring dual CAN controllers and multiple peripheral interfaces.
> 
> 🔗 NXP Semiconductors

> DS18B20 Temperature Sensor – Digital thermometer supporting the 1-Wire protocol with programmable resolution (9–12 bits).
> 
> 🔗 Analog Devices (Maxim)

> MCP2551 CAN Transceiver – High-speed CAN transceiver for interfacing the microcontroller to the CAN bus.
> 
> 🔗 Microchip Technology

> CAN Bus Protocol Specification (Standard CAN, 11-bit Identifier) – Official protocol developed by Bosch for robust automotive communication.
> 
> 🔗 Bosch CAN Specification 2.0

> Sensor & LCD Integration Resources – Practical guides for interfacing GP2D12 IR sensors and creating custom LCD characters using CGRAM.
> 
> 🔗 PhiloHome – GP2D12 IR Sensor Guide
> 
> 🔗 Controllerstech – Custom Characters on LCD using CGRAM
