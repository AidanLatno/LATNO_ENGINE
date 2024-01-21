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

    void JSONLoader::parseJSON(const Json& jsonData, Sector**& field, float*& weather) {

        for (int y = 0; y < 24; y++) {
            for (int x = 0; x < 24; x++) {
                field[y][x].sectorID = (y * 24) + x;
                field[y][x].plantHealth = jsonData["sectorInfo"][field[y][x].sectorID]["plantHealth"];
                field[y][x].waterAddAmount = jsonData["sectorInfo"][field[y][x].sectorID]["waterAddAmount"];
                field[y][x].mineralHealth = jsonData["sectorInfo"][field[y][x].sectorID]["mineralHealth"];
                weather[0] = jsonData["globalInfo"]["timeID"];
                weather[1] = jsonData["globalInfo"]["temperature"];
                weather[2] = jsonData["globalInfo"]["precipitation"];
            }
        }
    }
}
