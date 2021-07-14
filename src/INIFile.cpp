/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#include "INIFile.h"


inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
        return !std::isspace(ch);
    }));
}


inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
        return !std::isspace(ch);
    }).base(), s.end());
}


inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}


INIFile::INIFile(const string filename) {
    fs.open(filename);
    if(fs.is_open()) {
        this->is_open = true;

        string line;
        int linecnt = 0;
        string section_name = "";
        bool inside_section = false;
        vector<pair<string, string>> tmpkeys;

        while (getline(fs, line)) {
            linecnt++;
            trim(line);

            if (line.length() == 0)
                continue;

            switch (line[0]) {
                case ';':
                    break;

                case '[':
                    // In order to be a valid section, the ']' symbol should be
                    // at the end of the line
                    if (line.find(']') == (line.length() - 1)) {
                        sections.emplace_back(section_name, tmpkeys, !inside_section);
                        tmpkeys.clear();
                        inside_section = true;
                        section_name = line.substr(1, line.length() - 2);
                    }
                    break;

                default:
                    // this must be a property...
                    auto eq = line.find('=');
                    if (eq == string::npos)
                        break; // it wasn't

                    string key = line.substr(0, eq);
                    string value = line.substr(eq + 1, string::npos);
                    trim(key);
                    trim(value);
                    tmpkeys.emplace_back(key, value);
            }
        }

        // this handles the keys of the last section
        sections.emplace_back(section_name, tmpkeys, !inside_section);
    }
}


void INIFile::addSection() {

}


void INIFile::removeSection() {

}


INIFile::~INIFile() {
    fs.close();
}
