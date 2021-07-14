/* Copyright 2021 Matteo Carrara <matteo.carrara@stud.unifi.it> */

#include <iostream>
#include <filesystem>

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
    for(auto &s: myfile.getSections()) {
        cout << "Section name is " << s.getName() << endl;
        for (auto &p: s.getProp()) {
            cout << "Property name: " << p.getName() << endl << "Property value: " << p.getValue() << endl << endl;
        }
    }
}

TEST_F(INIFileSuite, TestAddSection) {
    myfile.addSection("NEW SECTION 123").addKey("random key", "lulz value");
    myfile["database"].addKey("New database key", "New database data");
}