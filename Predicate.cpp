#include "DatalogProgram.h"
#include "Rules.h"
#include "Predicate.h"
#include <cctype>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>


Predicate::Predicate(string currentToken){
    ID = currentToken;
}
string Predicate::toString(){
    stringstream ss;
    ss << ID << "(";
    for(unsigned int i = 0; i < ParamList.size(); i++){
		if(i == 0 ||ParamList[i].toString() == ")"||ParamList[i - 1].toString() == "("){
			ss << ParamList[i].toString();
		}
		else if (ParamList[i].toString() == "+" ||ParamList[i].toString() == "*") {
		    ss << ParamList[i].toString();
		    ++i;
		    ss << ParamList[i].toString();
		}
		else{
			ss << "," << ParamList[i].toString();
		}
	}
    ss << ")";
    return ss.str();
}
string Predicate::toStringDomain(){
    stringstream ss;
    for(unsigned int i = 0; i < DomainList.size(); i++){
			ss << "  " << DomainList[i].toString() << endl;
	}
    return ss.str();
}
void Predicate::AddParam(string currentTokenList){
    ParamList.push_back(currentTokenList);
    //for (unsigned int i = 0; i < ParamList.size(); ++i){
    //    cout << ParamList[i].toString() << endl;
    //}
    return;
}
