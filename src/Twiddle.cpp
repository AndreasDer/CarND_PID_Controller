#include "Twiddle.h"

Twiddle::Twiddle(){
	isInitialized = false;
}
Twiddle::~Twiddle(){}

void Twiddle::Init()
{

	for (int i = 0; i < 3; i++) {
		param[i] = 1;
	}
	for (int i = 0; i < 3; i++) {
		param_d[i] = 1;
	}
	counter = 0;
	error = 0.0;
	best_error = 0.0;
	param_iterator = 0;
	state = -1;
	isInitialized = true;
}

void Twiddle::setActive(bool state)
{
	this->active = state;
}

bool Twiddle::getActive()
{
	return this->active;
}

void Twiddle::change_state()
{
	switch (state)
	{
	case -1:
		state = 0;
	case 0:
		param_iterator%=3;
		param[param_iterator] += param_d[param_iterator];
		state=1;
		break;
	case 1:
		if (error < best_error) {
			best_error = error;
			param_d[param_iterator] *= 1.3;
			state = 0;
			param_iterator++;
		}
		else {
			param[param_iterator] -= 2 * param_d[param_iterator];
			state = 2;
		}
		break;
	case 2:
		if (error < best_error) {
			best_error = error;
			param_d[param_iterator] *= 1.3;
		}
		else {
			param[param_iterator] += param_d[param_iterator];
			param_d[param_iterator] *= 0.7;
		}
		state = 0;
		param_iterator++;
		break;
	}
}

void Twiddle::reset() {
	counter = 0;
	error = 0.0;
}