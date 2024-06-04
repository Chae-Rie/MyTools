#include "../include/MyTools/fileparser.h"
namespace MyTools{

    namespace Fileparser{

        // Funktion zum Parsen der .env-Datei
        std::unordered_map<std::string, std::string> parseEnvFile(const std::string& filePath) {


            std::unordered_map<std::string, std::string> envMap;
            std::ifstream infile(filePath);

            if (!infile.is_open()) {
                std::cerr << "Fehler beim Öffnen der Datei: " << filePath << std::endl;
                return envMap;
            }

            std::string line;
            while (std::getline(infile, line)) {
                // Überspringen leerer Zeilen und Kommentare
                if (line.empty() || line[0] == '#') {
                    continue;
                }

                // Finden der Position des Gleichheitszeichens
                std::size_t pos = line.find('=');
                if (pos == std::string::npos) {
                    continue; // Ungültige Zeile, kein '=' gefunden
                }

                // Extrahieren des Schlüssels und des Werts
                std::string key = line.substr(0, pos);
                std::string value = line.substr(pos + 1);

                // Entfernen von Anführungszeichen um den Wert
                if (!value.empty() && value.front() == '"' && value.back() == '"') {
                    value = value.substr(1, value.size() - 2);
                }

                // Hinzufügen zum Dictionary
                envMap[key] = value;
            }

            return envMap;
        }


        // Funktion zum Abrufen eines Werts basierend auf dem Schlüssel
        std::string getValueByKey(const std::unordered_map<std::string, std::string>& envMap, const std::string& key) {
            auto it = envMap.find(key);
            if (it != envMap.end()) {
                return it->second;
            } else {
                return ""; // Oder eine geeignete Fehlermeldung/Wert
            }
        }
    } // end namespace Fileparser
} // end namespace MyTools
