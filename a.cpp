#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

int main() {
    string text = "hello im a string";
    string bwt_encoded = bwt_encode(text + "$"); // Add a terminator character
    cout << "BWT Encoded Text: " << bwt_encoded << endl;
    
    string decoded_text = bwt_decode(bwt_encoded);
    cout << "BWT Decoded Text: " << decoded_text << endl;
    
    return 0;
}
