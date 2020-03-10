#include "Tuple.h"
void Tuple::addTuple(string current){
    Tuples.push_back(current);
    return;
}
bool Tuple::compareTuple(string queries, int i){
        if (queries == Tuples[i]){
            return true;
        }
    return false;
}
string Tuple::toString(){
    string g;
    for (unsigned int i = 0; i < Tuples.size(); ++i){
        g += Tuples[i];
        if (i < Tuples.size() - 1){
            g += " ";
        }
    }
    return g;
}
void Tuple::deleteTuple(){
    Tuples.clear();
    return;
}
bool Tuple::findDuplicateTuple(){
    for (unsigned int i = 0; i < Tuples.size();++i){
        for (unsigned int j = 0;j < Tuples.size(); ++j){
            if (Tuples[i] == Tuples[j] && i != j){
                return true;
            }
        }
    }
    return false;
}
string Tuple::receiveOneTuple(int i){
    return Tuples[i];
}
bool operator<(Tuple &s1, Tuple &s2){
    return s1.toString() < s2.toString();
}
int Tuple::size(){
    return Tuples.size();
}