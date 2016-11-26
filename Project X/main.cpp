#include <iostream>
#include"Figures.h"
#include <conio.h>
#include "Logger.h"
#include <string>

int main()
{
	CLogger::GetLogger()->Log("Game started");
	try
	{

	}
	catch (...)
	{
		CLogger::GetLogger()->Log("Unknown error!");
		std::cerr << "Unknown error!";
	}

	_getch();
	return 0;
}