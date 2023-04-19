#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

void list_directory(const fs::path& path) {
    try {
        if (fs::exists(path) && fs::is_directory(path)) {
            std::cout << "Listing directory: " << path << std::endl;
            for (const auto& entry : fs::directory_iterator(path)) {
                std::cout << (entry.is_directory() ? "[D]" : "[F]") << ' ' << entry.path().filename() << std::endl;
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void create_directory(const fs::path& path) {
    try {
        fs::create_directory(path);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void create_file(const fs::path& path) {
    try {
        std::ofstream file(path);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void delete_file(const fs::path& path) {
    try {
        fs::remove(path);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

void copy_file(const fs::path& src, const fs::path& dest) {
    try {
        fs::copy(src, dest, fs::copy_options::overwrite_existing);
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    std::string command;
    std::string path, dest;

    while (true) {
        std::cout << "> ";
        std::cin >> command;

        if (command == "list") {
            std::cin >> path;
            list_directory(path);
        }
        else if (command == "mkdir") {
            std::cin >> path;
            create_directory(path);
        }
        else if (command == "create") {
            std::cin >> path;
            create_file(path);
        }
        else if (command == "delete") {
            std::cin >> path;
            delete_file(path);
        }
        else if (command == "copy") {
            std::cin >> path >> dest;
            copy_file(path, dest);
        }
        else if (command == "exit") {
            break;
        }
        else if (command == "q" || command == "quit")
        {
            std::cout << "closing the program" << std::endl;
            return 0;
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    }

    return 0;
}
