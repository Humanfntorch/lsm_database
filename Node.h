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
struct Data
{
    std::pair<K, V> data;
};

// Node Struct
template <typename K, typename V>
struct Node_data
{   
    static constexpr int MAX_CAPACITY = 4;
    Data<K, V> buffer[MAX_CAPACITY];
    K index;
    int buffer_size;
    float timeStamp;
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
        /* Returns the value associated with this key if it's in this node. Otherwise returns NULL. */
        V get_value(K key);
        /* Attempts to insert the provided key/value pair into this node's buffer, returns true if succesful, false otherwise.*/
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
