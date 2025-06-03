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

**🎛️ LPC2129 –** ARM7 MCU with CAN support

**🔄 MCP2551 –** CAN transceiver (1 Mb/s)

**🌡️ DS18B20 –** 1-Wire temperature sensor

**🔭 GP2D12 –** IR distance sensor (ADC input)

**📟 16×2 LCD –** Displays status and symbols

**💡 LEDs (×8) –** Show window position

**🔔 Buzzer –** Reverse alert

**⚡ Power & Extras –** 5 V supply, pull-ups, switches, terminators

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
