/*
    Author: Jacob Rogers
    File: Node.h
    Purpose: Details the interface for a BST Node data structure
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <utility>


template <typename K, typename V>
class Node;

// Data struct
template <typename K, typename V>
struct Record
{
    K record_key;
    V record_value;
    float record_index;
    float timeStamp;
};

// Node Struct
template <typename K, typename V>
struct Node_data
{   
    static constexpr int MAX_CAPACITY = 4;
    Record<K, V> buffer[MAX_CAPACITY];
    K index;
    int buffer_size;
    Node<K, V> *left;
    Node<K, V> *right;

};

// Node Class
template <typename K, typename V>
class Node
{   

    public:

        // data struct for this node
        Node_data<K, V> *node;
        // Private methods

        /* Returns true if buffer size has reach MAX_CAPACITY, false otherwise. */
        bool is_full();
        /* Returns the current index pointer of this node. */
        K get_index();
        /* Returns a pair association value associated with the provided key. If the key is found in this node's buffer, returns the value associated with the key and a boolean flag of True indicating key value found, otherwise returns the default value for the value type, and a false flag indicating key was not found. */
        std::pair<V, bool> get_value(K key);
        /* Attempts to insert the provided key/value pair into this node's buffer, returns true if succesful, false otherwise.
            Note: Each Node controls it's own buffer, the tree then controls all nodes. If a node can store the data, it does, if it can't it's then the trees job to move to a new node.
        */
        bool insert(K key, V value);
        /* Attempts to remove the provided key/value pair if in this node's buffer, returns true if succesful, false otherwise.*/
        bool remove(K key, V value);
    //public:
        // Public methods

        /* Constructs a new node and initializes node data given a key/value pair. */
        Node(K key, V value);
        /*Deletes the data associated with this node. */
        ~Node();
};

#endif
