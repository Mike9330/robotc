#pragma config(Sensor, S1,     colorSensor,    sensorEV3_Color)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//


//int leftPower, rightPower = 10;
float threshold = 31;
int k = 2;
int maxVal = 67;
float changeDirection = (k * getColorReflected(colorSensor) - threshold);
float currentPower = 8;


task followLine(){
	while(true){
				changeDirection = k * (getColorReflected(colorSensor) - threshold);
				if(getColorReflected(colorSensor) > maxVal -10){
					k = 3;
				}
				else{
					k = 1;
				}
		}

}
task main(){
	startTask(followLine);
	while(true){
		setMotorSync(rightMotor, leftMotor, changeDirection, currentPower);

	}
}