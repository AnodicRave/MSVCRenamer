#include "file_tools.h"
#include "sln_processor.h"
#include <iostream>
#include <regex>
#include <string>

//NOTE: Substring matches are NOT supported yet.
//* If the project name is a substring of another word
//* it will also be replaced - fix later.

bool ProcessSlnFile(const fs::path& slnPath, const std::string& oldName, const std::string& newName) {

    //Update content inside the .sln file

    std::string content;
    if (!file_tools::ReadFileToString(slnPath, content)) {
        std::cerr << "Failed to read " << slnPath << std::endl;
        return false;
    }

    if (content.find(oldName) != std::string::npos) {
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

        std::cout << "Updated content: " << slnPath.filename() << std::endl;
    }
    else {
        std::cout << "No changes in content: " << slnPath.filename() << std::endl;
    }

    // Rename the .sln file if its name contains oldName

    if (slnPath.filename().string().find(oldName) != std::string::npos) {
        fs::path newPath = slnPath.parent_path() / (newName + ".sln");
        try {
            fs::rename(slnPath, newPath);
            std::cout << "Renamed: " << slnPath.filename() << " -> " << newPath.filename() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Failed to rename .sln: " << e.what() << std::endl;
            return false;
        }
    }

    return true;
}