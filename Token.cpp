#include "Token.h"
#include <iostream>

using namespace std;

Token::Token() {}

Token::Token(string Type, string Value, int LineNum) {
	value = Value;
	lineNum = LineNum;
	type = Type;
}
void Token::printTokens() {
	cout << "(" << type << ",\"" << value << "\"," << lineNum << ")" << endl;
	return;
}

string Token::returnType() {
	return type;
}

string Token::returnValue() {
	return value;
}
