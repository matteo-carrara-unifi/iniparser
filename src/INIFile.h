#ifndef INIPARSER_INIFILE_H
#define INIPARSER_INIFILE_H

#include <string>
#include <vector>

#include "INIWriter.h"
#include "INISection.h"

using namespace std;


class INIFile {
public:
    INIFile(const string filename);
    ~INIFile();

    const vector<INISection*>& getSections() const {
        return sections;
    }

    void addSection();
    void removeSection();

    bool isOpen() const {
        return w->isOpen();
    }

private:
    INIWriter *w;
    vector<INISection*> sections;
};

#endif //INIPARSER_INIFILE_H
