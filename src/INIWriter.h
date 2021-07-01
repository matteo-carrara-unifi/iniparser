//
// Created by Matteo Carrara on 01/07/21.
//

#ifndef INIPARSER_INIWRITER_H
#define INIPARSER_INIWRITER_H

#include <fstream>
#include <utility>
#include <iostream>
#include <string>
#include <vector>


using namespace std;
typedef pair<string,string> raw_key;
typedef vector<raw_key*> raw_key_group;
typedef pair<string, raw_key_group*> raw_section;


class INIWriter {
public:
    INIWriter(const string filename);
    ~INIWriter();

    bool isOpen() const {return is_open;}
    const vector<raw_section*>& getRawSections() const {return sections;};

private:
    bool is_open = false;
    vector<raw_section*> sections;
};


#endif //INIPARSER_INIWRITER_H
