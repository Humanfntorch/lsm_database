#include <iostream>
#include "Node.cpp"

int main() {
    // Create a Node object with some initial data
    Node<int, double> node(1, 2.0);
    Node_data<int, double> *ptr = node.node;
    
    std::cout << "size after creation: " << ptr->buffer_size << std::endl;
    std::cout << "is full after creation: " << node.is_full() << std::endl;
    std::cout << "Value associated with key 1: " << node.get_value(1).first << std::endl;

    node.insert(2, 3.0);
    std::cout << "size after insertion: " << ptr->buffer_size << std::endl;
    std::cout << "Value associated with key 2: " << node.get_value(2).first << std::endl;
    std::cout << "is full after insertion: " << node.is_full() << std::endl;


    node.insert(3, 4.0);
    std::cout << "size after insertion: " << ptr->buffer_size << std::endl;
    std::cout << "Value associated with key 3: " << node.get_value(3).first << std::endl;
    std::cout << "is full after insertion: " << node.is_full() << std::endl;

    node.insert(4, 5.0);
    std::cout << "size after insertion: " << ptr->buffer_size << std::endl;
    std::cout << "Value associated with key not in buffer: " << node.get_value(10).first << std::endl;
    std::cout << "Bool Flag associated with key not in buffer: " << node.get_value(10).second << std::endl;
    std::cout << "is full after insertion: " << node.is_full() << std::endl;

    // Add some key-value pairs to the buffer
    return 0;
}
