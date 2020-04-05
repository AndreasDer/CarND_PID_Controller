#ifndef TWIDDLE_H
#define TWIDDLE_H

#define MAX_CYCLES 3000

class Twiddle {
public:
	Twiddle();
	virtual ~Twiddle();
	void Init();
	void reset();
	void setActive(bool state);
	bool getActive();
	void change_state();
	bool isInitialized;
	int counter;
	int param_iterator;
	double error;
	double best_error;
	double param[3];
	double param_d[3];
	int state;
private:
	bool active;
};
#endif // !TWIDDLE_H
