#pragma once
#include "Parameter.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;
class Predicate{
    public:
    Predicate(){};
    Predicate(string currentToken);
    string ID;
    string toString();
    string toStringDomain();
    vector<Parameter>ParamList;
    vector<Parameter>DomainList;
    void AddParam(string currentTokenList);
};