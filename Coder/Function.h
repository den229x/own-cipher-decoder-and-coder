#pragma once
#include <string>
#include <vector>

int AddDopSign(std::vector<unsigned char>& text, int& counter);

void ReadFromFile(std::vector<std::string>& arr, std::string file_name);

void CiclicShift(std::vector<unsigned char>& half, int count, std::string side);

void SplitHalf(std::vector<unsigned char>  text, std::vector<unsigned char>& first_half, std::vector<unsigned char>& second_half, int& k, int& m);

void X0r(std::vector<unsigned char>& half, std::string key);
void X0r(std::vector<unsigned char>& half, std::vector<unsigned char> half_dop);

void Sbox(std::vector<unsigned char>& half);
