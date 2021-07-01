//
// Created by Matteo Carrara on 29/06/21.
//

#ifndef INIPARSER_INIPROP_H
#define INIPARSER_INIPROP_H

#include "INIWriter.h"


class INIProp {
public:
    INIProp(INIWriter *_w, raw_key *_k): w(_w), k(_k) {

    }

    const string getName() const {
        return k->first;
    }

    const string getValue() const{
        return k->second;
    }

private:
    INIWriter *w;
    raw_key *k;
};


#endif //INIPARSER_INIPROP_H
