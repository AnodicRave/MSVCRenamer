# MSVCRenamer

Rename Microsoft Visual Studio C++ projects without breaking internal links.

## The Problem

Renaming a Visual Studio C++ project manually often leads to broken projects:

- Renaming the folder breaks all paths in `.vcxproj`
- Visual Studio's built-in "Rename" doesn't update everything
- You end up editing XML files by hand - slow and error-prone

## The Solution

Point to your project, enter a new name, and you're done. The tool:

- Updates `.sln`, `.vcxproj`, `.vcxproj.filters` files
- Renames the project folder and all related files
- Creates backups (.bak) before any changes

Requirements:

- CMake 3.10+
- C++17 compiler
- pugixml (included in external/)
