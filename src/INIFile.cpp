#include "INIFile.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;




INIFile::INIFile(const string filename) {
    w = new INIWriter(filename);
}


void INIFile::addSection() {

}

void INIFile::removeSection() {

}

INIFile::~INIFile() {
}
