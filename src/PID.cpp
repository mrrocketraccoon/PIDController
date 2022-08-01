#include "PID.h"

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
  d_error = 0;
  prev_error = 0;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
  p_error = cte;
  i_error += cte;
  d_error = cte-prev_error;
  prev_error = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  double error = Kp*p_error + Ki*i_error + Kd*d_error; 
  if(error > 1)
  {
    return 1.0;
  }
  else if(error < -1)
  {
    return -1.0;
  }
  return error;  // TODO: Add your total error calc here!
}
