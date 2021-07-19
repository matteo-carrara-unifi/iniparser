/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#ifndef INIPARSER_INIFILE_H
#define INIPARSER_INIFILE_H

#include <fstream>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <exception>

#include "INISection.h"

using namespace std;


class INIFile {
public:
    // tested
    INIFile(const string &fname);
    ~INIFile();

    // tested
    const vector<INISection>& getSections() const {
        return sections;
    }

    // tested
    bool isOpen() const {
        return is_open;
    }

    // tested
    INISection& addSection(const string &name);

    // tested
    // Section names are unique
    INISection& getSection(const string &sec_name) const;

    // tested
    bool removeSection(const string &name);

    // tested
    bool hasChanged() const;

    // tested (destructor)
    bool writeChanges();

    // tested
    INISection& operator[](const string &sec_name) {
        return getSection(sec_name);
    }

private:
    void syntaxError() {
        syntax_error = true;
        write_enabled = false;
    }

    vector<INISection> sections;
    bool is_open = false; // FIXME Never checked
    bool has_changed = false;
    bool syntax_error = false; // TODO Implement
    bool write_enabled = true;
    string filename;
};


#endif //INIPARSER_INIFILE_H
