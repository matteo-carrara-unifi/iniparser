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
        cout << "Section name is " << s.getName() << endl;
        for(auto &p: s.getProp()) {
            cout << "Property name: " << p.getName() << endl << "Property value: " << p.getValue() << endl << endl;
        }
    }

    return 0;
}
