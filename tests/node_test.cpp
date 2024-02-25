#include <iostream>
#include <gtest/gtest.h>
#include "../src/Node/Node.cpp" // Include the header file for the code being tested

// Define a test case named NodeCreation
TEST(NodeCreation, node_ctor)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;

    // Assert: Verify the results
    EXPECT_EQ(ptr->buffer_size, 1);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value(1).first, 2.0);
}

TEST(NodeInsertion_1, node_insert1)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;
    node.insert(2, 3.0);
    EXPECT_EQ(ptr->buffer_size, 2);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value(2).first, 3.0);
}

TEST(NodeInsertion_2, node_insert2)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;
    node.insert(2, 3.0);
    node.insert(3, 4.0);

    EXPECT_EQ(ptr->buffer_size, 3);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value(1).first, 2.0);
    EXPECT_EQ(node.get_value(2).first, 3.0);
    EXPECT_EQ(node.get_value(3).first, 4.0);
}

TEST(NodeInsertion_3, node_insert3)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;
    node.insert(2, 3.0);
    node.insert(3, 4.0);
    node.insert(4, 5.0);

    EXPECT_EQ(ptr->buffer_size, 4);
    std::pair res = node.get_value(1);
    EXPECT_EQ(res.first, 2.0);
    EXPECT_TRUE(res.second);

    res = node.get_value(2);
    EXPECT_EQ(res.first, 3.0);
    EXPECT_TRUE(res.second);

    res = node.get_value(3);
    EXPECT_EQ(res.first, 4.0);
    EXPECT_TRUE(res.second);

    res = node.get_value(4);
    EXPECT_EQ(res.first, 5.0);
    EXPECT_TRUE(res.second);
    EXPECT_TRUE(node.is_full());
}

TEST(Node_get_value_return_false, node_get_value1)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;

    EXPECT_EQ(ptr->buffer_size, 1);
    std::pair res = node.get_value(1);
    EXPECT_EQ(res.first, 2.0);
    EXPECT_TRUE(res.second);

    res = node.get_value(4);
    EXPECT_EQ(res.first, 0.0);
    EXPECT_FALSE(res.second);
}
