#pragma config(Sensor, S1,     colorSensor,    sensorEV3_Color)
#pragma config(Sensor, S2,     rangeSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

float threshold = 31;
int k = 2;
int maxVal = 67;
float changeDirection = (k * getColorReflected(colorSensor) - threshold);
float currentPower = 20;


task controller(){																														//line following similar to lab 6
	while(true){

		if(getUSDistance(rangeSensor) > 15){
			changeDirection = k * (getColorReflected(colorSensor) - threshold);
			if(getColorReflected(colorSensor) > maxVal -10){
				k = 3;
			}
			else{
				k = 1;
			}

			setMotorSync(rightMotor, leftMotor, changeDirection, currentPower);
		}
		else
		{
			setMotorSpeed(leftMotor, 15);																							//turn
			setMotorSpeed(rightMotor, -15);
			sleep(1000);

			setMotorSpeed(leftMotor, 30);																							//move forward
			setMotorSpeed(rightMotor, 30);
			sleep(1700);

			setMotorSpeed(leftMotor, -15);																						//turn again
			setMotorSpeed(rightMotor, 15);
			sleep(1200);


			while(getColorReflected(colorSensor) > threshold){												//move until line detected again
				setMotorSync(leftMotor, rightMotor, 0, 20);
			}
		}
	}
}

task main(){
	startTask(controller);
	while(true){
		sleep(100);
	}
}
