#include <gtest/gtest.h>

// Declare the function to run the tests from node_test.cpp
extern void runNodeCreationTests();

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

