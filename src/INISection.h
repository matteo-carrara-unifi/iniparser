//
// Created by Matteo Carrara on 29/06/21.
//

#ifndef INIPARSER_INISECTION_H
#define INIPARSER_INISECTION_H

#include <string>
#include <iostream>
#include <vector>
#include <utility>

#include "INIWriter.h"
#include "INIProp.h"

using namespace std;


class INISection {
public:
    INISection(INIWriter *_w, raw_section *_sec): w(_w), sec(_sec) {
        for(auto &p: *sec->second) {
            properties.push_back(new INIProp(w, p));
        }
    }

    const string getName() const {
        return sec->first;
    }

    const vector<INIProp*> getProp() const {
        return properties;
    }

    void addValue();
    void removeValue();

private:
    INIWriter *w;
    raw_section *sec;
    vector<INIProp*> properties;
};


#endif //INIPARSER_INISECTION_H
