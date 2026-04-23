#include "file_tools.h"
#include <iostream>


std::vector<std::filesystem::path> file_tools::FindFiles(const std::filesystem::path& dir, const std::string& extension){
	std::vector<std::filesystem::path> result;

	if (!std::filesystem::exists(dir))
		return result;

	for (const auto& entry : std::filesystem::recursive_directory_iterator(dir)) {
		if (entry.is_regular_file() && entry.path().extension() == extension) {
			result.push_back(entry.path());
		}
	}

	return result;
}

bool file_tools::CreateBackup(const std::filesystem::path& filePath){

}
