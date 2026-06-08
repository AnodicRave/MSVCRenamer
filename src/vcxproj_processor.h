#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

bool ProcessVcxprojFile(const fs::path& vcxprojPath, const std::string& oldName, const std::string& newName);

bool ProcessFiltersFile(const fs::path& vcxprojPath, const std::string& oldName, const std::string& newName);

bool ProcessUserFile(const fs::path& vcxprojPath, const std::string& oldName, const std::string& newName);