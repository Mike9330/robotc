#pragma config(Sensor, S1,     ultrasound,     sensorEV3_Ultrasonic)
#pragma config(Motor,  motorB,          left,          tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          right,         tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int desiredPower;
long currentPower;
float error;
int desiredDistance = 30;
const float maxDistance = 60;
const int K = 2;
const int slewRate = 5;
const float tolerance = 2;
float currentDistance=0;



task controllerTask()
{
	while(true)
	{
		//calculate desired power
		error = desiredDistance - currentDistance;
		if (abs(error) > tolerance)
		{
			desiredPower = K * error;
		}
		else
		{
			currentPower = 0;
			desiredPower = 0;
		}
		//calculate current power
		if (currentDistance < desiredDistance)
		{
			if(currentPower + slewRate < -(desiredPower))
			{
				currentPower += slewRate;
			}
			else
			{
				if(currentPower - slewRate > -(desiredPower))
				{
					currentPower -= slewRate;
				}
			}
		}
		else if(currentDistance > desiredDistance && currentDistance < maxDistance)
		{
			if(currentPower + slewRate <	-(desiredPower))
			{
				currentPower += slewRate;
			}
			else
			{
				if(currentPower - slewRate > -(desiredPower))
				{
					currentPower -= slewRate;
				}
			}
		}
		else
		{
			currentPower = 0;
		}
		sleep(100);
	}
}
task displayTask()
{
	while(true)
	{
		currentDistance = getUSDistance(ultrasound);
		displayBigTextLine(3,"Distance:");
		displayBigTextLine(5,"%d", currentDistance);
		sleep(10);
	}
}

task main()
{
	sensorReset(ultrasound);
	startTask(displayTask);
	startTask(controllerTask);
	while(true){
		setMotorSync(right, left, 0, currentPower);
	}
}
