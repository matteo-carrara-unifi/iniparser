//
// Created by Matteo Carrara on 29/06/21.
//

#include <iostream>
#include "../src/INIFile.h"


using namespace std;

int main() {
    INIFile ini;
    ini.open("../sample.ini");
    for(auto &sec: ini.getSections()) {
        cout << "MAIN: got section " << sec->getName() << endl;
        for(auto &item: *sec->getMembers()) {
            cout << "MAIN: got member with key = " << item->first << " and value = " << item->second << endl;
        }
    }


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
