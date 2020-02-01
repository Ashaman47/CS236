#include "Predicate.h"
#include "DatalogProgram.h"
#include <algorithm> 


DatalogProgram::DatalogProgram(){
    
}
void DatalogProgram::addSchemes(Predicate s){
    SchemesList.push_back(s);
    return;
}
void DatalogProgram::addQueries(Predicate q){
    QueriesList.push_back(q);
    return;
}
void DatalogProgram::addFacts(Predicate f){
    FactsList.push_back(f);
    return;
}
void DatalogProgram::addRules(Rules r){
    RulesList.push_back(r);
    return;
}
void DatalogProgram::addDomain(string f){
    for (unsigned int i = 0; i < DomainList.size(); ++i){
            if (f == DomainList[i]){
                return;
            }
    }
    DomainList.push_back(f);
    sort(DomainList.begin(),DomainList.end());
}
void DatalogProgram::Print(){
    cout << "Schemes(" << SchemesList.size() << "):" << endl;
    for (unsigned int i = 0; i < SchemesList.size(); ++i){
        cout << "  " << SchemesList[i].toString() << "." << endl;
    }
    cout << "Facts(" << FactsList.size() << "):" << endl;
    for (unsigned int i = 0; i < FactsList.size(); ++i){
        cout << "  " << FactsList[i].toString() << "." << endl;
    }
    cout << "Rules(" << RulesList.size() << "):" << endl;
    for (unsigned int i = 0; i < RulesList.size(); ++i){
        cout << "  " << RulesList[i].toString() << endl;
    }
    cout << "Queries(" << QueriesList.size() << "):" << endl;
    for (unsigned int i = 0; i < QueriesList.size(); ++i){
        cout << "  " << QueriesList[i].toString() << "?" << endl;
    }
    cout << "Domain(" << DomainList.size() << "):" << endl;
    for (unsigned int i = 0; i < DomainList.size(); ++i){
        cout << DomainList[i] << endl;
    }
    
}