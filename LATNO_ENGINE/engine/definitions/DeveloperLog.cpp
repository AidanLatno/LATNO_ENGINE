#include "../declarations/DeveloperLog.h" 
namespace Latno
{
	DevLog::DevLog(std::string _name, std::string _fileType)
	{
		name = "Logs/" + _name;
		fileType = _fileType;
		fileName = name + "." + fileType;
		std::ofstream Constructor(fileName);
	}
	void DevLog::LOG(std::string message)
	{
		if (Logs.size() >= 1 && Logs[Logs.size() - 1] == message)
			RepititionCounter++;
		else
			RepititionCounter = 0;

		LogFile.open(fileName);
		if (RepititionCounter == 0)
			Logs.push_back(message);
		for (int i = 0; i < Logs.size(); i++)
		{
			LogFile << Logs[i];
		}
		if (S_RepititionCounter > 0)
			LogFile << "\nLog above repeated " + std::to_string(RepititionCounter) + " times";
		LogFile.close();
	}
	void DevLog::LOGLN(std::string message)
	{
		if (Logs.size() >= 1 && Logs[Logs.size() - 1] == message + '\n')
			RepititionCounter++;
		else
			RepititionCounter = 0;

		LogFile.open(fileName);
		if (RepititionCounter == 0)
			Logs.push_back(message + "\n");
		for (int i = 0; i < Logs.size(); i++)
		{
			LogFile << Logs[i];
		}
		if (S_RepititionCounter > 0)
			LogFile << "\nLog above repeated " + std::to_string(RepititionCounter) + " times";
		LogFile.close();
	}
	void DevLog::CLEAR()
	{
		Logs.clear();
		std::ofstream file(fileName + fileType);
	}
}