#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class Parameter{
    public:
    Parameter(){};
    Parameter(string currentToken);
    string currentTokenList;
    string toString();
};