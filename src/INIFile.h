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

    // TODO Operator overloading
    // TODO custom classes
    const vector<raw_section*>&  getSections() const {return w->getRawSections();};
    void addSection();
    void removeSection();

    bool isOpen() const {return w->isOpen();};

private:
    INIWriter *w;
};

#endif //INIPARSER_INIFILE_H
