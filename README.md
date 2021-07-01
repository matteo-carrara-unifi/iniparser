# iniparser
C++ library to work with INI files

# Project status
At this moment, INI file reading seems to work fine but
file writing has not be implemented. Unit testing needs also
to be added.

# Usage
This is a small concept of what should be possible to do
with this library when the project will be completed:
```c++
#include <INIParser>

INIParser myfile("config.ini");

if(!myfile.isOpen())
    return 1;

for(auto &section: myfile)
    cout << section.getName() << endl;

auto mySection = myfile["mySection"];
for(auto &property: mySection) {
    cout << property.getName() << "," << property.getValue() << endl;
    
}

myfile["newSection"] = {{"IP", "192.168.1.2"}, {"Name", "laptop"}};
myfile["emptySection"] = {};
myfile["uglySection"].delSection();

myfile["section"]["property"].getValue();
myfile["section"]["property"] = "new custom value";
myfile["section"]["property"].delProp();
```

# Features 
(This is a list of wanted features, some are *still to be implemented*)

**INI file management**
* Open for reading (no live updates, file loaded in memory)
* File lock
* Writes in-place at every change
* No commit required
* Retains original formatting

**Sections**
* Global section is not supported at the moment
* Get a list of all sections
* Delete a section
* Add a new section

**Keys**
* Get all keys from a section
* Remove a key
* Add a new key

# Updates
Follow this project on [github](https://github.com/matteo-carrara-unifi/iniparser)
or email me at [matteo.carrara@stud.unifi.it](matteo.carrara@stud.unifi.it).