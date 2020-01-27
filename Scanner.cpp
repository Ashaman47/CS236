#include "Scanner.h"
#include "Token.h"
#include <cctype>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;

Scanner::Scanner(string fileName) {
	linenum = 1;
	filename = fileName;
	Readfile(filename);
	Tokenize();

}
void Scanner::Readfile(string filename) {

	in.open(filename);
	while (c != -1) {
		c = in.get();
		currentchar = static_cast<char>(c);
		input.push_back(currentchar);
	}
	return;
}
void Scanner::Tokenize() {
	for (i = 0; i < static_cast<signed int>(input.size()) - 1; i++) {
		if (isspace(input[i])) {
			if (input[i] == '\n') {
				linenum++;
			}
			i++;
			if (input[i] == '\n') {
				linenum++;
			}
		}
		
		if (isalpha(input[i])) {
			type = "ID";
			while (isalpha(input[i]) || isdigit(input[i])) {
				value += input[i];
				i++;
			}
            i--;
			if (value == "Queries") {
				type = "QUERIES";
			}
			if (value == "Rules") {
				type = "RULES";
			}
			if (value == "Facts") {
				type = "FACTS";
			}
			if (value == "Schemes") {
				type = "SCHEMES";
			}
		}
		else if (input[i] == '\'') {
			i = stringfunc(i, linenum);
			if (i == -1) {
				exit(EXIT_SUCCESS);
			}
			if (input[i] == '\n') {
				linenum++;
			}
		}
		else if (input[i] == ',') {
			type = "COMMA";
			value += ",";

		}
		else if (input[i] == ':') {
			type = "COLON";
			value += ":";
			if (input[i + 1] == '-') {
				type = "COLON_DASH";
				value += "-";
				++i;
			}
		}
		else if (input[i] == '?') {
			type = "Q_MARK";
			value += "?";
		}
		else if (input[i] == '(') {
			type = "LEFT_PAREN";
			value += "(";
		}
		else if (input[i] == '.') {
			type = "PERIOD";
			value += ".";
		}
		else if (input[i] == ')') {
			type = "RIGHT_PAREN";
			value += ")";
		}
		else if (input[i] == '*') {
			type = "MULTIPLY";
			value += "*";
		}
		else if (input[i] == '+') {
			type = "ADD";
			value += "+";
		}

		else if (input[i] == '#') {
			type = "COMMENT";
			oldline = linenum;
			if (input[i + 1] == '|') {
				commentfunc();
			}
			else {
				do {
					value += input[i];
					i++;

				} while (input[i] != '\n');
				if (input[i] == '\n') {
					linenum++;
				}
			}
			Token token(type, value, oldline);
			token.printTokens();
			TotalTokens++;
			value.clear();
		}
		else {
			type = "UNDEFINED";
			if (input[i] == -1) {
				break;
			}
			if (!isspace(input[i])) {
				value += input[i];
			}
		}
		if (value != "") {
			if (input[i] != '#' ) {
				Token token(type, value, linenum);
				token.printTokens();
				TotalTokens++;
				value.clear();
			}
		}
		if (i == -1) {
			break;
		}
	}
	PrintEOF();
}

void Scanner::PrintEOF() {
	cout << "(EOF,\"\"," << linenum << ")" << endl;
	cout << "Total Tokens = " << TotalTokens << endl;
	return;
}

int Scanner::stringfunc(int i, int funcstartline) {
	type = "STRING";
	int oldline = funcstartline;
	value += input[i];

	do {

		if (i < static_cast<signed int>(input.size()) - 1) {
			i++;
			if (input[i] == '\n') {
				linenum++;
			}
		}
		else {
			type = "UNDEFINED";
			Token token(type, value, oldline);
			token.printTokens();
			TotalTokens++;
			PrintEOF();
			
			i = -1;
			return -1;
		}
		if (input[i] != -1){
		    value += input[i];
        }
	} while (input[i] != '\'');
	if (input[i + 1] == '\'') {
		i = stringfunc(i + 1, oldline);

	}
	if (i != -1) {
        if (value != ""){
		Token token(type, value, oldline);
		token.printTokens();
		TotalTokens++;
		value.clear();
        }
	}
	
	return i;
}

void Scanner::commentfunc(){
	do {
		if (input[i] == '\n') {
			linenum++;
		}
		value += input[i];
		i++;
	} while (input[i] != '|');
	if(input[i+1] != '#'){
		commentfunc();
	}
	else{
		value += input[i];
		value += input[i+1];
		++i;
		if (input[i] == '\n') {
			linenum++;
		}
	}
}
