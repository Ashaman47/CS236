#pragma once
#include <map>
#include <iterator> 
#include <iostream>
#include "DatalogProgram.h"
#include "Relation.h"
#include "Scheme.h"

using namespace std;
class Database{
    public:
        Database();
        map<string, Relation>relations;
        void addRelation(string Name, Scheme scheme);
        void addTuplesToRelation(string Name, Tuple current);
        void printDatabase();
        void checkQuery(vector<string>queries, vector<int>isConstant);

};
