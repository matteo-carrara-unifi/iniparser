#include "INIFile.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;




INIFile::INIFile(const string filename) {
    w = new INIWriter(filename);
    for(auto &s: w->getRawSections()) {
        sections.push_back(new INISection(w, s));
    }
}


void INIFile::addSection() {

}

void INIFile::removeSection() {

}

INIFile::~INIFile() {
}
