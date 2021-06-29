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
        vector<string> sections;

        string line;
        while(getline(fs, line)) {
            cout << line << endl;

            /*bool line_comment = false;
            bool line_section = false;
            bool line_key = false;

            string section_name;


            bool leading_space = true;
            int section_name_starts = 0, section_name_ends = 0;

            int key_starts = 0;
            string key_name = "";
            int key_trailing_spaces = 0;


            // start character iteration
            for(int i = 0; i < line.length(); i++) {


               if((line[i] == ' ') && leading_space) continue;
               else {
                   if (leading_space) { // first non-space char
                       leading_space = false;

                       if (line[i] == ';') { // line is a comment
                           line_comment = true;
                           cout << "comment" << endl;
                           break;  // not useful for our purpose
                       }

                       else if (line[i] == '[') { // line is a section
                           line_section = true;
                           section_name_starts = i+1;
                           cout << "section" << endl;
                           continue;
                       }

                       else {
                           // after some spaces we found a character
                           // so this is a key
                           line_key = true;
                           key_starts=i;
                           cout << "key" << endl;
                           continue;
                       }
                   } // we are after leading space

                   if(line_key) {
                       if(line[i] == ' ' && key_name == "") {
                           key_trailing_spaces++;
                           if(i == (line.length()-1)) {
                               cout << "Missing key value";
                           }
                       }
                       else if (line[i] == '=' && key_name == "") {
                           key_name = line.substr(key_starts, i-key_trailing_spaces-key_starts);
                           cout << "KEY NAME =" << key_name << endl;
                       }


                   }

                   if(line_section) {
                       if(section_name_ends != 0)
                           cout << "Error: found charachters after the end of the section " << endl;
                       else if(line[i] == ']') {
                               section_name_ends = i-1;
                               cout << "SECTION NAME IS = " << line.substr(section_name_starts, i-section_name_starts) << endl;
                       }


                   }



               }*/
            }
            // end of char iteration
            is_open = true;
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
