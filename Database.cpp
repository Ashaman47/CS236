#include "Database.h"
Database::Database(){}
void Database::addRelation(string Name, Scheme scheme){
    Relation newRelation(Name, scheme);
    relations.insert(pair<string, Relation>(Name, newRelation));
}
void Database::addTuplesToRelation(string Name, Tuple current){
        relations[Name].addTuple(current);
}
void Database::printDatabase(){
    map<string,Relation>::iterator it;
    for(it = relations.begin(); it != relations.end(); ++it){
   //    cout << it->first << " " << it->second.toStringScheme() << endl;;
    }

}
void Database::checkQuery(vector<string> queries, vector<int>isConstant){ 
    map<string,Relation>::iterator it;
    for(it = relations.begin(); it != relations.end(); ++it){
        if (queries[0] == it->first){
            it->second.cQ(queries, isConstant);
        }
    }
}