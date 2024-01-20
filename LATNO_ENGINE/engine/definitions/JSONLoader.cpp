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
                Json ref = jsonData[(y * 24) + x];
                Sector fieldRef = field[y][x];
                fieldRef.sectorID = (y * 24) + x;

                fieldRef.plantHealth = ref["plant health"].get<float>();
                fieldRef.plantHealth = ref["plant health"].get<float>();
                fieldRef.plantHealth = ref["plant health"].get<float>();
                fieldRef.plantHealth = ref["plant health"].get<float>();
                fieldRef.plantHealth = ref["plant health"].get<float>();
                fieldRef.plantHealth = ref["plant health"].get<float>();
                fieldRef.plantHealth = ref["plant health"].get<float>();

            }
        }

    }

}