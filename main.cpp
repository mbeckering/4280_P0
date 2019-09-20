/*
 * File:   main.cpp
 * Author: Michael Beckering
 * Project 0
 * CS-4280-001-FS2019
 *
 * Created on September 13, 2019, 9:21 AM
 * Last Edited: Sept 20 2019 //TODO update
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "tree.h"
//#include "node.h"

using namespace std;

int main(int argc, char** argv) {
    string inputFilenameStr; // name of data file WITH extension to open for sorting
    // parse command line arguments
    // if no args, get input from stdin until eof or simulated eof
    if (argc == 1) {
        string line;
        ofstream out("kbs.fs19"); // kbs = keyboard stream
        cout << "Reading input from keyboard. (CTRL+D when finished)\n";
        while (getline(cin, line)) {
            out << line << "\n";
        }
        out.close();
        cout << "Saving keyboard input to file kbs.fs19...\n";
        inputFilenameStr = "kbs.fs19";
    }
    // if one arg, append file extension
    else if (argc == 2) {
        cout << "Argument given: " << argv[1] << "\n";
        string arg1(argv[1]);
        inputFilenameStr = arg1 + ".fs19";
    }
    // else too many args, print error message and exit
    else {
        cout << "Error: Too many arguments.\n";
        cout << "Usage: ./P0 <filename>\n";
        cout << "Exclude file extension.\n";
        return 1;
    }
    
    // convert string to const char*
    const char *inputFilenameChar = inputFilenameStr.c_str();
    
    // if this point is reached, input file has been successfully opened
    
    /* sample main
     * node *root = builtTree(inputFilenameChar);
     * printPreorder(root);
     * printInorder(root);
     * printPostorder(root);
     */
    struct node *root = NULL;
    root = buildTree(inputFilenameChar);
    if (root == NULL) {
        cout << "main.cpp: root is null\n";
        return 1;
    }
    else {
        //printInorder(inputFilenameChar);
        int depth = 0;
        cout << "========================= PRINTING ========================\n";
        //printPreorder(root, depth);
        //printPostorder(inputFilenameChar);
    }
    
    return 0;
}

