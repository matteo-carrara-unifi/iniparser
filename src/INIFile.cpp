/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#include "INIFile.h"
#include "INIProp.h"
#include "utility.h"

INIFile::INIFile(const string &fname) {
    open(fname);
}

void INIFile::open(const string &fname) {
    this->filename = fname;

    if(!std::filesystem::exists(fname)) {
        return;
    }

    ifstream fs(filename);

    if(fs.is_open()) {
        this->is_open = true;

        string line;
        string section_name = "";
        bool inside_section = false;
        vector<pair<raw_comm, raw_key>> tmpkeys;
        vector<string> comments;
        vector<string> sec_com;

        while (getline(fs, line)) {
            trim(line);
            if (line.length() == 0)
                continue;
            switch (line[0]) {
                case ';':
                    comments.push_back(line);
                    break;

                case '[':
                    // In order to be a valid section, the ']' symbol should be
                    // at the end of the line
                    if (line.find(']') == (line.length() - 1)) {

                        sections.emplace_back(section_name, tmpkeys, sec_com, !inside_section);
                        sec_com = comments;
                        comments.clear();
                        tmpkeys.clear();
                        inside_section = true;
                        section_name = line.substr(1, line.length() - 2);
                    }
                    else {
                        syntaxError();
                    }
                    break;

                default:
                    // this must be a property...
                    auto eq = line.find('=');
                    if (eq == string::npos) {
                        syntaxError();
                        break; // it wasn't
                    }

                    string key = line.substr(0, eq);
                    string value = line.substr(eq + 1, string::npos);
                    trim(key);
                    trim(value);
                    tmpkeys.emplace_back(comments, make_pair(key, value));
                    comments.clear();
            }
        }

        // this handles the keys of the last section
        sections.emplace_back(section_name, tmpkeys, comments, !inside_section);
    }
    fs.close();
}


INIFile::~INIFile() {
    writeChanges();
}


INISection& INIFile::addSection(const string &name) {
    if(find(sections.begin(), sections.end(), name) != sections.end())
        throw invalid_argument("Cannot add the section with the specified name because it already exists");

    vector<pair<vector<string>, pair<string, string>>> no_keys;
    vector<string> no_com;
    sections.emplace_back(name, no_keys, no_com);
    has_changed = true;
    return sections.at(sections.size()-1);
}


bool INIFile::removeSection(const string &name) {
    auto pos = find(sections.begin(), sections.end(), name);
    if(pos == sections.end())
        return false;

    sections.erase(pos);
    return has_changed = true;
}


bool INIFile::hasChanged() const {
    if(has_changed)
        return true;

    for(auto &s: sections){
        if(s.hasChanged())
            return true;
    }

    return false;
}


bool INIFile::writeChanges() {
    if(!isOpen())
        return false;
    //if(!hasChanged())
        //return false;

    std::ofstream ofs;
    ofs.open(filename, std::ofstream::out | std::ofstream::trunc);
    for(auto &s: sections) {
        for(auto &comment: s.getComments())
            ofs << comment << endl;
        if(!s.isGlobal()) {
            ofs << "[" << s.getName() << "]" << endl;
        }

        for(auto &k: s.getProp()) {
            for(auto &comment: k.getComments())
                ofs << comment << endl;
            ofs << k.getName() << " = " << k.getValue() << endl;
        }
        ofs << endl;
    }
    ofs.close();
    has_changed = false;

    return true;
}


INISection &INIFile::getSection(const string &sec_name) const {
    auto pos = find(sections.begin(), sections.end(), sec_name);
    if(pos == sections.end())
        throw invalid_argument("Section with the specified name does not exists!");

    return const_cast<INISection &>(sections.at(distance(sections.begin(), pos)));
}
