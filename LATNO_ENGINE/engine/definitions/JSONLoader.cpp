#include "../declarations/JSONLoader.h"


namespace Latno
{

    bool JSONLoader::load(const std::string& filename, Json& jsonData) {
        std::ifstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
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

    void JSONLoader::parseJSON(const Json& jsonData) {
        fieldData.sectorID = jsonData["sector id"].get<std::string>();
        fieldData.


    }

}