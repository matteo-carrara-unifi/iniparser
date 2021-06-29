#include "INIFile.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

INIFile::INIFile() {

}


void INIFile::open(const string filename) {
    ifstream fs(filename);

    if(fs.is_open()) {
        is_open = true;
        string line;
        while(getline(fs, line)) {
            trim(line);
            if(line.length() == 0)
                continue;

            cout << line << endl;
            switch(line[0]) {
                case ';':
                    cout << "commento" << endl;
                    break;
                case '[':
                    cout << "sezione" << endl;
                    break;
                default:
                    cout << "valore" << endl;
                    break;
            }

            }
            fs.close();
        }
    else
        cerr << "Cannot open file" << endl;
    // FIXME eccezione

}

void INIFile::commit() {

}

void INIFile::close() {
    is_open = false;
}

void INIFile::getSections() {

}

void INIFile::addSection() {

}

void INIFile::removeSection() {

}
