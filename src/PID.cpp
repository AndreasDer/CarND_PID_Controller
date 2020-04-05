#include "PID.h"

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
    this->Kd = Kd_;
    this->Ki = Ki_;
    this->Kp = Kp_;
    p_error = 0.0;
    i_error = 0.0;
    priv_cte = 0.0;
    sum_error = 0.0;
    d_error = 0.0;
    counter = 0;
}

void PID::UpdateError(double cte) {
    counter++;
    p_error = cte;
    i_error = cte - priv_cte;
    priv_cte = cte;
    sum_error += cte;
    d_error = sum_error / counter;
}

double PID::TotalError() {
    return -Kp * p_error - Kd * i_error - Ki * d_error;
}
