
task main()
{

	while(true){
		int x1 = ((rand() % 6) - 3);
		int x2 = ((rand() % 6) - 3);
		int y1 = ((rand() % 6) - 3);
		int y2 = ((rand() % 6) - 3);
		drawEllipse(x1,x2,y1,y2);
		if(x1 > 177)
		{
				playSound(soundBlip);
				sleep(100);
			  eraseEllipse(x1,y1,x2,y2);
			  sleep(100);
			  drawEllipse(x1,x2,y1,y2);

		}
		if(x2 > 177)
		{
				playSound(soundBlip);
				sleep(100);
				eraseEllipse(x1,y1,x2,y2);
				sleep(100);
				drawEllipse(x1,x2,y1,y2);
		}
		if(x1 < 0)
		{
				playSound(soundBlip);
				sleep(100);
			  	eraseEllipse(x1,y1,x2,y2);
			  	sleep(100);
			  	drawEllipse(x1,x2,y1,y2);
		}
			if(x2 < 0)
		{
				playSound(soundBlip);
				sleep(100);
				eraseEllipse(x1,y1,x2,y2);
				sleep(100);
				drawEllipse(x1,x2,y1,y2);
		}
		if(y1 > 127)
		{
			playSound(soundBlip);
			sleep(100);
			eraseEllipse(x1,y1,x2,y2);
			sleep(100);
			drawEllipse(x1,x2,y1,y2);
		}
		if(y2 > 127)
		{
			playSound(soundBlip);
			sleep(100);
			eraseEllipse(x1,y1,x2,y2);
			sleep(100);
			drawEllipse(x1,x2,y1,y2);
		}
			if(y1 < 0)
		{
			playSound(soundBlip);
			sleep(100);
			eraseEllipse(x1,y1,x2,y2);
			sleep(100);
			drawEllipse(x1,x2,y1,y2);
		}
			if(y2 < 0)
		{
			playSound(soundBlip);
			sleep(100);
			eraseEllipse(x1,y1,x2,y2);
			sleep(100);
			drawEllipse(x1,x2,y1,y2);
		}
		sleep(100);
		eraseEllipse(x1,y1,x2,y2);
}

}
