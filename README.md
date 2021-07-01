# iniparser
C++ library to work with INI files

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

# Usage

```c++
#include <INIParser>

INIParser myfile("config.ini");

if(!myfile.isOpen())
    return 1;

auto sections = myfile.getSections();
```

# Updates
Follow this project on [github](https://github.com/matteo-carrara-unifi/iniparser)
or write an email to [matteo.carrara@stud.unifi.it](matteo.carrara@stud.unifi.it).