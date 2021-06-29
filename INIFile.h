#ifndef INIPARSER_INIFILE_H
#define INIPARSER_INIFILE_H

class INIFile {
public:
    INIFile();

    void open();
    void commit();
    void close();

    void getSections();
    void addSection();
    void removeSection();
};

#endif //INIPARSER_INIFILE_H
