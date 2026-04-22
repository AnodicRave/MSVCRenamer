#pragma once
#include <filesystem>
#include <vector>

namespace file_tools {

	std::vector<std::filesystem::path> FindFiles(const std::filesystem& dir, const std::string& extension);

	bool BackupFile(const std::filesystem& filePath);

	bool ReadFileToString(const std::filesystem::path& filePath, std::string& content);

	bool WriteStringToFile(const std::filesystem::path& filePath, const std::string& content);

}