#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

#include "nlohmann/json.hpp"

using Json = nlohmann::json;

namespace Latno
{
	class JSONLoader
	{
		
	public:
		static bool load(const std::string& filename, Json& jsonData);
		static void parseJSON(const Json& jsonData);

				
		float waterAmount, currentWater, plantHealth, mineralHealth;
		float time, temperture, percipitation;
		
			

	};	
}
