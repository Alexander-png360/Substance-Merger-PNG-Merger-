#pragma once
#include <vector>
#include <string>

class Image_Merger {

public:

	static void mergeImages(const std::vector<std::string>& filePaths, const std::string& outputPath);
};

