//
// Created by Matteo Carrara on 29/06/21.
//

#include <iostream>
#include "INIParser.h"


using namespace std;

int main() {
    INIParser ini;
    ini.open("../sample.ini");
    for(auto &sec: ini.getSections())
        cout << "MAIN: got section " << sec->getName() << endl;
    ini.close();

    // ini.open()
    // ini.isOpen()
    // ini.close()

    // ini.getSections()
    // ini.addSection()
    // ini.removeSection()

    // section.getKeys()
    // section.removeKey()
    // section.addKey()

    // key.getValue()



    return 0;
}
