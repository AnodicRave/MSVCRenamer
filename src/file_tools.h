#pragma once
#include <filesystem>
#include <vector>

namespace file_tools {

	std::vector<std::filesystem::path> FindFiles(const std::filesystem::path& dir, const std::string& extension);

	bool CreateBackup(const std::filesystem::path& filePath);

	bool ReadFileToString(const std::filesystem::path& filePath, std::string& content);

	bool WriteStringToFile(const std::filesystem::path& filePath, const std::string& content);

}