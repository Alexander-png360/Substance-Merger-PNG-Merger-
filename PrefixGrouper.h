#pragma once
#include <string>
#include <vector>
#include <map>


class PrefixGrouper {
	
public:

	static std::map <std::string, std::vector<std::string>> groupByMapType(const std::vector<std::string>& files);

private:

	static std::string extractMapType(const std::string& filename);
};

