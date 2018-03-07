#pragma config(Sensor, S1,     touchSensor,    sensorEV3_Touch)
#pragma config(Sensor, S2,     gyroSensor,     sensorEV3_Gyro, modeEV3Gyro_RateAndAngle)
#pragma config(Sensor, S3,     colorSensor,    sensorEV3_Color, modeEV3Color_Color)
#pragma config(Sensor, S4,     sonarSensor,    sensorEV3_Ultrasonic)
#pragma config(Motor,  motorA,          armMotor,      tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, driveLeft, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, driveRight, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Global Variables
int motorControlTaskDelay = 1;
int slewRate = 1;
int increment = slewRate * motorControlTaskDelay;
int currentPowerLeft = 0;
int currentPowerRight = 0;
int	desiredPowerLeft = 50;
int desiredPowerRight =50;
//int desiredLeft = (abs(rand()) % 100 + 1);
//int desiredRight = (abs(rand()) % 100 + 1);


// Motor Control Task Left
task motorControlTaskLeft()
{

	while(true)
	{

		if(currentPowerLeft != desiredPowerLeft)
		{
			if(currentPowerLeft < desiredPowerLeft)
			{
				if(currentPowerLeft + increment > desiredPowerLeft)
				{
					currentPowerLeft = desiredPowerLeft;
					sleep(300);
				}
				else
				{
					currentPowerLeft += increment;
					sleep(300);
				}
			}
			else
			{
				if(currentPowerLeft - increment < desiredPowerLeft)
				{
					currentPowerLeft = desiredPowerLeft;
					sleep(300);
				}
				else
				{
					currentPowerLeft -= increment;
					sleep(300);
				}
			}
		}
	} //End of while loop
}

task motorControlTaskRight()
{

	while(true)
	{

		if(currentPowerRight != desiredPowerRight)
		{
			if(currentPowerRight < desiredPowerRight)
			{
				if(currentPowerRight + increment > desiredPowerRight)
				{
					currentPowerRight = desiredPowerRight;
					sleep(300);
				}
				else
				{
					currentPowerRight += increment;
					sleep(300);
				}
			}
			else
			{
				if(currentPowerRight - increment < desiredPowerRight)
				{
					currentPowerRight = desiredPowerRight;
					sleep(300);
				}
				else
				{
					currentPowerRight -= increment;
					sleep(300);
				}
			}
		}
	} //End of while loop
}

task main()
{
	//int currentPowerLeft = currentPower;
	//int currentPowerRight = currentPower;

	StartTask( motorControlTaskLeft);
	StartTask( motorControlTaskRight);
	while(true)
	{
			setMotorSpeed(leftMotor, currentPowerLeft);
			setMotorSpeed(rightMotor, currentPowerRight);

			if(currentPowerLeft == desiredPowerLeft && currentPowerRight == desiredPowerRight)
			{
				desiredPowerLeft = (abs(rand()) % 100 + 1) ;
				desiredPowerRight = (abs(rand()) % 100 + 1);

			}

			displayBigTextLine(5, "%d / %d", currentPowerLeft, desiredPowerLeft);
			sleep(1000);
			displayBigTextLine(10, "%d / %d", currentPowerRight, desiredPowerRight);
			sleep(1000);
	}







}
