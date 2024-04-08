# Project Title: UART Serial Communication between PC and MCU

This project demonstrates the use of UART serial communication between a PC and an MCU to transmit and receive data. The Python script running on the PC sends data to the MCU, which then sends data back to the PC. I have used an MCU consisting of Atmega328P.

## Requirements

- Arduino UNO board
- USB cable for connecting the Arduino UNO to the PC
- Python 3.9.7 or above installed on the PC
- PySerial library installed on the PC

## Embedded c++ Code

The Embedded code is written in C/C++ and can be uploaded to the MCU board. The code sets up the serial communication at a baud rate of 2400 and listens for incoming data from the PC. When data is received, it is stored in the EEPROM memory of the MCU. When the stored data is read, it is sent back to the PC. **I have directly accessed the EEPROM registers than using the inbuilt header file or any ready-made libraries of EEPROM to read and write data on EEPROM**

## Python Script

The Python script reads data from a binary file named `Data.txt` and transmits it to MCu. It then receives data from the MCU and prints it to the console. The script also calculates the transmission and receiving speeds in real-time.

## Usage

1. Connect the MCU to the PC using a USB cable.
2. Open the `Data.txt` file in binary mode and ensure it contains data to be transmitted.
3. Run the Python script.
4. The script will transmit the data to MCU and print the transmission speed.
5. The MCU will store the received data in its EEPROM memory and send an acknowledgment back to the PC.
6. The Python script will receive the acknowledgment and print the receiving speed.
7. The MCU will then send the stored data back to the PC.
8. The Python script will receive the data and print it to the console.
9. The script will print the receiving speed again.




