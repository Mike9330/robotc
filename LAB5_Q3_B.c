#pragma config(Sensor, S1,     gyroSensor,     sensorEV3_Gyro)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#define DATA_SERIES_0 0
#define DATA_SERIES_1 1

float rate, movingAvgRate;
const int bufferSize = 5;
float avg;
float gyroBuffer[bufferSize];



void insertGyroBuffer(float var)
{
	int i;
	for(i = 0; i < bufferSize - 1; i++)
	{
		gyroBuffer[i] = gyroBuffer[i+1];
	}
	gyroBuffer[bufferSize - 1] = var;
}

float movingAvgCalc()
{
	int i;
	float sum=0;
	for(i = 0; i < bufferSize - 1; i++)
	{
		sum += gyroBuffer[i];
	}
	avg = (sum / 5);
	return avg;
}

task gyroTask()
{
	while(true)
	{
		rate = getGyroRate(gyroSensor) * (PI/180);
		insertGyroBuffer(rate);
		movingAvgRate = movingAvgCalc();
		datalogAddValue(DATA_SERIES_0,rate);
		datalogAddValue(DATA_SERIES_1,movingAvgRate);
	}

}


task main()
{
	startTask(gyroTask);
	while(true)
	{
		sleep(200);
	}


}