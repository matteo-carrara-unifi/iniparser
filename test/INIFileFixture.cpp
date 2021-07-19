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
            std::filesystem::copy("./test/sample2.ini", "./test/sample.ini", std::filesystem::copy_options::overwrite_existing);
        } catch (std::filesystem::filesystem_error& e) {
            std::cout << e.what() << '\n';
        }
        myfile.open("./test/sample.ini");
    }

    virtual void TearDown() override {

    }

    const string new_sec_name = "NEW SECTION 123";
    INIFile myfile;
};


TEST_F(INIFileSuite, TestOpen) {
    ASSERT_TRUE(myfile.isOpen());

    INIFile TestErr("barambani.ini");
    ASSERT_FALSE(TestErr.isOpen());
}


TEST_F(INIFileSuite, TestGetSection) {
    vector<string> correctSections = {"", "database", "this is another section", "this is an empty section", "this section is not empty"};

    int i = 0;
    int global_cnt = 0;

    for(auto &s: myfile.getSections()) {
        ASSERT_EQ(s.getName(), correctSections[i++]);
        if(s.isGlobal())
            global_cnt++;
    }

    ASSERT_EQ(global_cnt, 1);
}


TEST_F(INIFileSuite, TestSectionHandling) {

    auto &s1 = myfile.addSection(new_sec_name);

    EXPECT_NO_THROW({myfile[new_sec_name];});
    ASSERT_TRUE(myfile.hasChanged());

    myfile.removeSection(new_sec_name);
    EXPECT_THROW({myfile[new_sec_name];}, invalid_argument);
}


TEST_F(INIFileSuite, TestKeyHandling) {
    INISection &s1 = myfile["database"];
    ASSERT_FALSE(s1.isGlobal());

    s1.addKey("random key", "lulz value");
    ASSERT_FALSE(s1.addKey("random key", "another value"));
    ASSERT_TRUE(s1.hasChanged());


    EXPECT_NO_THROW(s1["random key"]);
    EXPECT_THROW({s1["chiave non esistente"];}, invalid_argument);

    ASSERT_TRUE(s1.delKey("random key"));
    ASSERT_FALSE(s1.delKey("random key"));

    ASSERT_TRUE(s1 == "database");
}


TEST_F(INIFileSuite, TestSectionComments) {
    myfile.writeChanges();

    INISection& s1 = myfile["this is another section"];

    ASSERT_EQ(s1.getComments().size(), 1);
    ASSERT_EQ(s1.getComments()[0], "; comment before a section");
}


TEST_F(INIFileSuite, TestSectKeys) {
    vector<vector<string>> correct = {
            {"server", "192.0.2.62"},
            {"port",   "143"},
            {"file",   "\"payroll.dat\""}
    };

    INISection &s = myfile["database"];
    ASSERT_EQ(s.getProp().size(), correct.size());

    for(int i = 0; i < correct.size(); i++) {
        ASSERT_EQ(s.getProp()[i], correct[i][0]);
        ASSERT_EQ(s[correct[i][0]].getValue(), correct[i][1]);
    }
}


TEST_F(INIFileSuite, TestKeyClass) {
    INISection &s = myfile["database"];

    ASSERT_EQ(s["server"].getName(), "server");
    ASSERT_EQ(s["server"].getValue(), "192.0.2.62");

    ASSERT_TRUE(s["port"] == "port");
    ASSERT_EQ(s["server"].getComments()[0], "; use IP address in case network name resolution is not working");
}

