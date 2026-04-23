#pragma once
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;

namespace file_tools {

	std::vector<fs::path> FindFiles(const fs::path& dir, const std::string& extension);

	bool CreateBackup(const fs::path& filePath);

	bool ReadFileToString(const fs::path& filePath, std::string& content);

	bool WriteStringToFile(const fs::path& filePath, const std::string& content);

}