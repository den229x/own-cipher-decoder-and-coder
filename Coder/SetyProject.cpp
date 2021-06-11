#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
#include "Cipher.h"
#include "RSOLS.h"
#include "Function.h"





											
    //                                     	   	░░░░░░░░░░░░░██░░░░░░░░░░░░░                               
    //                                          ░░░░░░░░░░░▀████▀░░░░░░░░░░░
    //                                          ░░░░░░░░░░░▄█▀▀█▄░░░░░░░░░░░
    //      	                             	░░░░░░░░░░░ ░▄▄░░░░░░░░░░░░░
	//     		                                ░░░░░░░░░░░▄████▄░░░░░░░░░░░
	//											░░░░░░░░░▄████████▄░░░░░░░░░
	//											░░░░░░░▄▄░░▀▀▀▀█████▄░░░░░░░
	//											░░░░░░▀▀█▄░██░░░▄▄░▀▀▀░░░░░░                        
	//											░░░░░░▄██████▄░▄█████▄░░░░░░                           
	//											░░░░▄██████████████████▄░░░░                           
	//											░░░▀▀▀██████████▀▀▀▀▀░░░░░░░                          
	//											░░░░░▀▀▀▀▀░░▄▄▄░░▄█░███▄░░░░                           
	//											░░▄▄▄▄█████▄███▄▄████████▄░░                            
	//											░▀▀▀▀█████████████████████▄░                      
	//											░░░░▄▄░░░▄▄░░░░░░░▀▀▀▀▀░░░░░                            
	//											░░▄███▄░▄██▄▄██████░░████▄░░                             
	//											▄██████████████████████████▄                            
	//											░░░░░░░░░░░░████░░░░░░░░░░░░                          
	//		                            		░░░░░░░░░░░░████░░░░░░░░░░░░                            
  		



int main() 
{
	int len_of_text;
	int k = 8;
	int m = 0;
	int counter_of_dopSign = 0;

	std::vector<std::string> arr;
	std::string file_name = "text.txt";

	ReadFromFile(arr, file_name);

	std::vector<unsigned char> text;
	for (int i = 0; i < arr[0].length(); i++)
	{
		text.push_back(arr[0][i]);
	}
	std::vector<unsigned char> pass;
	for (int i = 0; i < arr[1].length(); i++)
	{
		pass.push_back(arr[1][i]);
	}
	std::vector<unsigned char> pass2;
	for (int i = 0; i < arr[2].length(); i++)
	{
		pass2.push_back(arr[2][i]);
	}
	std::vector<unsigned char> pass3;
	for (int i = 0; i < arr[3].length(); i++)
	{
		pass3.push_back(arr[3][i]);
	} 


	std::vector<unsigned char> first_half;
	std::vector<unsigned char> second_half;
	int rounds;

	
	RSOLS gpsp;
	Cipher cip(gpsp.createKey(pass3),gpsp.createKey(pass2), gpsp.createKey(pass));

	rounds = AddDopSign(text,counter_of_dopSign);

	for (int j = 0; j < rounds; j++)
	{
		SplitHalf(text, first_half, second_half, k, m);
		CiclicShift(first_half, 3, "right");
		X0r(first_half, cip.PrintKey1());
		Sbox(first_half);
		CiclicShift(second_half, 2, "left");
		X0r(second_half, cip.PrintKey2());
		Sbox(second_half);
		CiclicShift(first_half, 1, "right");
		X0r(first_half, cip.PrintKey3());
		Sbox(first_half);
		X0r(second_half, first_half);

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

	std::ofstream file_out("Decoder\\out.txt");
	
	for (int i = 0; i < text.size(); i++)
	{
		file_out << text[i];
	}

	unsigned char a = counter_of_dopSign * 7 + 69;

	file_out << a;

	file_out.close();

	return 0;
}
 
