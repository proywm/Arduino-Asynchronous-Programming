/*
  Asynchronous Timer Interrupt Example
  --------------------------------------
  This sketch demonstrates asynchronous programming using a timer interrupt.
  The built-in LED is toggled every 1 second by a timer interrupt (via TimerOne),
  independent of the main loop. Meanwhile, the main loop prints the LED state every second.
*/

#include <TimerOne.h>  // Include the TimerOne library for timer interrupts

// Declare a volatile variable for the LED state since it is modified inside an ISR.
volatile bool ledState = false;

// Interrupt Service Routine (ISR) to toggle the LED state.
// This function is called automatically every 1 second by TimerOne.
void toggleLED() {
  ledState = !ledState;                 // Toggle the LED state
  digitalWrite(LED_BUILTIN, ledState);   // Update the built-in LED with the new state
}

void setup() {
  // Initialize the built-in LED as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  // Start Serial communication at 9600 baud for debugging purposes.
  Serial.begin(9600);
  // Wait for the Serial port to connect (useful for boards with native USB, like Leonardo).
  while (!Serial) {
    ; // Do nothing until Serial is connected.
  }

  Serial.println("Asynchronous Timer Interrupt Example Started");

  // Initialize TimerOne with a period of 1,000,000 microseconds (1 second).
  Timer1.initialize(1000000);
  // Attach the toggleLED function to the TimerOne interrupt.
  Timer1.attachInterrupt(toggleLED);
}

void loop() {
  // Print the current LED state to the Serial Monitor.
  Serial.print("LED is ");
  Serial.println(ledState ? "ON" : "OFF");
  
  // Wait for 1 second before printing again.
  delay(1000);
}
