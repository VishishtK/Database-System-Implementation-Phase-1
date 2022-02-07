#include "gtest/gtest.h"
#include "DBFile.h"

class DBFileTest : public ::testing::Test {
protected:
    DBFileTest() {
        // You can do set-up work for each test here.
    }

    ~DBFileTest() override {
        // You can do clean-up work that doesn't throw exceptions here.
    }
    void SetUp() override {
        // Code here will be called immediately after the constructor (right
        // before each test).
        dbfile = new DBFile();
    }

    void TearDown() override {
        // Code here will be called immediately after each test (right
        // before the destructor).
    }

    DBFile* dbfile;
};

TEST_F(DBFileTest, CreateTest) {
    EXPECT_EQ(dbfile->Create("/Users/vishy/parsedData/test.bin", heap, NULL), 1);
}

TEST_F(DBFileTest, OpenTest) {
    EXPECT_EQ(dbfile->Open("/Users/vishy/parsedData/lineitem.bin"), 1);
}

TEST_F(DBFileTest, CloseTest) {
    EXPECT_EQ(dbfile->Close(), 1);
}

TEST_F(DBFileTest, OpenAndCloseTest) {
    dbfile->Open("/Users/vishy/parsedData/lineitem.bin");
    EXPECT_EQ(dbfile->Close(), 1);
}

TEST_F(DBFileTest, CreateAndCloseTest) {
    dbfile->Create("/Users/vishy/parsedData/test.bin", heap, NULL);
    EXPECT_EQ(dbfile->Close(), 1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}