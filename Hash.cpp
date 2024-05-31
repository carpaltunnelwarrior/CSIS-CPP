//Hash.cpp
#include "Hash.h"

#include <iostream>

Hash::Hash(const std::string& filename) : tableSize(53) {
    names.resize(tableSize);
}

void Hash::Sort() {
    std::string name;
    std::ifstream file("names.txt");

    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return;
    }

    while (std::getline(file, name)) {
        int index = Hasher(name);
        names[index].push_back(name);
    }
    file.close();
}

void Hash::Print() {
    for (int i = 0; i < tableSize; i++) {
        if (!names[i].empty()) {
            std::cout << i << ": ";
            for (const std::string& name : names[i]) {
                std::cout << name << ", ";
            }
            std::cout << std::endl;
        }
    }
}

int Hash::Hasher(const std::string& name) {
    int hashVal = 5381;
    for (int i = 0; i < name.length(); i++) {
        hashVal *= 33;
        hashVal += static_cast<int>(name[i]);
    }
    return abs(hashVal % tableSize);
}