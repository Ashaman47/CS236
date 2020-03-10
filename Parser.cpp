#include "Parser.h"
#include "DatalogProgram.h"
#include <cctype>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>


Parser::Parser(vector<Token>tokenlist){
    tokenList = tokenlist;
    currenttoken = 0;
    ParseDatalogProgram();
    
}

void Parser::ParseDatalogProgram(){
    match("SCHEMES");
    match("COLON");
    ParseSchemes();
    ParseSchemesList();
    match("FACTS");
    match("COLON");
    ParseFacts();
    ParseFactsList();
    match("RULES");
    match("COLON");
    ParseRules();
    ParseRulesList();
    match("QUERIES");
    match("COLON");
    ParseQueries();
    ParseQueriesList();
    if (tokenList.size() != static_cast<unsigned int>(currenttoken)){
        cout << "Failure!" << endl;
        tokenList[currenttoken].printTokens();
        exit(0);
    }
    cout << "Success!" << endl;
    exit(0);
}
void Parser::match(string currenttype){
    if (tokenList[currenttoken].returnType() == currenttype){
        currenttoken++;
        if (tokenList.size() == static_cast<unsigned int>(currenttoken)){
            DB.printDatabase();
            exit(0);
        }
    }
    else {
        cout << "Failure!" << endl;
        tokenList[currenttoken].printTokens();
        exit(0);
    }
    return;
}
void Parser::ParseSchemes(){

    Pred = Predicate(tokenList[currenttoken].returnValue());
    match("ID");
    string ID = tokenList[currenttoken - 1].returnValue();
    match("LEFT_PAREN");
    match("ID");
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
    scheme.addScheme(tokenList[currenttoken - 1].returnValue());
    ParseIdList();
    match("RIGHT_PAREN");
    DB.addRelation(ID, scheme);
    DLP.addSchemes(Pred);
    scheme.deleteScheme();
}
void Parser::ParseSchemesList(){
    if (tokenList[currenttoken].returnType() == "ID"){
        ParseSchemes();
        ParseSchemesList();
    }
    else{}
}
void Parser::ParseIdList(){
    if (tokenList[currenttoken].returnType() == "COMMA"){
        match("COMMA");
        match("ID");
        Pred.AddParam(tokenList[currenttoken - 1].returnValue());
        scheme.addScheme(tokenList[currenttoken - 1].returnValue());
        ParseIdList();
    }
    else{
        
    }
    return;
}
void Parser::ParseFacts(){
    if (tokenList[currenttoken].returnType() == "ID"){
    Pred = Predicate(tokenList[currenttoken].returnValue());
    match("ID");
    string ID = tokenList[currenttoken - 1].returnValue();
    match("LEFT_PAREN");
    match("STRING");
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
    DLP.addDomain(tokenList[currenttoken - 1].returnValue());
    tuple.addTuple(tokenList[currenttoken -1].returnValue());
    ParseStringList();
    match("RIGHT_PAREN");
    match("PERIOD");
    DLP.addFacts(Pred);
    DB.addTuplesToRelation(ID, tuple);
    tuple.deleteTuple();
    }
    else if (tokenList[currenttoken].returnType() == "RULES"){}
    else {
        cout << "Failure!" << endl;
        tokenList[currenttoken].printTokens();
        exit(0);
    }
    return;
}
void Parser::ParseFactsList(){
    if (tokenList[currenttoken].returnType() == "ID"){
        ParseFacts();
        ParseFactsList();
    }
    else{}
    return;
}
void Parser::ParseStringList(){
    if (tokenList[currenttoken].returnType() == "COMMA"){
        match("COMMA");
        match("STRING");
        Pred.AddParam(tokenList[currenttoken - 1].returnValue());
        DLP.addDomain(tokenList[currenttoken - 1].returnValue());
        tuple.addTuple(tokenList[currenttoken -1].returnValue());
        ParseStringList();
    }
    else{}
    return;
}
void Parser::ParseRules(){
    if (tokenList[currenttoken].returnType() == "ID"){
    R = Rules();
    ParseHeadPredicate();
    match("COLON_DASH");
    ParsePredicate();
    ParsePredicateList();
    match("PERIOD");
    DLP.addRules(R);
    }
    else if (tokenList[currenttoken].returnType() == "QUERIES"){}
    else {
        cout << "Failure!" << endl;
        tokenList[currenttoken].printTokens();
        exit(0);
    }
    
    return;
}
void Parser::ParseRulesList() {
    if (tokenList[currenttoken].returnType() == "ID"){
        ParseRules();
        ParseRulesList();
    }
    else{}
    return;
}
void Parser::ParseHeadPredicate(){
    Pred = Predicate(tokenList[currenttoken].returnValue());
    match("ID");
    match("LEFT_PAREN");
    match("ID");
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
    ParseIdList();
    match("RIGHT_PAREN");
    R.addRule(Pred);
    return;
}
void Parser::ParsePredicate(){
    Pred = Predicate(tokenList[currenttoken].returnValue());
    match("ID");
    if (querycheck == 1){
    isConstant.push_back(0);
    queries.push_back(tokenList[currenttoken - 1].returnValue());
    }
    
    match("LEFT_PAREN");
    ParseParameter();
    ParseParameterList();
    match("RIGHT_PAREN");
    R.addRule(Pred);
    DB.checkQuery(queries,isConstant);
    queries.clear();
    isConstant.clear();
    return;
}
void Parser::ParsePredicateList(){
    if (tokenList[currenttoken].returnType() == "COMMA"){
        match("COMMA");
        ParsePredicate();
        ParsePredicateList();
    }
    else{}
    return;
}
void Parser::ParseParameterList(){
    if (tokenList[currenttoken].returnType() == "COMMA"){
        match("COMMA");
        ParseParameter();
        ParseParameterList();
    }
    else{}
    return;
}
void Parser::ParseQueries(){
    querycheck = 1;
    ParsePredicate();
    DLP.addQueries(Pred);
    match("Q_MARK");
    querycheck = 0;
    return;
}
void Parser::ParseQueriesList(){
    if (tokenList[currenttoken].returnType() == "ID"){
        ParseQueries();
        ParseQueriesList();
    }
    else{}
    return;
}
void Parser::ParseParameter() {
    if (tokenList[currenttoken].returnType() == "STRING"){
        match("STRING");
        queries.push_back(tokenList[currenttoken - 1].returnValue());
        isConstant.push_back(1);
    }
    else if (tokenList[currenttoken].returnType() == "ID"){
        match("ID");
        
        queries.push_back(tokenList[currenttoken - 1].returnValue());
        isConstant.push_back(2);
    }
    else if (tokenList[currenttoken].returnType() == "LEFT_PAREN"){
        ParseExpression();
        return;
    }
    else{
        cout << "Failure!" << endl;
        tokenList[currenttoken].printTokens();
        exit(0);
    }
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
    return;
}
void Parser::ParseExpression(){
    match("LEFT_PAREN");
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
    ParseParameter();
    ParseOperator();
    ParseParameter();
    match("RIGHT_PAREN");
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
    return;
}
void Parser::ParseOperator(){
    if(tokenList[currenttoken].returnType() == "ADD"){
        match("ADD");
    }
    else if (tokenList[currenttoken].returnType() == "MULTIPLY"){
        match("MULTIPLY");
    }
    else{
        cout << "Failure!" << endl;
        tokenList[currenttoken].printTokens();
        exit(0);
    }
    Pred.AddParam(tokenList[currenttoken - 1].returnValue());
}