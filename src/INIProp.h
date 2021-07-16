/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INIPROP_H
#define INIPARSER_INIPROP_H

#include <utility>
#include <string>

using namespace std;


class INIProp {
public:
    INIProp(const pair<string, string> &_desc, const vector<string> &_comments_before): desc(_desc), comments_before(_comments_before) {

    }

    const string getName() const {
        return desc.first;
    }

    const string getValue() const {
        return desc.second;
    }

    bool operator==(const string name) const {
        return name == getName();
    }

    const vector<string> &getComments() const {
        return comments_before;
    }

private:
    pair<string, string> desc;
    vector<string> comments_before;
};


#endif //INIPARSER_INIPROP_H
