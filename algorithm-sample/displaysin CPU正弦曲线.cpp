// CPUÏÔÊ¾ÕıÏÒÇúÏß
void displaysine()
{
	long idletime = 500;
	long angle = 0;
	long interval = 2;
	while (TRUE)
	{
		double percentage = (sin(3.14159265358979323846*angle/180) + 1) / 2;

		int starttime = GetTickCount();
		while (GetTickCount() - starttime < idletime*percentage)
			;
		Sleep((DWORD)(idletime*(1-percentage)));	

		angle += interval;
		if (angle > 360)
			angle -= 360;

		cout << percentage << endl;
	}
}
