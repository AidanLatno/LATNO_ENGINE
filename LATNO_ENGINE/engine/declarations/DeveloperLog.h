// INCLUDE IN ENGINE HEADERS
#include <fstream>
#include <string>
#include <vector>

static std::vector<std::string> StaticLogs;

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
		std::ofstream Constructor(file + ".txt");
		std::fstream StaticLogFile;
		StaticLogFile.open(file + ".txt");
		StaticLogs.push_back(message);
		for (int i = 0; i < StaticLogs.size(); i++)
		{
			StaticLogFile << StaticLogs[i];
		}
		StaticLogFile.close();
	}
	static inline void LOGLN(std::string message, std::string file)
	{
		std::ofstream Constructor(file + ".txt");
		std::fstream StaticLogFile;
		StaticLogFile.open(file + ".txt");
		StaticLogs.push_back(message + '\n');
		for (int i = 0; i < StaticLogs.size(); i++)
		{
			StaticLogFile << StaticLogs[i];
		}
		StaticLogFile.close();

	}
};