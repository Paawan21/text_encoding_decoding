#include <iostream>
#include <fstream>
#include "BurrowsWheeler.h" // Include BWT implementation
#include "HuffmanTree.h"    // Include Huffman coding implementation

using namespace std;

int main() {
    // Read input from file
    string inputFileName = "input.txt";
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file: " << inputFileName << endl;
        return 1;
    }
    stringstream buffer;
    buffer << inputFile.rdbuf();
    string inputText = buffer.str();

    // Encode using Burrows-Wheeler Transform
    BurrowsWheeler bwt(inputText);
    string bwtEncodedText = bwt.bwt_encode(inputText+"$");

    // Encode using Move-to-Front
    string mtfEncodedText = moveToFrontEncoding(bwtEncodedText);
    HuffmanTree huff(mtfEncodedText);
    string huffmanEncodedText = huff.encode(mtfEncodedText);
    string huffmandecoded = huff.decode(huffmanEncodedText);


    // Decode Move-to-Front result
    string mtfDecodedText = moveToFrontDecoding(huffmandecoded);

    // Decode Burrows-Wheeler result
    string reversedBWT =bwt.bwt_decode(mtfDecodedText);

    // Display results
    cout << "Original Text: " << inputText << endl;
    cout << "BWT Encoded Text: " << bwtEncodedText << endl;
    cout << "MTF Encoded Text: " << mtfEncodedText << endl;
    cout << "Huffman Encoded Text: " << huffmanEncodedText << endl;
    cout << "Huffman Decoded Text: " << huffmandecoded << endl;
    cout << "MTF Decoded Text: " << mtfDecodedText << endl;
    cout << "BWT Decoded Text: " << reversedBWT << endl;
    return 0;
}