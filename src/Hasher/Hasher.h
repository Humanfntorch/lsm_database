/*
    Author: Jacob Rogers
    File: Hasher.h
    Purpose: Template hasher  to allow generic type values K
    to be hashable using std::hash. Applicable generic values types allowed include:
    int, double, float, char, bool and string.
*/
#ifndef HASHER_H
#define HASHER_H

#include <iostream>
#include <functional>

template <typename K>
struct Hasher;

// int type hash struct
template <>
struct Hasher<int>
{
    size_t operator()(int value) const
    {
        return std::hash<int>{}(value);
    }
};

// double type hash struct
template <>
struct Hasher<double>
{
    size_t operator()(double value) const
    {
        return std::hash<double>{}(value);
    }
};

// bool type hash struct
template <>
struct Hasher<bool>
{
    size_t operator()(bool value) const
    {
        return std::hash<bool>{}(value);
    }
};

// char type hash struct
template <>
struct Hasher<char>
{
    size_t operator()(char value) const
    {
        return std::hash<char>{}(value);
    }
};

// string type hash struct
template <>
struct Hasher<std::string>
{
    size_t operator()(std::string value) const
    {
        return std::hash<std::string>{}(value);
    }
};

#endif