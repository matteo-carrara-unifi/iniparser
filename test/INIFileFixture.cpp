/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

#include "gtest/gtest.h"
#include "../src/INIFile.h"


class INIFileSuite : public ::testing::Test {

protected:
    virtual void SetUp() override {
        try {
            std::filesystem::copy("../test/sample2.ini", "../test/sample.ini", std::filesystem::copy_options::overwrite_existing);
        } catch (std::filesystem::filesystem_error& e) {
            std::cout << e.what() << '\n';
        }
    }

    virtual void TearDown() override {

    }

    INIFile myfile{"../test/sample.ini"};
};


TEST_F(INIFileSuite, TestOpen) {
    ASSERT_EQ(myfile.isOpen(), true);
}

TEST_F(INIFileSuite, TestGetSection) {
    vector<string> correctSections = {"", "database", "this is another section", "this is an empty section", "this section is not empty"};

    int i = 0;
    for(auto &s: myfile.getSections()) {
        ASSERT_EQ(s.getName(), correctSections[i++]);
    }
}

TEST_F(INIFileSuite, TestWrite) {
    const string name = "NEW SECTION 123";
    auto s1 = myfile.addSection(name);

    EXPECT_NO_THROW({
        myfile[name];
    });

    s1.addKey("random key", "lulz value");
    bool keyfound = false;
    for(auto &k: s1.getProp()) {
        if(k.getName() == "random key") {
            keyfound = true;
            break;
        }
    }
    ASSERT_TRUE(keyfound);

    EXPECT_NO_THROW({
        myfile["database"].addKey("New database key", "New database data");
    });
}