
#include "Parameter.h"
#include <cctype>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>

Parameter::Parameter(string currentToken){
    currentTokenList += currentToken;
}
string Parameter::toString(){
    return currentTokenList;
}
