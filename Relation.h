#pragma once
#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include "DatalogProgram.h"
#include "Tuple.h"
#include "Scheme.h"

using namespace std;
class Relation{
    public:
        Relation(){};
        Relation(string name, Scheme schemes);
        string Name;
        Scheme scheme;
        vector<Tuple>Tuples;
        void addTuple(Tuple current);
        string toString();
        string toStringScheme();
        void select(string queries, int i);
        vector<Tuple>variables;
        vector<Tuple>constants;
        vector<string>dupQuery;
        vector<int>dupLocation;
        void Project(vector<int>columns);
        void Rename(vector<string>queries);
        void cQ(vector<string>queries, vector<int>isConstant);
        int failConstant = 0;   
        vector<int> columns;
        void select2(int j, int i);
        vector<string> otherString;
};
