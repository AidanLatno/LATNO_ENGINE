#include "../declarations/DeveloperLog.h" 

DevLog::DevLog(std::string _name, std::string _fileType)
{
	name = _name;
	fileType = _fileType;
	fileName = name + "." + fileType;
	std::ofstream Constructor(fileName);
}
void DevLog::LOG(std::string message)
{
	LogFile.open(fileName);
	Logs.push_back(message);
	for (int i = 0; i < Logs.size(); i++)
	{
		LogFile << Logs[i];
	}
	LogFile.close();
}
void DevLog::LOGLN(std::string message)
{
	LogFile.open(fileName);
	Logs.push_back(message + "\n");
	for (int i = 0; i < Logs.size(); i++)
	{
		LogFile << Logs[i];
	}
	LogFile.close();
}