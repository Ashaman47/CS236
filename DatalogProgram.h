#pragma once
#include <vector>
#include "Predicate.h"
#include "Rules.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
class DatalogProgram{
    public:
    DatalogProgram();
    void Print();
    void addFacts(Predicate f);
    void addQueries(Predicate q);
    void addSchemes(Predicate s);
    void addRules(Rules r);
    void addDomain(string f);
    vector<Rules>RulesList;
    vector<Predicate>SchemesList;
    vector<Predicate>FactsList;
    vector<Predicate>QueriesList;
    vector<string>DomainList;
    private:
};