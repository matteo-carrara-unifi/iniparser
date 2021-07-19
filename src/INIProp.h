/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INIPROP_H
#define INIPARSER_INIPROP_H

#include <utility>
#include <string>

using namespace std;

typedef pair<string, string> raw_key;
typedef vector<string> raw_comm;


class INIProp {
public:
    // tested
    INIProp(const pair<string, string> &_desc, const vector<string> &_comments_before): desc(_desc), comments_before(_comments_before) {

    }

    // tested
    const string getName() const {
        return desc.first;
    }

    // tested
    const string getValue() const {
        return desc.second;
    }

    // tested
    bool operator==(const string &name) const {
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
