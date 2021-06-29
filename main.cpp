//
// Created by Matteo Carrara on 29/06/21.
//

#include <iostream>
#include "INIFile.h"


using namespace std;

int main() {
    INIFile conf;
    conf.open("../sample.ini");
    cout << "hello world" << endl;
    return 0;
}
