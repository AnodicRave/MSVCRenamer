#include "file_tools.h"
#include "sln_processor.h"
#include <iostream>
#include <regex>
#include <string>

//NOTE: Substring matches are NOT supported yet.
//* If the project name is a substring of another word
//* it will also be replaced - fix later.
//TODO: Add .sln file renaming

bool ProcessSlnFile(const fs::path& slnPath, const std::string& oldName, const std::string& newName) {
    std::string content;
    if (!file_tools::ReadFileToString(slnPath, content)) {
        std::cerr << "Failed to read " << slnPath << std::endl;
        return false;
    }

    if (content.find(oldName) == std::string::npos) {
        std::cout << "No changes in .sln: " << slnPath.filename() << std::endl;
        return true;
    }

    std::string newContent = content;
    size_t pos = 0;
    while ((pos = newContent.find(oldName, pos)) != std::string::npos) {
        newContent.replace(pos, oldName.length(), newName);
        pos += newName.length();
    }

    if (!file_tools::WriteStringToFile(slnPath, newContent)) {
        std::cerr << "Failed to write updated .sln: " << slnPath << std::endl;
        return false;
    }

    std::cout << "Updated .sln: " << slnPath.filename() << std::endl;
    return true;
}