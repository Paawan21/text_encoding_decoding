#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<sstream>
using namespace std;
class BurrowsWheeler {
    string text;

public:
    BurrowsWheeler(string Text) : text(Text) {}

    string bwt_encode(const string& text) {
    vector<string> rotations;
    int len = text.size();
    
    // Generate all cyclic rotations
    for (int i = 0; i < len; ++i) {
        rotations.push_back(text.substr(i) + text.substr(0, i));
    }
    
    // Sort the cyclic rotations lexicographically
    sort(rotations.begin(), rotations.end());
    
    // Extract the last characters of sorted rotations
    string bwt_encoded = "";
    for (const string& rotation : rotations) {
        bwt_encoded += rotation.back();
    }
    
    return bwt_encoded;
}


string bwt_decode(const string& bwt_encoded) {
    int len = bwt_encoded.size();
    
    // Construct a matrix of all cyclic rotations
    vector<string> matrix(len);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < len; ++j) {
            matrix[j] = bwt_encoded[j] + matrix[j];
        }
        sort(matrix.begin(), matrix.end());
    }
    
    // Find the original string
    string original_string = "";
    for (const string& rotation : matrix) {
        if (rotation.back() == '$') { // Assuming '$' as the terminator
            original_string = rotation;
            break;
        }
    }
    
    // Extract the original string
    original_string.pop_back(); // Remove the terminator character
    
    return original_string;
}
};

string moveToFrontEncoding(const string& text) {
    string result = "";
    vector<char> v;
    for (int i = 0; i < 256; i++) {
        v.push_back(i);
    }
    for (char c : text) {
        auto it = find(v.begin(), v.end(), c);
        int index = distance(v.begin(), it);
        result += to_string(index) + " ";
        v.erase(it);
        v.insert(v.begin(), c);
    }
    return result;
}

string moveToFrontDecoding(const string& text) {
    string result = "";
    vector<char> v;
    for (int i = 0; i < 256; i++) {
        v.push_back(i);
    }
    stringstream ss(text);
    int index;
    while (ss >> index) {
        char c = v[index];
        result += c;
        v.erase(v.begin() + index);
        v.insert(v.begin(), c);
    }
    return result;
}
