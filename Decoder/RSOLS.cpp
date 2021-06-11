#include "RSOLS.h"
#include <iostream>
#include <vector>
#include <string>


// Создаем ключи 
std::string RSOLS::createKey(std::vector<unsigned char> pass)
{
	std::vector<unsigned char> key;
	unsigned char temp; // временно для перестановки битов


	key.push_back(pass[pass.size() - 1]);

	for (int i = 0; i < 7; i++)
	{
		temp = pass[0] ^ pass[1] ^ pass[pass.size() - 1];

		for (int j = pass.size() - 1; j > 0; j--)
		{
			pass[j] = pass[j - 1];
		}

		pass[0] = temp;

		key.push_back(pass[pass.size() - 1]);
	}

	std::string key_string;
	for (int i = 0; i < key.size(); i++)
	{
		key_string += key[i];
	}

	return key_string;
}
