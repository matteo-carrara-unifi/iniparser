//
// Created by Matteo Carrara on 29/06/21.
//

#ifndef INIPARSER_INISECTION_H
#define INIPARSER_INISECTION_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>


using namespace std;

class INISection {
public:
    // TODO Destroy members
    INISection(const string name, vector<pair<string, string>*>* members): __name(name) {
        cout << "NEW SECTION ADDED: " << name << endl;
        for(auto &m: *members) {
            cout << "MEMBER: " << m->first << " >>> " << m->second << endl;
        }
    }

    const string &getName() const {return __name;}
    void getMembers();
    void addValue();
    void removeValue();

private:
    const string __name;
};


#endif //INIPARSER_INISECTION_H
