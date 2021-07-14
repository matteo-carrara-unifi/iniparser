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
    INIFile(const string filename);
    ~INIFile();

    const vector<INISection>& getSections() const {
        return sections;
    }

    bool isOpen() const {
        return is_open;
    }

    void addSection();
    void removeSection();

private:
    vector<INISection> sections;
    bool is_open = false;
    fstream fs;
};


#endif //INIPARSER_INIFILE_H
