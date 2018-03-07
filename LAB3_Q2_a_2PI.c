#pragma config(Motor,  motorB,          LEFT,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          RIGHT,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard

const float speed = 40.0, angleBeta = 2*PI, trackWidth = 120.0, diameter = 58.0, distanceS = trackWidth/2 * angleBeta;
float angleU = 0;


task turnRightMotor(){

	angleU = (distanceS *(2/diameter))*(180/PI);
	setMotorSyncEncoder(RIGHT,LEFT,-100,angleU,speed);

}// end of turnRightMotorTask



task main()
{
		while(true){
			startTask(turnRightMotor);
			sleep(1000);
		}
}// end of main()
