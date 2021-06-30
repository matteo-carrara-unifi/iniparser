#ifndef INIPARSER_INIPARSER_H
#define INIPARSER_INIPARSER_H

#include <string>
#include <vector>

#include "INISection.h"

using namespace std;

class INIParser {
public:
    INIParser();
    ~INIParser();

    void open(const string filename);
    void close();

    const vector<INISection*>& getSections() const {return sections;}
    void addSection();
    void removeSection();

    bool isOpen() {return is_open;}

private:
    bool is_open = false;
    vector<INISection*> sections;
};

#endif //INIPARSER_INIPARSER_H
