#pragma once
#include "Token.h"
#include "Scanner.h"
#include "DatalogProgram.h"
#include "Predicate.h"
#include "Rules.h"
#include "Database.h"
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;
class Parser{
    public:
    Parser(){}; 
    Parser(vector<Token>tokenlist);
    DatalogProgram DLP;
    Predicate Pred;
    Database DB;
    Scheme scheme;
    Tuple tuple;
    vector<string>queries;
    vector<int>isConstant;
    int querycheck = 0;
    Rules R;
    private:
    string Domain;
    vector<Token>tokenList;
    void ParseDatalogProgram();
    int currenttoken;
    void printerror();
    void match(string currenttype);
    void ParseSchemes();
    void ParseIdList();
    void ParseFacts();
    void ParseStringList();
    void ParseParameter();
    void ParseParameterList();
    void ParsePredicate();
    void ParsePredicateList();
    void ParseRules();
    void ParseHeadPredicate();
    void ParseSchemesList();
    void ParseFactsList();
    void ParseRulesList();
    void ParseQueries();
    void ParseQueriesList();
    void ParseExpression();
    void ParseOperator();
};