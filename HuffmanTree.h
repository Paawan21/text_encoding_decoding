#include<iostream>
#include<queue>
#include<map>
#include<string>
#include"Node.h"
#pragma once
using namespace std;

class HuffmanTree {
private:
    Node* root;
    map<char, string> codes;

    void generateCodes(Node* root, string code) {
        if (root == nullptr) {
            return;
        }
        if (root->left == nullptr && root->right == nullptr) {
            codes[root->data] = code;
            return;
        }
        generateCodes(root->left, code + "0");
        generateCodes(root->right, code + "1");
    }

public:
    HuffmanTree(string Text) {
    map<char, int> freq;
    for (int i = 0; i < Text.size(); i++) {
        freq[Text[i]]++;
    }
    priority_queue<Node*, vector<Node*>, compare> pq;
    for (auto& x : freq) {
        Node* temp = new Node(x.first, x.second);
        pq.push(temp); // Using push instead of emplace
    }
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();
        Node* newNode = new Node(left->freq + right->freq, left, right);
        pq.push(newNode); // Using push instead of emplace
    }
    root = pq.top();
    pq.pop();
    generateCodes(root, "");
}
    void printCodes() const {
        for (const auto& x : codes) {
            cout << x.first << " " << x.second << endl;
        }
    }

    string encode(const string& text) const {
        string result;
        for (char c : text) {
            result += codes.at(c);
        }
        return result;
    }

    string decode(const string& text) const {
        string result;
        Node* temp = root;
        for (char bit : text) {
            if (bit == '0') {
                temp = temp->left;
            }
            else {
                temp = temp->right;
            }
            if (temp->left == nullptr && temp->right == nullptr) {
                result += temp->data;
                temp = root;
            }
        }
        return result;
    }
};
