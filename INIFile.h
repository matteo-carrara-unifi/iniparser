#ifndef INIPARSER_INIFILE_H
#define INIPARSER_INIFILE_H

#include <string>
using namespace std;

class INIFile {
public:
    INIFile();

    void open(const string filename);
    void commit();
    void close();

    void getSections();
    void addSection();
    void removeSection();

    bool isOpen() {return is_open;}

private:
    bool is_open = false;
    vector<string
};

#endif //INIPARSER_INIFILE_H
