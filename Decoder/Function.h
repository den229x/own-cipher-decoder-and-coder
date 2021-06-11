#pragma once
#include <vector>
#include <string>

void OpenAndWritingFile(std::vector<unsigned char>& text, std::string file_name);

void X0r(std::vector<unsigned char>& half, std::string key);
void X0r(std::vector<unsigned char>& half, std::vector<unsigned char> half_dop);

void SplitHalf(std::vector<unsigned char> text, std::vector<unsigned char>& first_half, std::vector<unsigned char>& second_half, int& k, int& m);

void CiclicShift(std::vector<unsigned char>& half, int count, std::string side);

void ReadPasswords(std::string file_name_of_passwords, std::vector<std::string>& arr);

void Msbox(std::vector<unsigned char>& half);


