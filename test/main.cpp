//
// Created by Matteo Carrara on 29/06/21.
//

#include <iostream>
#include "../src/INIFile.h"

using namespace std;


int main() {
    INIFile myfile("../test/sample.ini");

    if(!myfile.isOpen())
        cout << "Error opening file\n";
    else
        cout << "File read correctly\n";

    for(auto &s: myfile.getSections()) {
        cout << "GOT section " << s->first << endl;
        for(auto &m: *s->second) {
            cout << "RAW KEY: " << m->first << "=" << m->second << endl;
        }
        }

    return 0;
}
