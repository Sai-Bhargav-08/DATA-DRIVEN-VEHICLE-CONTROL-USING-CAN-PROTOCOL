 **🚗 CAN-Based Vehicle Control System (LPC2129)**

> A compact vehicle control system using CAN protocol on the LPC2129 ARM7 microcontroller. It monitors engine temperature, provides a reverse alert, and shows window position—all coordinated over a CAN bus using MCP2551 transceivers.

--------------------------------------------------------------------------------------------------------------
**🔧 Key Features**

> 🌡️ Engine Temperature Monitoring: Utilizes the DS18B20 sensor to display real-time engine temperature on the dashboard LCD.
> 
> 🪟 Window Control & Display: Adjusts window levels (0–8) via dashboard switches, with status broadcasted over CAN. Visual feedback provided through 8 active-low LEDs and a custom LCD icon.
> 
> 🔁 Direction Toggle: Switch between Forward and Reverse modes using a dedicated dashboard switch, with direction status displayed on the LCD.
>
> 🔙 Reverse Alert: In Reverse mode, receives distance data from the Reverse Alert Node via CAN. If an obstacle is detected within 15 cm, activates a buzzer and displays a warning symbol on the LCD.
>
> 📶 Robust CAN Communication: Employs MCP2551 transceivers and LPC2129 controllers to ensure reliable, high-speed (1 Mb/s) communication across all nodes.

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
 
**🧭 Dashboard Node**

> 🌡️ Reads engine temp via DS18B20 (1-Wire, parasite mode)
> 
> 📟 LCD shows temp & vehicle direction
>
> 🔼 SW1 / 🔽 SW2: Adjust window, send level via CAN
> 
> >📤 Sends window level status via CAN
> 
> 🔁 SW3: Toggle direction (FWD/REV)
>
> 🛎️ Switches use external interrupts
>
>
> 🔙 In Reverse mode:
> 
> >  📥 Gets distance data from CAN (sent by Reverse Alert Node)
>
> > 📟 Displays obstacle distance on LCD
>
> > 🚨 If <15 cm: buzzer + warning symbol

**🔙Reverse Alert Node**:

> Continuously reads distance using GP2D12
> 
> Sends distance data to Dashboard Node via CAN(dis > 5cm and dis < 81cm)

**🪟 Window Display Node:**

> This Node receives 0–8 level via CAN
> 
> Window Node lights 0–8 active-low LEDs
> 
> Dashboard LCD displays window icon using CGRAM
>
📶CAN Communication:

> MCP2551 handles bus signaling
> 
> LPC2129 CAN controller manages frames
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
