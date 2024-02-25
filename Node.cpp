#include <iostream>
#include <utility>
#include "Node.h"

// Constructor definition
template <typename K, typename V>
Node<K, V>::Node(K key, V value)
{
    node = new Node_data<K, V>();
    // Allocate memory for Node_data
    node->buffer[0].data = std::make_pair(key, value);
    node->buffer_size = 1;
    node->left = nullptr;
    node->right = nullptr;
    node->index = key;
}

template <typename K, typename V>
Node<K,V>::~Node()
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
V Node<K, V>::get_value(K key)
{
    for(Data<K, V> data : node->buffer)
    {
        if(data.data.first == key)
        {
            return data.data.second;
        }
    }
    return -2;
}

template <typename K, typename V>
bool Node<K, V>::insert(K key, V value)
{   
    // Ensure enough capacity to store into buffer
    if(!is_full())
    {
        node->buffer[node->buffer_size].data = std::make_pair(key, value);
        node->buffer_size++;
        return true;
    }
    // Will 
    // TODO: need to create a new node if needed and store as left/right child here
    return false;
}

template <typename K, typename V>
bool Node<K, V>::remove(K key, V value)
{   
    // TODO
    return false;
}
