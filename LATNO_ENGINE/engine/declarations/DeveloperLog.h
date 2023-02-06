// INCLUDE IN ENGINE HEADERS
#pragma once

#include <fstream>
#include <string>
#include <vector>

static std::vector<std::string> StaticLogs;
static int RepititionCounter = 0;

class DevLog
{
public:
	std::string name;
	std::string fileType;
	std::string fileName;
	std::vector<std::string> Logs;
	std::fstream LogFile;

	DevLog(std::string _name, std::string _fileType = "txt");
	void LOG(std::string message);
	void LOGLN(std::string message);
	static inline void LOG(std::string message, std::string file)
	{
		if (StaticLogs.size() >= 1 && StaticLogs[StaticLogs.size() - 1] == message)
			RepititionCounter++;
		else
			RepititionCounter = 0;

		std::ofstream Constructor(file + ".txt");
		std::fstream StaticLogFile;
		StaticLogFile.open(file + ".txt");
		if (RepititionCounter == 0)
			StaticLogs.push_back(message);
		for (int i = 0; i < StaticLogs.size(); i++)
		{
			StaticLogFile << StaticLogs[i];
		}
		if (RepititionCounter > 0)
			StaticLogFile << "\nLog above repeated " + std::to_string(RepititionCounter) + " times";
		StaticLogFile.close();
	}
	static inline void LOGLN(std::string message, std::string file)
	{
		if (StaticLogs.size() >= 1 && StaticLogs[StaticLogs.size() - 1] == message + '\n')
			RepititionCounter++;
		else
			RepititionCounter = 0;

		std::ofstream Constructor(file + ".txt");
		std::fstream StaticLogFile;
		StaticLogFile.open(file + ".txt");
		if (RepititionCounter == 0)
			StaticLogs.push_back(message + '\n');
		for (int i = 0; i < StaticLogs.size(); i++)
		{
			StaticLogFile << StaticLogs[i];
		}
		if (RepititionCounter > 0)
			StaticLogFile << "Log above repeated " + std::to_string(RepititionCounter) + " times";
		StaticLogFile.close();

	}
};