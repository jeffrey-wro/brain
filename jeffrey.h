#ifndef JEFFREY_H_
#define JEFFREY_H_

#include "MyRio.h"

class Jeffrey {
private:
	Motor_Controller mc;

public:
    Jeffrey();
    ~Jeffrey();
    NiFpga_Status init(NiFpga_Session* myrio_session);
    void reset();

	void moveForwardCM(int cm);

};

#endif