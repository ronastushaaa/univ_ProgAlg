#pragma once
#include <vector>

// ������� ��� ������ �� ��������
bool        n_IsSpace(char ch);

std::string n_Trim (std::string  str);
std::string n_Token(std::string &str, std::string sep, bool trim = true);
void        n_Split(std::string  str, std::string sep, std::vector<std::string> &v, bool trim = true);


// �������� �� ����� (���������� ���������� ��������������)
bool to_double(std::string s, double* num = NULL);

// �������� �� ����� ����� (���������� ���������� ��������������)
bool to_number(std::string s, int* num = NULL);

// ������ ������ �� stdin
int    n_ReadInt(int def);
double n_ReadDouble(double def);