/*
    Author: Jacob Rogers
    File: Node.cpp
    Purpose: Implements the Node interface. 
    Each Node acts indepedently from another and has control over it's own buffer.
*/
#include <iostream>
#include <utility>
#include "Node.h"
#include "../Hasher/Hasher.h"

// Constructor definition
template <typename K, typename V>
Node<K, V>::Node(K key, V value)
{   
    // Allocate memory for Node_data and initiate the node
    node = new Node_data<K, V>();
    node->buffer[0].record_key = key;
    node->buffer[0].record_value = value;
    node->buffer_size = 1;
    node->left = nullptr;
    node->right = nullptr;

    // Create hasher and determine index
    Hasher<K> hasher;
    node->buffer[0].record_index = hasher(key);
}

template <typename K, typename V>
Node<K, V>::~Node()
{
    delete node;
}

template <typename K, typename V>
bool Node<K, V>::is_full()
{
    return (node->buffer_size >= node->MAX_CAPACITY);
}

template <typename K, typename V>
K Node<K, V>::get_index()
{
    return (node->index);
}

template <typename K, typename V>
std::pair<V, bool> Node<K, V>::get_value(K key)
{
    for (Record<K, V> record_i : node->buffer)
    {
        if (record_i.record_key == key)
        {
            return std::make_pair(record_i.record_value, true);
        }
    }
    return std::make_pair(V{}, false);
}

template <typename K, typename V>
bool Node<K, V>::insert(K key, V value)
{
    // Ensure enough capacity to store into buffer
    if (!is_full())
    {
        node->buffer[node->buffer_size].record_key = key;
        node->buffer[node->buffer_size].record_value = value;
        Hasher<K> hasher;
        node->buffer[node->buffer_size].record_index = hasher(key);
        node->buffer_size++;
        return true;
    }
    return false;
}

template <typename K, typename V>
bool Node<K, V>::remove(K key, V value)
{
    // TODO
    return false;
}
