/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INISECTION_H
#define INIPARSER_INISECTION_H

#include <string>
#include <vector>
#include <utility>

#include "INIProp.h"

using namespace std;


class INISection {
public:
    // tested
    INISection(const string &_name, const vector<pair<vector<string>, pair<string, string>>> &raw_keys, const vector<string> &_comments_before, bool is_global = false): name(_name), global(is_global) {
        this->comments_before = _comments_before;
        for(auto &k: raw_keys) {
            keys.emplace_back(k.second, k.first);
        }
    }


    const vector<string> &getComments() {
        return comments_before;
    }

    // tested
    const string getName() const {
        return name;
    }


    const vector<INIProp> &getProp() {
        return keys;
    }

    // tested
    bool isGlobal() const {
        return global;
    }

    // tested
    bool hasChanged() const {
        return has_changed;
    }

    // tested
    INIProp &operator[](const string &prop) {
        auto pos = find(keys.begin(), keys.end(), prop);
        if(pos == keys.end())
            throw invalid_argument("Property with the specified name does not exists!");

        return const_cast<INIProp &>(keys.at(distance(keys.begin(), pos)));
    }

    // tested
    bool operator==(const string &name) const {
        return name == getName();
    }

    // tested
    bool addKey(const pair<string, string> &to_ins);

    // tested
    bool delKey(const string &name);

    // tested
    bool addKey(const string &name, const string &value) {
        return addKey(make_pair(name, value));
    }

private:

    string name;
    bool global;
    bool has_changed = false;
    vector<INIProp> keys;
    vector<string> comments_before;
};


#endif //INIPARSER_INISECTION_H
