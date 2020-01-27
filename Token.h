#pragma once
#include <string>

using namespace std;

class Token {

private:
	string value;
	string type;
	int lineNum;
	

public:
	Token();
	Token(string type, string value, int lineNum);
	void printTokens();
	string returnType();
	string returnValue();

};

