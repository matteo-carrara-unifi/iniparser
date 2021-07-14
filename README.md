# iniparser
C++ library to work with INI files


# Usage
This is a small concept of what is possible to do
with this library:
```c++
#include <INIParser>

INIParser myfile("config.ini");

if(!myfile.isOpen())
    return 1;

for(auto &section: myfile.getSections())
    cout << section.getName() << endl;

auto mySection = myfile["mySection"];
for(auto &property: mySection.getProp()) {
    cout << property.getName() << "," << property.getValue() << endl;
    
}

myfile.addSection("newSection").addKey("IP", "192.168.1.2");
myfile["section"].getProp()[0].getName(); // IP
myfile.removeSection("newSection");

```

# Features 


**INI file management**
* Open for reading (no live updates, file loaded in memory)
* Buffered changes
* Changes can be written at any time or automaticaly when object gets destroyed

**Sections**
* Global section support
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
