# iniparser
C++ library to work with INI files

# Usage
This is a small concept of what you can do with this library:
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
For more detailed information, please see the documentation
generated with *Doxygen*.

# Features
**INI file management**
* Open for reading (live file updates are not supported)
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
or write an email to [matteo.carrara@stud.unifi.it](matteo.carrara@stud.unifi.it).