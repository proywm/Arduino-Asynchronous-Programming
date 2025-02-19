#include "NRF52_MBED_TimerInterrupt.h"

#define TIMER_INTERVAL_MS 1000  // 1-second timer interval

NRF52_MBED_Timer ITimer(NRF_TIMER_1);  // Use hardware Timer 1
volatile bool ledState = false;

void toggleLED() {
  ledState = !ledState;
  digitalWrite(LED_BUILTIN, ledState);
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);

  Serial.println("Asynchronous Timer Interrupt Example Started");

  // Initialize the hardware timer for a 1-second interrupt
  if (ITimer.attachInterruptInterval(TIMER_INTERVAL_MS * 1000, toggleLED)) {
    Serial.println("Timer started successfully");
  } else {
    Serial.println("Timer failed to start");
  }
}

void loop() {
  Serial.print("LED is ");
  Serial.println(ledState ? "ON" : "OFF");
  delay(1000);
}
