#include <iostream>
#include <gtest/gtest.h>
#include "../src/Node/Node.cpp"
#include "../src/Hasher/Hasher.h"

// Define a test case named NodeCreation
TEST(NodeCreation_int_double, node_ctor_int_double)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;

    // Assert: Verify the results
    EXPECT_EQ(ptr->buffer_size, 1);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value(1).first, 2.0);
}

TEST(NodeInsertion_1_int_double, node_insert1_int_double)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;
    node.insert(2, 3.0);
    EXPECT_EQ(ptr->buffer_size, 2);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value(2).first, 3.0);
}

TEST(NodeInsertion_2_int_double, node_insert2_int_double)
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

TEST(NodeInsertion_3_int_double, node_insert3_int_double)
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

TEST(NodeCreation_string_char, node_ctor_string_char)
{
    Node<std::string, char> node("Test1", 'A');
    Node_data<std::string, char> *ptr = node.node;

    // Assert: Verify the results
    EXPECT_EQ(ptr->buffer_size, 1);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value("Test1").first, 'A');
}

TEST(NodeInsertion_1_string_char, node_insert1_string_char)
{
    Node<std::string, char> node("Test1", 'A');
    Node_data<std::string, char> *ptr = node.node;
    node.insert("Test2", 'B');
    EXPECT_EQ(ptr->buffer_size, 2);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value("Test2").first, 'B');
}

TEST(NodeInsertion_2_string_char, node_insert2_string_char)
{
    Node<std::string, char> node("Test1", 'A');
    Node_data<std::string, char> *ptr = node.node;
    node.insert("Test2", 'B');
    node.insert("Test3", 'C');

    EXPECT_EQ(ptr->buffer_size, 3);
    EXPECT_FALSE(node.is_full());
    EXPECT_EQ(node.get_value("Test1").first, 'A');
    EXPECT_EQ(node.get_value("Test2").first, 'B');
    EXPECT_EQ(node.get_value("Test3").first, 'C');
}

TEST(NodeInsertion_3_string_char, node_insert3_string_char)
{
    Node<std::string, char> node("Test1", 'A');
    Node_data<std::string, char> *ptr = node.node;
    node.insert("Test2", 'B');
    node.insert("Test3", 'C');
    node.insert("Test4", 'D');

    EXPECT_EQ(ptr->buffer_size, 4);
    std::pair res = node.get_value("Test1");
    EXPECT_EQ(res.first, 'A');
    EXPECT_TRUE(res.second);

    res = node.get_value("Test2");
    EXPECT_EQ(res.first, 'B');
    EXPECT_TRUE(res.second);

    res = node.get_value("Test3");
    EXPECT_EQ(res.first, 'C');
    EXPECT_TRUE(res.second);

    res = node.get_value("Test4");
    EXPECT_EQ(res.first, 'D');
    EXPECT_TRUE(res.second);
    EXPECT_TRUE(node.is_full());
}

TEST(Node_get_value_return_false_int_double, node_get_value_int_double)
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

TEST(Node_get_value_return_false_string_char, node_get_value_string_char)
{
    Node<std::string, char> node("Test1", 'A');
    Node_data<std::string, char> *ptr = node.node;

    EXPECT_EQ(ptr->buffer_size, 1);
    std::pair res = node.get_value("Test1");
    EXPECT_EQ(res.first, 'A');
    EXPECT_TRUE(res.second);

    res = node.get_value("Test26");
    EXPECT_EQ(res.first, '\0');
    EXPECT_FALSE(res.second);
}

TEST(Node_create_hash_index_int_double, node_create_hash_index_int_double)
{
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;

    EXPECT_EQ(ptr->buffer[0].record_index, std::hash<int>{}(1));
}

TEST(Node_create_hash_index_string_double, node_create_hash_index_string_double)
{
    Node<std::string, double> node("Test1", 2.0);
    Node_data<std::string, double> *ptr = node.node;
    // Must cast the return of hash to unsigned int for valid comparison
    EXPECT_EQ(ptr->buffer[0].record_index, (unsigned int)std::hash<std::string>{}("Test1"));
}
