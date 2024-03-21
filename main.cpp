#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include "BurrowsWheeler.h" // Include BWT implementation
#include "HuffmanTree.h"    // Include Huffman coding implementation

using namespace std;

// Function to encode the input text and save it to a file
void encode(const string& inputText, const string& outputFileName) {
    // Encode using Burrows-Wheeler Transform
    BurrowsWheeler bwt(inputText);
    string bwtEncodedText = bwt.bwt_encode(inputText + "$");

    // Encode using Move-to-Front
    string mtfEncodedText = moveToFrontEncoding(bwtEncodedText);
    HuffmanTree huff(mtfEncodedText);
    string huffmanEncodedText = huff.encode(mtfEncodedText);

    // Save encoded text to a file
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create output file: " << outputFileName << endl;
        return;
    }

    outputFile << huffmanEncodedText;
    outputFile.close();
    cout << "Encoding successful. Encoded text saved to: " << outputFileName << endl;
}

// Function to decode the input text from a file and save it to another file
void decode(const string& inputFileName, const string& outputFileName) {
    // Read encoded text from the file
    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input file: " << inputFileName << endl;
        return;
    }

    stringstream buffer;
    buffer << inputFile.rdbuf();
    string encodedText = buffer.str();
    inputFile.close();
HuffmanTree huff(encodedText);
    string reversedBWT = huff.decode(encodedText);
    // Decode using Move-to-Front
    if (reversedBWT.empty()) {
        cerr << "Error: Invalid encoded text" << endl;
        return;
    }
    string mtfDecodedText = moveToFrontDecoding(reversedBWT);

    // Decode using Huffman coding

    // Decode using Burrows-Wheeler Transform
    BurrowsWheeler bwt(mtfDecodedText);
    string originalText = bwt.bwt_decode(mtfDecodedText);

    // Save decoded text to a file
    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to create output file: " << outputFileName << endl;
        return;
    }

    outputFile << originalText;
    outputFile.close();
    cout << "Decoding successful. Decoded text saved to: " << outputFileName << endl;
}
int main() {
    srand(time(0));

    int choice;
    do {
        cout << "\nDashboard Menu:\n";
        cout << "1. Encode text file\n";
        cout << "2. Decode encoded file\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                string inputFileName = "input.txt";
                string outputFileName = "encoded.txt";

                // Read input text from file
                ifstream inputFile(inputFileName);
                if (!inputFile.is_open()) {
                    cerr << "Error: Unable to open input file: " << inputFileName << endl;
                    break;
                }

                stringstream buffer;
                buffer << inputFile.rdbuf();
                string inputText = buffer.str();
                inputFile.close();

                // Encode the input text and save it to a file
                encode(inputText, outputFileName);
                break;
            }
            case 2: {
                string inputFileName, outputFileName;
                cout << "Enter the name of the encoded file to decode: ";
                cin >> inputFileName;
                cout << "Enter the name of the output file to save the decoded text: ";
                cin >> outputFileName;

                // Decode the encoded text from the file and save it to a new file
                decode(inputFileName, outputFileName);
                break;
            }
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cerr << "Invalid choice. Please choose 1, 2, or 3.\n";
        }
    } while (choice != 3);

    return 0;
}
