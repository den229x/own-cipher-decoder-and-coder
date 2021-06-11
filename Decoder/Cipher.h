#pragma once
#include <string>
#include <vector>

class Cipher
{
private:
	std::string key1, key2, key3;

public:

	Cipher(std::string key1, std::string key2, std::string key3);

	std::string PrintKey1();
	std::string PrintKey2();
	std::string PrintKey3();

};

