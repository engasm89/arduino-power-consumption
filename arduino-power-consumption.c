// Model sleep/wake duty cycle and estimated current draw
#include <stdio.h> // Logs

static double estimate_current(double i_sleep, double i_active, double duty) { // Estimate mA
  return i_sleep * (1.0 - duty) + i_active * duty; // Weighted average
}

int main(void) { // Entry
  printf("Arduino Power Consumption\n"); // Title
  double i_sleep = 0.02; // mA in deep sleep
  double i_active = 20.0; // mA active
  double duty[] = {0.01, 0.05, 0.10}; // Duty cycles
  for (int i = 0; i < 3; ++i) { // Iterate
    double mA = estimate_current(i_sleep, i_active, duty[i]); // Estimate
    printf("duty=%.2f current=%.2fmA\n", duty[i], mA); // Log
  } // End loop
  return 0; // Exit
} // End main
