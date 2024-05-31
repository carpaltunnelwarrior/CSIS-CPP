//Hash.h
#pragma once
#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>
#include <fstream>

class Hash {
public:
	Hash(const std::string& filename);
	void Sort();
	void Print();
private:
	std::vector<std::vector<std::string>> names;
	int Hasher(const std::string& name);
	int tableSize;
};
#endif