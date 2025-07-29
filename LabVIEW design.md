\# 💻 LabVIEW Design for Smart Environmental Monitoring



This document explains how LabVIEW is used to visualize the environmental data from Arduino.



\## 🎯 Purpose



To visualize temperature, humidity, and light data received over serial communication from an Arduino-based monitoring system.



\## 🔧 Block Diagram Description



\- \*\*VISA Configure Serial Port\*\*: Initializes communication with the Arduino.

\- \*\*VISA Read\*\*: Continuously reads incoming data.

\- \*\*String Manipulation\*\*: Splits serial string using comma delimiters.

\- \*\*Numeric Conversions\*\*: Converts string values to numeric for display.

\- \*\*Numeric Indicators\*\*:

&nbsp; - Temperature (°C)

&nbsp; - Humidity (%RH)

&nbsp; - Light Intensity (LUX)



\## 📈 Front Panel Design



🔹 Elements to Include:



Component	                  Type	                      Purpose

Temperature Indicator	      Numeric Indicator      	Displays temperature (°C)

Humidity Indicator	      Numeric Indicator	        Displays humidity (%)

Light Intensity Indicator     Numeric Indicator  	Displays LDR output (arbitrary or lux)

Waveform Chart	                  Graph	              Shows trend of temp, humidity, and light





**## Back Panel (Block Diagram)**



**🔹 Step-by-Step Logic Flow:**



**VISA Configure Serial Port**



**Configure COM port (e.g., COM3, baud rate 9600).**



**Set timeout and termination character.**



**While Loop**



**Keeps reading data continuously.**



**VISA Read**



**Reads the serial string sent from Arduino (e.g., "28.4,61.2,460").**



**String to Array**



**Use "Spreadsheet String to Array" function.**



**Set delimiter to comma ,.**



**Array Indexing**



**Index 0 → Temperature**



**Index 1 → Humidity**



**Index 2 → Light Intensity**



**String to Number**



**Convert each string value to numeric.**



**Indicators**



**Connect to respective numeric displays.**



**Waveform Chart**



**Bundle all 3 values and wire to chart.**



\## 🔢 Data Format from Arduino



LabVIEW expects the following serial format:
25.3,48.6,210

Where:
- `25.3` = Temperature
- `48.6` = Humidity
- `210` = Light Intensity