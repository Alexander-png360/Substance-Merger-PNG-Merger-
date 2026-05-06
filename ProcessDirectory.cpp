#include <filesystem>
#include <vector>
#include <string>

#include "PrefixGrouper.h"
#include "Image_Merger.h"

void processDirectory(const std::string& directoryPath)
{
    std::vector<std::string> files;

    for (const auto& entry : std::filesystem::directory_iterator(directoryPath)) {
        if (entry.is_regular_file()) {
            std::string path = entry.path().string();

            if (path.size() >= 4 &&
                path.substr(path.size() - 4) == ".png")
            {
                files.push_back(path);
            }
        }
    }

    auto groups = PrefixGrouper::groupByMapType(files);

    for (const auto& [mapType, groupfiles] : groups) {
        std::string outputPath =
            directoryPath + "/" + mapType.substr(1) + "_combined.png";

        Image_Merger::mergeImages(groupfiles, outputPath);
    }
}