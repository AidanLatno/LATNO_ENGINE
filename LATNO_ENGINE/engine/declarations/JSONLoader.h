#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "../../UserClasses/declarations/Sector.h"

#include "nlohmann/json.hpp"

using Json = nlohmann::json;

namespace Latno
{
	class JSONLoader
	{
		
	public:
		static bool load(const std::string& filename, Json& jsonData);
		static void parseJSON(const Json& jsonData, Sector**& field, float*& weather);

				
		
		
			

	};	
}
