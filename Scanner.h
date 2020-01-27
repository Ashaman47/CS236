#pragma once
#include "Token.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Scanner {
public:
	Scanner(string filename);
	void Readfile(string filename);
	ifstream in;
	vector<char> input{};

	string type;
	char currentchar;
	void Tokenize();
	string value;
	void PrintEOF();

private:
	int stringfunc(int i,int linenum);
	int linenum;
	int c;
	int oldline;
	int TotalTokens = 1;
	string filename;
	void commentfunc();
	int i;
};
