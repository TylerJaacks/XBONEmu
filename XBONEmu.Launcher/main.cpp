#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>


int main(int argc, char* argv[])
{	
	if (argc != 3)
	{
		printf("Usage XBONEmu.Launcher.exe -executable <PATH_TO_EXECUTABLE>");
	}

	std::string executablePath = argv[2];

	

	return 0;
}

void loadPEImage(std::string executablePath)
{
	
}