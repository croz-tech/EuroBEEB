# EuroBEEB
Re-creation of the Control Universal EuroBEEB. EuroBEEB was an Acorn BBC Micro-compatible embedded controller from the early-mid 1980s of the Eurocard format (160mm x 100mm). A standard DIN 41612 bus connector makes the CPU card compatible with the CUBE range of Eurocards.  For a comprehensive background and writeup see https://croz.co.uk/vintage-computer-robot-collection/control-universal-eurobeeb/

![Finished populated EuroBEEB.jpg](https://github.com/croz-tech/EuroBEEB/blob/main/Finished%20populated%20EuroBEEB.jpg)

# Features
* 6502 CPU
* on-board real-time calendar clock
* a VIA I/O chip providing 16 I/O channels,
4 control lines and 2 timers
* CUBE/ACORN bus
* four reconfigurable 28—pin memory sockets that take RAM or ROM up to 16 kB per device
* choice of memory maps
* battery back-up for the real-time clock and any CMOS RAM on board
* RS-423 serial interface (RS-232 compatible) * RS-422 option for noisy environments
* Auto-run feature allowing Turnkey operation (automatic power-up and run)

# Machine Operating System
The machine operating system used in EuroBEEB provides a software environment similar to that of the BBC Micro and can support BBC BASIC (or other languages) if required. In addition the MOS contains the peripheral drivers (software to drive cards such as the Teletext card) and Control BASIC (an extension of BBC BASIC which provides BASIC-type commands for analog and digital I/O). 

# Evolution
The design is based on the Issue 7 EuroBEEB with a few further improvements:
* Replacement of the IC9/10 PROMs with more readily available GAL16V8 devices
* Addition of an optional pull-up resistor to BUSY+ to avoid modifications at the terminal/BBC
* Option to fit a lithium coin cell in place of the NiMh B1, to avoid leakage risk
