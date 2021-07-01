#ifndef INIPARSER_INIFILE_H
#define INIPARSER_INIFILE_H

#include <string>
#include <vector>

#include "INISection.h"

using namespace std;


class INIFile {
public:
    INIFile(); // TODO open file in constructor
    ~INIFile();

    void open(const string filename); // TODO exception
    void close(); // TODO private

    // TODO Operator overloading
    const vector<INISection*>& getSections() const {return sections;}
    void addSection();
    void removeSection();

    bool isOpen() {return is_open;}

private:
    bool is_open = false;
    vector<INISection*> sections;
};

#endif //INIPARSER_INIFILE_H
