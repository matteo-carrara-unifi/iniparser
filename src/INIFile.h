/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INIFILE_H
#define INIPARSER_INIFILE_H

#include <fstream>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "INISection.h"

using namespace std;


class INIFile {
public:
    INIFile(const string _filename);
    ~INIFile(); // FIXME write buffer

    const vector<INISection>& getSections() const {
        return sections;
    }

    bool isOpen() const {
        return is_open;
    }

    bool addSection(const string name);
    bool removeSection(const string name);
    bool hasChanged();
    bool writeChanges();

private:
    vector<INISection> sections;
    bool is_open = false;
    bool has_changed = false;
    string filename;
};


#endif //INIPARSER_INIFILE_H
