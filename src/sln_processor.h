#pragma once
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

//NOTE: Simple find and replace, substring matches aren't supported
bool ProcessSlnFile(const fs::path& slnPath, const std::string& oldName, const std::string& newName);