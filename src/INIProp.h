/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INIPROP_H
#define INIPARSER_INIPROP_H

#include <utility>
#include <string>

using namespace std;


class INIProp {
public:
    INIProp(const pair<string, string> &_desc): desc(_desc) {

    }

    const string getName() const {
        return desc.first;
    }

    const string getValue() const {
        return desc.second;
    }

private:
    pair<string, string> desc;
};


#endif //INIPARSER_INIPROP_H
