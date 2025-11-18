/*
 * Course: Arduino Power Consumption
 * Platform: Arduino
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Arduino Power Consumption" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (Arduino)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/arduino-power-consumption/
 * Repository: https://github.com/engasm89/arduino-power-consumption
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

// Model sleep/wake duty cycle and estimated current draw
#include <stdio.h> // Logs

static double estimate_current(double i_sleep, double i_active, double duty) { // Estimate mA
  return i_sleep * (1.0 - duty) + i_active * duty; // Weighted average
}

int main(void) { // Program entry point
  printf("Arduino Power Consumption\n"); // Title
  double i_sleep = 0.02; // mA in deep sleep
  double i_active = 20.0; // mA active
  double duty[] = {0.01, 0.05, 0.10}; // Duty cycles
  for (int i = 0; i < 3; ++i) { // Iterate
    double mA = estimate_current(i_sleep, i_active, duty[i]); // Estimate
    printf("duty=%.2f current=%.2fmA\n", duty[i], mA); // Log
  } // End loop
  return 0; // Exit
} // End of main function
