#pragma once
#include <map>
#include <vector>
#include "DatalogProgram.h"
using namespace std;
class Scheme{
    public:
        Scheme();
        vector<string>Schemes;
        void addScheme(string scheme);
        string toString();
        string name;
        void deleteScheme();
        void erase(vector<int>i);
        string receiveOneScheme(int i);
        int size();

};
