#include <iostream>
#include <string>
#include "vcxproj_processor.h"
#include "file_tools.h"
#include "pugixml.hpp"

// Figure out underscore differences ("My_Project" -> "MyProject")
// TODO: Add file renaming (currently: content update only)

static bool ProcessXmlFile(const fs::path& path, const std::string& oldName, const std::string& newName) {
    pugi::xml_document doc;
    if (!doc.load_file(path.c_str())) {
        std::cerr << "Failed to parse: " << path.filename() << std::endl;
        return false;
    }

    const char* tags[] = { "RootNamespace", "ProjectName" };
    for (const char* tag : tags) {
        auto node = doc.select_node(("//" + std::string(tag)).c_str()).node();
        if (node && node.first_child() && node.first_child().value() == oldName) {
            node.first_child().set_value(newName.c_str());
            doc.save_file(path.c_str());
            std::cout << "Updated " << tag << " in: " << path.filename() << std::endl;
            return true;
        }
    }

    std::cout << "No changes: " << path.filename() << std::endl;
    return true;
}

bool ProcessVcxprojFile(const fs::path& path, const std::string & oldName, const std::string & newName) {
    return ProcessXmlFile(path, oldName, newName);
}

bool ProcessFiltersFile(const fs::path& path, const std::string& oldName, const std::string& newName){
    return ProcessXmlFile(path, oldName, newName);
}

bool ProcessUserFile(const fs::path& path, const std::string& oldName, const std::string& newName){
    return ProcessXmlFile(path, oldName, newName);
}