// INCLUDE IN ENGINE HEADERS
#include <fstream>
#include <string>
#include <vector>

extern std::fstream LogFile;
extern std::vector<std::string> Logs;
extern bool IsOpen = true;


void CREATE_LOG(std::string FileName)
{
	std::ofstream Constructor(FileName);
}

void CLOSE_LOG()
{
	IsOpen = false;
}

void OPEN_LOG()
{
	IsOpen = true;
}

// MUST CREATE A LOG BEFORE LOGGING
void LOG(std::string Message, std::string FileName = "MainLog.txt")
{
	if(IsOpen)
	{
		LogFile.open(FileName);
		Logs.push_back(Message);
		for(int i = 0; i < Logs.size(); i++)
		{
			LogFile << Logs[i];
		}
		LogFile.close();
	}
}
void LOGLN(std::string Message, std::string FileName = "MainLog.txt")
{
	if(IsOpen)
	{
		LogFile.open(FileName);
		Logs.push_back(Message + "\n");
		for(int i = 0; i < Logs.size(); i++)
		{
			LogFile << Logs[i];
		}
		LogFile.close();
	}
}