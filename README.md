# cpu-visualizer
This is an adafruit circuit playground project which utilizes serial communications to give a clear CPU visualization.

How it works?
===========
CPU Visualizer uses serial communications to get the cpu load from the desire computer. Then from the given cpu load, the arduino will accept it and use this function to calculate the delay:

![alt_text](https://github.com/lukashh6/cpu-visualizer/blob/master/client/graph.png?raw=true)

Compatibility
===========
Client Side
-----------
* Adafruit Circuit Playground

Server Side
-----------
Currently, CPU Visualizer only supports the following operating systems:
* Most of Linux distributions
* MAC

How to install
===========

Arduino Side (Client Side)
-----------
1. Copy 'client' folder to your computer.
2. Open the file inside the folder using the official arduino IDE.
3. Upload the code to your arduino.
4. Plug in to the usb port of your desire computer.

Any Compatible Machine (Server Side)
-----------
1. Copy 'server' folder to your desire computer.
2. Open a terminal in that folder.
3. Run the script inside the folder called 'setup.sh' using the following command: 
```bash 
./setup.sh
```
4. Then, if you want to run it, just run the script called 'run.sh' using the following command:
```bash
./run.sh
```
