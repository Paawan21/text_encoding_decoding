# Text Encoding/Decoding Project

This project implements a text encoding and decoding system using a combination of the Burrows-Wheeler Transform (BWT), Move-to-Front (MTF) encoding, and Huffman coding techniques.

## Overview

The encoding process follows these steps:

1. The input text is transformed using the Burrows-Wheeler Transform (BWT) algorithm.
2. The transformed text is then encoded using Move-to-Front (MTF) encoding.
3. The MTF-encoded text is further compressed using Huffman coding.

The decoding process is the reverse of the encoding process:

1. The encoded text is first decoded using Huffman decoding.
2. The decoded text is then decoded using Move-to-Front decoding.
3. Finally, the original text is recovered using the Burrows-Wheeler Transform decoding algorithm.

## Files

- [`BurrowsWheeler.h`](BurrowsWheeler.h): Contains the implementation of the Burrows-Wheeler Transform encoding and decoding algorithms.
- [`HuffmanTree.h`](HuffmanTree.h): Implements the Huffman coding and decoding algorithms using a Huffman tree data structure.
- [`Node.h`](Node.h): Defines the `Node` class used in the Huffman tree implementation.
- [`main.cpp`](main.cpp): The main driver program that provides a command-line interface for encoding and decoding text files.

## Usage

1. Compile the program using a C++ compiler.
2. Run the compiled program.
3. Follow the on-screen instructions to encode or decode text files.

When encoding:
- Provide the name of the input text file to be encoded.
- The encoded text will be saved to a file named "encoded.txt" in the same directory.

When decoding:
- Provide the name of the encoded file to be decoded.
- Provide the name of the output file to save the decoded text.
