#include "../declarations/JSONLoader.h"

namespace Latno
{

    bool JSONLoader::load(const std::string& filepath, Json& jsonData) {
        std::ifstream file(filepath);


        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filepath << std::endl;
            return false;
        }

        try {
            file >> jsonData;
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
            file.close();
            return false;
        }

        file.close();
        return true;
    }

    void JSONLoader::Write(std::string filepath, Json& data)
    {
        std::ofstream output("resources/JSON/sectors.json");
    if (!output.is_open()) {
        std::cerr << "Failed to open the JSON file for writing." << std::endl;
        return;
    }

    // Write the modified JSON data back to the file
    try {
        output << data.dump(4);  // The argument specifies the indentation level
    } catch (const nlohmann::json::exception& e) {
        std::cerr << "Failed to write JSON: " << e.what() << std::endl;
    }
    }


}
