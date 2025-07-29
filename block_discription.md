
The Block Diagram handles data acquisition, parsing, and output logic.

Key Components in the Block Diagram:


VISA Configure Serial Port	
Initializes serial communication with Arduino (usually COM3, 9600 bps)


While Loop	
Continuously reads data from Arduino until stopped


VISA Read	
Reads serial data string like: "29.4,65.0,540"


"Split String" or "Scan From String"	
Converts comma-separated string into three numeric values.


Numeric Outputs	
Each value is sent to its corresponding indicator.


Waveform Chart	
Bundles and plots the three values over time.


Stop Condition	
Linked to Stop Button to exit loop.

Sample Data Format (From Arduino via Serial):

29.4,65.0,540

29.4 → Temperature (°C)

65.0 → Humidity (%)

540 → Light Intensity (0–1023 from LDR)



