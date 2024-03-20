#include <iostream>
#include <string>
#include "BurrowsWheeler.h" // Include BWT implementation
#include "HuffmanTree.h"    // Include Huffman coding implementation
#include<fstream>
using namespace std;

int main() {
    // Original text
    string inputFileName = "input.txt";
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file: " << inputFileName << endl;
        return 1;
    }
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string inputText = buffer.str();

    // Encode using Burrows-Wheeler Transform (BWT)
    BurrowsWheeler bwtEncoder(inputText);
    string bwtEncodedText = bwtEncoder.bwt_encode(inputText+"$");

    // Decode using Burrows-Wheeler Transform (BWT)
    
    string bwtDecodedText = bwtEncoder.bwt_decode(bwtEncodedText);

    // Encode using Move-to-Front (MTF)
    string mtfEncodedText= moveToFrontEncoding(inputText);

    // Decode using Move-to-Front (MTF)
    string mtfDecodedText =moveToFrontDecoding(mtfEncodedText);

    // Encode using Huffman coding
    HuffmanTree huffmanEncoder(inputText);
    string huffmanEncodedText = huffmanEncoder.encode(inputText);

    // Decode using Huffman coding
    string huffmanDecodedText = huffmanEncoder.decode(huffmanEncodedText);

    // Print results
    cout << "Original Text: " << inputText << endl;
    cout << "BWT Encoded Text: " << bwtEncodedText << endl;
    cout << "BWT Decoded Text: " << bwtDecodedText << endl;
    cout << "MTF Encoded Text: " << mtfEncodedText << endl;
    cout << "MTF Decoded Text: " << mtfDecodedText << endl;
    cout << "Huffman Encoded Text: " << huffmanEncodedText << endl;
    cout << "Huffman Decoded Text: " << huffmanDecodedText << endl;

    return 0;
}
