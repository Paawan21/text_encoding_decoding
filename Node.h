#include<iostream>
#include<queue>
#include<map>
#pragma once
using namespace std;

class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;

    // Constructor using initializer list
    Node(char data, int freq) : data(data), freq(freq), left(nullptr), right(nullptr) {}

    Node(int freq, Node* left, Node* right) : data('\0'), freq(freq), left(left), right(right) {}

    // Destructor to deallocate memory
    ~Node() {
        delete left;
        delete right;
    }
};

class compare {
public:
    bool operator()(const Node* a, const Node* b) const {
        return a->freq > b->freq;
    }
};
