#include "PID.h"
#include <iostream>
#include <math.h>       /* fabs */
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
   Kp = Kp_;
   Ki = Ki_;
   Kd = Kd_;
}
double PID::CalculateValue(){
    return -(Kp * p_error + Kd * d_error + Ki * i_error);
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
   d_error = cte - p_error;
   p_error = cte;
   i_error += cte;
   total_error += cte * cte;

}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */

  return total_error;  // TODO: Add your total error calc here!
}
