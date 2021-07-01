//
// Created by Matteo Carrara on 01/07/21.
//

#include "INIWriter.h"


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


INIWriter::INIWriter(const string filename) {
    ifstream fs(filename);
    if(fs.is_open()) {
        this->is_open = true;
        string line;

        raw_key_group *tmpkeys = new raw_key_group;
        string section_name = ""; // FIXME global section
        bool inside_section = false;

        while (getline(fs, line)) {
            trim(line);
            if (line.length() == 0)
                continue;

            switch (line[0]) {
                // comment line
                case ';':
                    break;

                    // section
                case '[':
                    if (line.find(']') != (line.length() - 1)) {
                        // the ']' symbol should be only at the end of the line
                        // in order to be a valid section
                    } else {
                        // good section found
                        if (inside_section == false && tmpkeys->size() != 0) {
                            // FIXME temp solution
                            tmpkeys = new raw_key_group;
                            // this is the global section
                            // TODO implement proper global section handling
                            // sections.push_back(new INISection("", tmpkeys));
                            // tmpkeys = new vector<pair<string,string>*>; // FIXME possible memory leak at the end
                            // inside_section = true;
                            // section_name = line.substr(1, line.length()-2); // saving this for later
                        }
                        if (inside_section == false && tmpkeys->size() == 0) {
                            inside_section = true;
                        }
                        if (inside_section == true && tmpkeys->size() != 0) {
                            // end of previous section
                            raw_section *s = new raw_section(section_name, tmpkeys);
                            sections.push_back(s);
                            tmpkeys = new raw_key_group; // FIXME possible memory leak at the end
                        }
                        section_name = line.substr(1, line.length() - 2); // saving this for later
                    }
                    break;

                default:
                    // we found a property?
                    auto eq = line.find('=');
                    if (eq == string::npos) {
                        // nope
                        break;
                    }

                    // yes it's a valid key

                    string key = line.substr(0, eq);
                    string value = line.substr(eq + 1, string::npos);
                    trim(key);
                    trim(value);

                    tmpkeys->push_back(new raw_key(key, value));
                    break;
            }
        } // end of line iteration

        // this handles the keys of the last section
        if (tmpkeys->size() != 0) {
            raw_section *s = new raw_section(section_name, tmpkeys);
            sections.push_back(s);
        }

        fs.close();
    }
}

INIWriter::~INIWriter() {

}
