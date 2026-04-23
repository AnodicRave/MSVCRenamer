#include "file_tools.h"
#include <fstream>
#include <iostream>


std::vector<fs::path> file_tools::FindFiles(const fs::path& dir, const std::string& extension){
	std::vector<fs::path> result{};

	if (!fs::exists(dir))
		return result;

	for (const auto& entry : fs::recursive_directory_iterator(dir)) {
		if (entry.is_regular_file() && entry.path().extension() == extension) {
			result.push_back(entry.path());
		}
	}

	return result;
}

bool file_tools::CreateBackup(const fs::path& filePath){
	fs::path backupPath = filePath;
	backupPath += ".bak"; 

	try {
		fs::copy_file(filePath, backupPath, fs::copy_options::overwrite_existing);
		std::cout << "Backup created: " << backupPath.filename() << std::endl;
		return true;
	}
	catch (const std::exception& e) {
		std::cerr << "Failed to backup " << filePath << ": " << e.what() << std::endl;
		return false;
	}
}

bool file_tools::ReadFileToString(const fs::path& filePath, std::string& content){
	std::ifstream file(filePath, std::ios::binary);

	if (!file.is_open())
		return false;

	content.assign(
		(std::istreambuf_iterator<char>(file)),
		std::istreambuf_iterator<char>());

	return true;
}

bool file_tools::WriteStringToFile(const fs::path& filePath, const std::string& content){
	std::ofstream file(filePath, std::ios::binary);
	if (!file.is_open())
		return false;

	file.write(content.data(), content.size());

	return true;
}
