/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INISECTION_H
#define INIPARSER_INISECTION_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>

#include "INIProp.h"

using namespace std;


class INISection {
public:
    INISection(const string _name, const vector<pair<string, string>> &raw_keys, bool is_global = false): name(_name), global(is_global) {
        for(auto &k: raw_keys) {
            keys.emplace_back(k);
        }
    }


    const string getName() const {
        return name;
    }


    const vector<INIProp> &getProp() const {
        return keys;
    }


    bool isGlobal() {
        return global;
    }

    void addValue();
    void removeValue();

private:
    const string name;
    const bool global;
    vector<INIProp> keys;
};


#endif //INIPARSER_INISECTION_H
