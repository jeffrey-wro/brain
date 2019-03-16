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


void Jeffrey::moveForwardCM(int cm, int speed){

	int degree = WHEEL_DEGREE_CM * cm;
	int degree1 = degree+mc.readEncoderDegrees(DC, DC_1);
	int degree2 = -degree+mc.readEncoderDegrees(DC, DC_2);

	mc.setMotorDegrees(DC, speed, degree1, speed, degree2);

	//TODO maybe make a timeout
	while(mc.readEncoderDegrees(DC, DC_1) != degree1 ){
		Utils::waitForMicro(50000);
		printf("%d\n", degree1);
		printf("%d\n\n", mc.readEncoderDegrees(DC, DC_1));
	}
	Utils::waitForMicro(50000);
	while(mc.readEncoderDegrees(DC, DC_2) != degree2 ){
		Utils::waitForMicro(50000);
		printf("%d\n", degree2);
		printf("%d\n\n", mc.readEncoderDegrees(DC, DC_2));
	}

}
