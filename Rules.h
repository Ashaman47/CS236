#pragma once
#include "Predicate.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;
class Rules{
    public:
    Rules(){};
    Rules(Predicate p);
    string currentTokenList;
    string toString();
    Predicate Pred;
    vector<Predicate>PredList;
    void addRule(Predicate Pred);
    Predicate getPred();
};