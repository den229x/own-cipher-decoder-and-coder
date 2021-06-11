#include "Cipher.h"
#include <vector>
#include <string>
#include <iostream>


Cipher::Cipher(std::string key1, std::string key2, std::string key3)
{
	this->key1 = key1;
	this->key2 = key2;
	this->key3 = key3;
}


std::string Cipher::PrintKey1()
{
	return key1;
}

std::string Cipher::PrintKey2()
{
	return key2;
}

std::string Cipher::PrintKey3()
{
	return key3;
}
