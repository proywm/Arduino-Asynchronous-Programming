# Asynchronous Timer Interrupt Example

This repository contains an Arduino sketch that demonstrates asynchronous programming using a timer interrupt. The code toggles the built-in LED every 1 second using the TimerOne library, while the main loop prints the current LED state to the Serial Monitor. This example showcases how an interrupt service routine (ISR) can decouple time-sensitive tasks from the main program flow, allowing the system to handle asynchronous events efficiently.

## Overview

- **Asynchronous Behavior:**  
  The sketch uses a timer interrupt to toggle the LED independently of the main loop. This means the LED toggle operation occurs even while the main loop is busy, illustrating a core concept of asynchronous programming.

- **Timer Interrupt:**  
  The TimerOne library is employed to generate an interrupt every 1 second. The ISR (`toggleLED()`) is attached to this interrupt and updates the LED state.

- **Serial Output:**  
  The main loop prints the LED state (ON/OFF) every second to the Serial Monitor, providing real-time feedback.

## Prerequisites

- **Hardware:**  
  An Arduino board (e.g., Arduino Uno) with a built-in LED (usually connected to the pin defined as `LED_BUILTIN`).

- **Software:**  
  - [Arduino IDE](https://www.arduino.cc/en/software)
  - [TimerOne Library](https://github.com/PaulStoffregen/TimerOne) (Install via the Arduino Library Manager)

## Installation

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/yourusername/async-timer-interrupt-example.git
   cd async-timer-interrupt-example
   ```

2. **Open the Sketch:**

   Open the `AsyncTimerInterruptExample.ino` file in the Arduino IDE.

3. **Install the TimerOne Library:**

   In the Arduino IDE, navigate to `Sketch > Include Library > Manage Libraries...`. Search for "TimerOne" and install it if you haven't already.

4. **Upload the Sketch:**

   Connect your Arduino board, select the appropriate board and port from `Tools`, and upload the sketch.

## Code Explanation

### Interrupt Service Routine (ISR):

The `toggleLED()` function is declared as the ISR. It toggles the `ledState` and updates the built-in LED accordingly. Because this function is called by the hardware timer, it operates asynchronously relative to the `loop()` function.

### Setup Function:

- Configures the built-in LED as an output.
- Starts Serial communication at 9600 baud.
- Initializes TimerOne to generate an interrupt every 1 second and attaches the ISR.

### Loop Function:

- Prints the current LED state to the Serial Monitor every second.
- Demonstrates that the main loop continues to run independently while the ISR manages the LED toggling.

## How to Use

### Upload the Code:

Once you have uploaded the sketch to your Arduino board, open the Serial Monitor in the Arduino IDE to view the LED state messages.

### Observe the Behavior:

- The built-in LED will toggle every second, managed by the timer interrupt.
- The Serial Monitor will print "LED is ON" or "LED is OFF" every second, reflecting the current state of the LED.

## Understanding Asynchronous Programming

This example highlights the advantage of asynchronous programming in microcontroller applications:

### Decoupling Tasks:

The LED toggling happens in the background via an interrupt, meaning the main loop can perform other tasks without waiting for the LED toggle to complete.

### Efficient Resource Utilization:

By handling the LED toggle asynchronously, the microcontroller can remain responsive, and the CPU is not blocked by long wait times.

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.

## Acknowledgments

- The TimerOne library for simplifying the use of hardware timers on Arduino.
- The Arduino community for continuous support and development of asynchronous programming techniques in embedded systems.
