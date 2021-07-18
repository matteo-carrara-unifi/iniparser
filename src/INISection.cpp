/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#include "INISection.h"


bool INISection::addKey(const pair<string, string> &to_ins) {
    if(find(keys.begin(), keys.end(), to_ins.first) != keys.end())
        return false;

    vector<string> empty;
    keys.emplace_back(to_ins, empty);
    return has_changed = true;
}


bool INISection::delKey(const string &name) {
    auto pos = find(keys.begin(), keys.end(), name);

    if(pos == keys.end()) {
        return false;
    }
    else {
        keys.erase(pos);
        return has_changed = true;
    }
}
