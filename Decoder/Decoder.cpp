#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include "RSOLS.h"
#include "Cipher.h"
#include "Function.h"


//		
//		░						░░░░░░░▄▄█████▄░░░░░░░
//								░░░░░▄█▀░░░░░░▀█▄░░░░░
//								░░░░▄█▀░░░░░░░░░█▄░░░░
//							   	░░░▄██████▄▄██████▄▄░░
//░								 ▄█▀░░░░░░▀██░░░░░▀██░
//								▄█░░░░░░░░░░█▄░░░░░░██
//								██░░░░░░░░░░▀█▄░░░░░██
//								▀█▄░░░░░░░░░░░▀░░░░░█▀
//								░▀█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█▀░
//								░░░▀██████████████▀░░░
//								░░░░░█████████████░░░░
//								░░░░░░███████████░░░░░
//								░░░░░░▀█████████▀░░░░░
//								░░░░░░░█████████░░░░░░
//								░░░░░░░░███████░░░░░░░
//								░░░░░░░░▀█████▀░░░░░░░
//								░░░░░░░░░█████░░░░░░░░
//								░░░░░░░░░▀███▀░░░░░░░░
//								░░░░░░░░░░▀█▀░░░░░░░░░




int main()
{
	std::vector<unsigned char> text;
	std::string file_name = "out.txt";
	std::string file_name_of_passwords = "passwords.txt";
	std::vector<std::string> arr;
	OpenAndWritingFile(text,file_name);
	int len_of_text;
	int k = 8;
	int m = 0;
	unsigned char a;
	int counter_of_dop_sign;
	a = text[text.size() - 1];
	counter_of_dop_sign = (int)a;
	counter_of_dop_sign = (counter_of_dop_sign - 69) / 7;
	text.pop_back();


	ReadPasswords(file_name_of_passwords, arr);

	std::vector<unsigned char> pass, pass2, pass3;
	for (int i = 0; i < arr[0].length(); i++)
	{
		pass.push_back(arr[0][i]);
	}
	for (int i = 0; i < arr[1].length(); i++)
	{
		pass2.push_back(arr[1][i]);
	}
	for (int i = 0; i < arr[2].length(); i++)
	{
		pass3.push_back(arr[2][i]);
	}
	RSOLS gpsp;
	Cipher cip(gpsp.createKey(pass3), gpsp.createKey(pass2), gpsp.createKey(pass));

	std::vector<unsigned char> first_half;
	std::vector<unsigned char> second_half;
	int rounds = text.size() / 16;


	for (int j = 0; j < rounds; j++)
	{
		SplitHalf(text, first_half, second_half, k, m);
		X0r(second_half, first_half);
		Msbox(first_half);
		X0r(first_half, cip.PrintKey3());
		CiclicShift(first_half, 1, "left");
		Msbox(second_half);
		X0r(second_half, cip.PrintKey2());
		CiclicShift(second_half, 2, "right");
		Msbox(first_half);
		X0r(first_half, cip.PrintKey1());
		CiclicShift(first_half, 3, "left");

		int temp = 0;
		for (int i = m - 8; i < k - 8; i++)
		{
			text[i] = first_half[temp];
			temp++;
		}

		temp = 0;
		for (int i = m; i < k; i++)
		{
			text[i] = second_half[temp];
			temp++;
		}

		first_half.clear();
		second_half.clear();
		m += 8;
		k += 8;
	}

	for (int i = 0; i < counter_of_dop_sign; i++)
	{
		text.pop_back();
	}

	std::ofstream file("finish.txt");

	for (int i = 0; i < text.size(); i++)
	{
		file << text[i];
	}
	file.close();

	

	return 0;
}


