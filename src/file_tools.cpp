#include "file_tools.h"


std::vector<std::filesystem::path> file_tools::FindFiles(const std::filesystem& dir, const std::string& extension){
	std::vector<fs::path> result;

	if (!std::filesystem::exists(dir))
		return result;

	for (const auto& entry : std::filesystem::recursive_directory_iterator(dir)) {
		if (entry.is_regular_file() && entry.path().extension() == extension) {
			result.push_back(entry.path());
		}
	}

	return result;
}

bool file_tools::BackupFile(const std::filesystem& filePath){

	return false;
}
