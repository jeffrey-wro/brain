#include "MyRio.h"
#include "I2C.h"
#include "Motor_Controller.h"
#include "Utils.h"

#include "jeffrey.h"

Jeffrey::Jeffrey(){	

}
Jeffrey::~Jeffrey(){

}

NiFpga_Status Jeffrey::init(NiFpga_Session* myrio_session){

	NiFpga_Status status = mc.init(myrio_session);
	mc.controllerEnable(DC);

	int volt = mc.readBatteryVoltage(1);
	printf("Battery: %.02fv\n\n", volt/100.0);

	return status;
}

void Jeffrey::reset(){
	Utils::waitFor(2);
	mc.controllerReset(DC);
}


void Jeffrey::moveForwardCM(int cm){

	printf("Jeffrey move forward\n");
	fflush(stdout);

	mc.setMotorSpeeds(DC, 50, -50);

}