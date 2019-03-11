#include <vector>
#include <iostream>

#include <stdio.h>

#include "MyRio.h"
#include "I2C.h"
#include "Motor_Controller.h"
#include "Utils.h"

#include "opencv2/core.hpp"

#include "ImageSender.h"
#include "Ultrasonic.h"

using namespace std;
using namespace cv;


extern NiFpga_Session myrio_session;
NiFpga_Status status;

int main(int argc, char **argv) {
	
	status = MyRio_Open();
	if (MyRio_IsNotSuccess(status)) {
		return status;
	}

	MyRio_I2c i2c;
	status = Utils::setupI2CB(&myrio_session, &i2c);

	Motor_Controller mc = Motor_Controller(&i2c);
	mc.controllerEnable(DC);

	int volt = mc.readBatteryVoltage(1);
	printf("%d\n\n", volt);

	




	
	Utils::waitFor(2);
	mc.controllerReset(DC);

	status = MyRio_Close();

	return status;
}
