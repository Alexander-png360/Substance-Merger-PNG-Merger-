#include "PrefixGrouper.h"
#include <filesystem>
#include <algorithm> // for std::transform

std::map<std::string, std::vector<std::string>> PrefixGrouper::groupByMapType(const std::vector<std::string>& files) {
    std::map<std::string, std::vector<std::string>> groups;

    for (const std::string& filePath : files) {
        std::filesystem::path p(filePath);
        std::string filename = p.filename().string();

        // Convert filename to lowercase for comparison
        std::string lowercaseName = filename;
        std::transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);

        if (lowercaseName.find("normal") != std::string::npos) {
            groups["_normal"].push_back(filePath);
        }
        else if (lowercaseName.find("basecolor") != std::string::npos || lowercaseName.find("albedo") != std::string::npos) {
            groups["_BaseColor"].push_back(filePath);
        }
        else if (lowercaseName.find("alpha") != std::string::npos || lowercaseName.find("albedo") != std::string::npos) {
            groups["_Alpha"].push_back(filePath);
        }
        else if (lowercaseName.find("emission") != std::string::npos || lowercaseName.find("albedo") != std::string::npos) {
            groups["_Emission"].push_back(filePath);
        }
        else if (lowercaseName.find("metallic") != std::string::npos || lowercaseName.find("albedo") != std::string::npos) {
            groups["_Metallic"].push_back(filePath);
        }
        else if (lowercaseName.find("roughness") != std::string::npos || lowercaseName.find("albedo") != std::string::npos) {
            groups["_Roughness"].push_back(filePath);
        }

        
    }
    return groups;
}