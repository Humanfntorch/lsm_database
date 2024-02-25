#include <iostream>
#include <utility>
#include "Node.h"

// Constructor definition
template <typename K, typename V>
Node<K, V>::Node(K key, V value)
{
    node = new Node_data<K, V>();
    // Allocate memory for Node_data
    node->buffer[0].record_key = key;
    node->buffer[0].record_value = value;
    node->buffer_size = 1;
    node->left = nullptr;
    node->right = nullptr;
    node->index = key;
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
