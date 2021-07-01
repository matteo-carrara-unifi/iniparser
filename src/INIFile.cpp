#include "INIFile.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

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
    if(is_open == true)
        close();

    ifstream fs(filename);

    if(fs.is_open()) {
        is_open = true;
        string line;

        vector<pair<string,string>*> *tmpvalues;
        string section_name=""; // this means "global section", if no other sections are found but there are some key=value
        bool inside_section = false;
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
                    if (line.find(']') != (line.length()-1)) {
                        cout << "Invalid section termination" << endl;
                    }
                    else {
                        // good section found
                        if(inside_section == false && tmpvalues->size() != 0) {
                            // this is the global section
                            // TODO create a flag for the global section
                            sections.push_back(new INISection("", tmpvalues));
                            tmpvalues = new vector<pair<string,string>*>; // FIXME possible memory leak at the end
                            inside_section = true;
                            section_name = line.substr(1, line.length()-2); // saving this for later
                        }
                        if(inside_section == false && tmpvalues->size() == 0) {
                            inside_section = true;
                            section_name = line.substr(1, line.length()-2); // saving this for later
                        }
                        if(inside_section == true && tmpvalues->size() != 0) {
                            sections.push_back(new INISection(section_name, tmpvalues));
                            tmpvalues = new vector<pair<string,string>*>; // FIXME possible memory leak at the end
                            inside_section = true;
                            section_name = line.substr(1, line.length()-2); // saving this for later
                        }
            // FIXME aggiornare tmpvalues

                    }

                    break;


                default:
                    cout << "valore" << endl;
                    auto eq = line.find('=');
                    if(eq == string::npos) {
                        cout << "Invalid key" << endl;
                        break;
                    }

                    // good value

                    if (tmpvalues == nullptr) {
                        tmpvalues = new vector<pair<string,string>*>;
                    }

                    string key = line.substr(0, eq);
                    trim(key);
                    string value = line.substr(eq+1, string::npos);
                    trim(value);
                    tmpvalues->push_back(new pair(key, value));
                    break;
            }


            } // end of line iteration
            if(tmpvalues->size() != 0) {
                sections.push_back(new INISection(section_name, tmpvalues));
            }

            fs.close();
        }
    else
        cerr << "Cannot open file" << endl;
    // FIXME eccezione

}

void INIFile::close() {
    if(is_open) {
        is_open = false;
        cout << "Vector size is" << sections.size() << endl;
        for(int i = 0; i < sections.size(); i++) {
            cout << "deleting section " << sections[i]->getName() << endl;
            delete sections[i];
            sections.erase(sections.begin()+i);
        }
    }

}

void INIFile::addSection() {

}

void INIFile::removeSection() {

}

INIFile::~INIFile() {
    close();

}
