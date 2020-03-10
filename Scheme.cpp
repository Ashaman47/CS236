#include "Scheme.h"

Scheme::Scheme(){
}
void Scheme::addScheme(string scheme){
    Schemes.push_back(scheme);
}
string Scheme::toString(){
    string g;
    for (unsigned int i = 0; i < Schemes.size(); ++i){
        g += Schemes[i];
        if (i < Schemes.size() - 1){
            g += " ";
        }
    }
    return g;
}
void Scheme::deleteScheme(){
    Schemes.clear();
}
void Scheme::erase(vector<int> i){
    for (unsigned int q = 0; q < Schemes.size(); ++q){
        for (unsigned int j = 0; j < Schemes.size(); ++j){
            if (q != static_cast<unsigned int>(i[j])){
                Schemes.erase(Schemes.begin() + q);
            }
        }
    }
    return;
}
string Scheme::receiveOneScheme(int i){
    return Schemes[i];
}
int Scheme::size(){
    return Schemes.size();
}