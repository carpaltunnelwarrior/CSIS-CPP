//Main.cpp
#include "Hash.h"

int main() {
	Hash Hash("names.txt");
	Hash.Sort();
	Hash.Print();
	return 0;
}