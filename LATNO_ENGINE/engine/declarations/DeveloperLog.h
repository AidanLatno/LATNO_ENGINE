// INCLUDE IN ENGINE HEADERS
#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>

static int S_RepititionCounter = 0; // Counts number of times the last line has been repeated
namespace Latno
{
	/*
	* Class Name: DevLog
	* Usage: Writes to and creates files for logging purposes. DO NOT USE EVERY FRAME. Limit usage as the class is very slow.
	* 
	* Constructor: Requires a name, then creates a file with that name. Any messages logged afterwards will be logged to the same file.
	* 
	* Methods:
	*	LOG(string message)
	*		- Adds a message to the file
	*	LOGLN(string message)
	*		- Adds a message to the file with a newline after message.
	*	CLEAR()
	*		- Clears the file and Logs list.
	* 
	* Static Methods:
	*	LOG(string message, string file)
	*		- Adds a line into specified file.
	*	LOGLN(string message, string file)
	*		- Adds a line into specified file with a newline after message.
	*/
	class DevLog
	{
	public:

		std::string name;
		std::string fileType;
		std::string fileName;
		std::vector<std::string> Logs;
		std::fstream LogFile;
		int RepititionCounter = 0;


		DevLog(std::string _name, std::string _fileType = "txt");
		void LOG(std::string message);
		void LOGLN(std::string message);
		void CLEAR();

		static void CLEAR(std::string fileName)
		{
			std::ofstream file(fileName + ".txt");
		}



		// vv STATIC LOGGIN vv
		static inline void LOG(std::string message, std::string file)
		{
			std::vector<std::string> StaticLogs;

			std::fstream StaticLogFile;

			// Open a file to perform a write operation using a file object.
			StaticLogFile.open("Logs/" + file + ".txt", std::ios::in);

			// Checking whether the file is open.
			if (StaticLogFile.is_open())
			{
				std::string sa;
				// Read data from the file object and put it into a string.
				while (getline(StaticLogFile, sa))
				{
					StaticLogs.push_back(sa);
				}

				// Close the file object.
				StaticLogFile.close();
			}

			// Check for and count repitition
			if (StaticLogs.size() >= 1 && StaticLogs[StaticLogs.size() - 1] == message)
				S_RepititionCounter++;
			else
				S_RepititionCounter = 0;

			std::ofstream Constructor("Logs/" + file + ".txt");
			StaticLogFile.open("Logs/" + file + ".txt");
			if (S_RepititionCounter == 0)
				StaticLogs.push_back(message);
			for (int i = 0; i < StaticLogs.size(); i++)
			{
				StaticLogFile << StaticLogs[i];
			}
			if (S_RepititionCounter > 0)
				StaticLogFile << "\nLog above repeated " + std::to_string(S_RepititionCounter) + " times";
			StaticLogFile.close();
		}
		static inline void LOGLN(std::string message, std::string file)
		{
			std::vector<std::string> StaticLogs;

			std::fstream StaticLogFile;

			// Open a file to perform a write operation using a file object.
			StaticLogFile.open("Logs/" + file + ".txt", std::ios::in);

			// Checking whether the file is open.
			if (StaticLogFile.is_open())
			{
				std::string sa;
				// Read data from the file object and put it into a string.
				while (getline(StaticLogFile, sa))
				{
					StaticLogs.push_back(sa);
				}

				// Close the file object.
				StaticLogFile.close();
			}

			// Check for and count repitition
			if (StaticLogs.size() >= 1 && StaticLogs[StaticLogs.size() - 1] == message + '\n')
				S_RepititionCounter++;
			else
				S_RepititionCounter = 0;

			std::ofstream Constructor("Logs/" + file + ".txt");
			StaticLogFile.open("Logs/" + file + ".txt", std::ios::out);
			if (S_RepititionCounter == 0)
				StaticLogs.push_back(message);
			for (int i = 0; i < StaticLogs.size(); i++)
			{
				StaticLogFile << StaticLogs[i];
				StaticLogFile << "\n";
			}
			if (S_RepititionCounter > 0)
				StaticLogFile << "Log above repeated " + std::to_string(S_RepititionCounter) + " times";
			StaticLogFile.close();

		}

	};
}