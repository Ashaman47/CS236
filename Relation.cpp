#include "Relation.h"
Relation::Relation(string name, Scheme schemes){
    Name = name;
    scheme = schemes;
}
void Relation::addTuple(Tuple current){
    if (Tuples.size() == 0){
        Tuples.push_back(current);
        return;
    }
    for (unsigned int i = 0; i < Tuples.size(); ++i){
        if (current.toString() == Tuples[i].toString()){
            return;
        }
        
    }
    Tuples.push_back(current);
    return;
}
string Relation::toString(){
    string g;
    for (unsigned int i =0; i < Tuples.size(); ++i){
        g += Tuples[i].toString();
        g += "/ ";
    }
    return g;
}
string Relation::toStringScheme(){
    return scheme.toString();
}
void Relation::select(string queries, int i){
    i = i - 1;
    for (unsigned int j = 0; j < Tuples.size(); ++j){
        
        if(Tuples[j].compareTuple(queries, i) == false){
            
            Tuples.erase(Tuples.begin() + j);
            --j;
        }
    }
    return;
}
void Relation::select2(int j, int i){
    i--;
    j--;
    for (unsigned int q = 0; q < Tuples.size(); ++q){
        if (Tuples[q].receiveOneTuple(j) != Tuples[q].receiveOneTuple(i)){
            Tuples.erase(Tuples.begin() + q);
            q--;
        }
    }
    return;
}
void Relation::Project(vector<int>columns){
    vector<string> x;
        for (unsigned int j= 0; j < Tuples.size(); ++j){
            
            for (unsigned int i = 0; i < dupLocation.size(); ++i){
            x.push_back(Tuples[j].receiveOneTuple(dupLocation[i] -1));
            }
            scheme.erase(columns);
            Tuples[j].deleteTuple();
            for (unsigned int i = 0; i < x.size(); ++i){
                Tuples[j].addTuple(x[i]);
            }
            x.clear();
        }
            
    
    return;
    
}
void Relation::Rename(vector<string>queries){
    scheme.deleteScheme();
    for (unsigned int i = 1; i < queries.size(); ++i){
        scheme.addScheme(queries[i]);
    }
    return;
}
void Relation::cQ(vector<string>queries, vector<int>isConstant){
    vector<Tuple>Tuples2 = Tuples;
    cout << queries[0] << "(";
    for (unsigned int i = 1; i < queries.size() - 1; ++i){
        cout << queries[i] << ",";
    }
    cout << queries[queries.size() - 1] << ")? ";
    for (unsigned int i = 1; i < isConstant.size(); ++i){
        if (dupQuery.size() == 0 && isConstant[i] == 2){
            dupQuery.push_back(queries[i]);
            dupLocation.push_back(i);
        }
        else{
        int v = 0;
            for (unsigned int j = 0; j < dupQuery.size(); ++j){
                if(queries[i] == dupQuery[j] || isConstant[i] != 2){
                    v = 1;
                }
            }
            if (v == 0 && isConstant[i] == 2){
                dupQuery.push_back(queries[i]);
                dupLocation.push_back(i);
            }
            
        }
        if (isConstant[i] == 1){
            this->select(queries[i],i);
            for (unsigned int g = 0; g < Tuples.size();++g){
            }
        }
        for (unsigned int g = 0; g < queries.size(); ++g){
        for (unsigned int f = 0; f < dupQuery.size(); ++f){
            if (dupQuery[f] == queries[g]){
                this->select2(dupLocation[f],g);
            }
        }
        }
        }
        for (unsigned int i = 0; i < dupLocation.size(); ++i){
            columns.push_back(dupLocation[i]);
        }
        
    this->Rename(queries);
    if (dupQuery.size() != 0){
        this->Project(columns);
    }
    sort(Tuples.begin(), Tuples.end());
    if (Tuples.size() == 0){
        cout << "No" << endl;
    }
    else {
        cout << "Yes(" << Tuples.size() << ")" << endl;
        for (int i = 0; i < static_cast<int>(Tuples.size()); ++i){
            if (dupQuery.size() > 0) {
                cout << "  ";
                for (int j = 0; j < static_cast<int>(Tuples[i].size() - 1); ++j){
                cout << dupQuery[j] << "=" << Tuples[i].receiveOneTuple(j) << ", ";
                }
                cout << dupQuery[dupQuery.size() -1] << "=" << Tuples[i].receiveOneTuple(dupQuery.size() - 1) << endl;
            }
        }
        
    }
    columns.clear();
    dupQuery.clear();
    dupLocation.clear();
    Tuples = Tuples2;
    return;
}
