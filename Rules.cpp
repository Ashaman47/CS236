#include "Rules.h"
#include <cctype>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
Rules::Rules(Predicate p){
    Pred = p;
}
void Rules::addRule(Predicate P){
    PredList.push_back(P);
    return;
}
string Rules::toString(){
    stringstream ss;
    ss << PredList[0].toString() << " :- ";
    for(unsigned int i = 1; i < PredList.size(); i++){
		if(i == 1){
			ss << PredList[i].toString();
		}
		else{
			ss << "," << PredList[i].toString();
		}
	}
    ss << ".";
    return ss.str();
}