#pragma once
#include <filesystem>
#include <string>

namespace fs = std::filesystem;

bool ProcessVcxprojFile(const fs::path& path, const std::string& oldName, const std::string& newName);

bool ProcessFiltersFile(const fs::path& path, const std::string& oldName, const std::string& newName);

bool ProcessUserFile(const fs::path& path, const std::string& oldName, const std::string& newName);