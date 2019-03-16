#ifndef JEFFREY_H_
#define JEFFREY_H_

#include "MyRio.h"

class Jeffrey {
private:
	Motor_Controller mc;

	/*
	 * The number of degree to turn the (4" / 31.9cm) wheel forward one centimenter
	 *  Formula used : 360/31.918581360472
	 */
	static constexpr double WHEEL_DEGREE_CM = 11.2786968;

public:
    Jeffrey();
    ~Jeffrey();
    NiFpga_Status init(NiFpga_Session* myrio_session);
    void reset();

	void moveForwardCM(int cm, int speed);

};

#endif