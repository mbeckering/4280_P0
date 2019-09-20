/*
 * File:   tree.cpp
 * Author: Michael Beckering
 * Project 0
 * CS-4280-001-FS2019
 *
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <set>
#include <ctype.h>
#include "tree.h"
#include "node.h"

using namespace std;

//TODO pass the set of data to build the tree
//TODO function descriptions
//TODO buildTree should return root pointer
struct node* buildTree(const char* inputFilename){
    struct node *root = NULL;
    cout << "buildTree() called with arg " << inputFilename << "\n"; //TODO remove
    cout << "Attempting to open file " << inputFilename << "...\n";
    ifstream in;
    in.open(inputFilename);
    // if file failed to open, exit with error message
    if (!(in.is_open())) {
        cout << "Error opening file " << inputFilename << "\n";
        return NULL;
    }
    else {
        cout << "Success opening " << inputFilename << "\n";
    }
    set <string> dataSet;
    string letter, word, line;
    bool is_in;
    string spc = " ";
    // parse data file
    while (getline(in, line)) {
        word = "";
        // iterate over each line in the data file
        for (int i=0; i <= line.length(); i++){
            // if the character is a letter, add it to this word
            if (isalpha(line[i])) {
                letter = line[i];
                word = word + letter;
            }
            // else end of word is found (if word is not empty)
            else if (word.length() > 0){
                // check to see if this word is already in the set
                is_in = (dataSet.find(word) != dataSet.end());
                // if not, insert it to the set AND the binary search tree
                if (is_in == false){
                    dataSet.insert(word);
                    // if this is the first word in the set, create the root
                    if (dataSet.size() == 1) {
                        cout << "tree.cpp: CALLING insertData() with root " << word << "\n";
                        root = insertData(root, word);
                    }
                    else {
                        cout << "tree.cpp: calling insertData() with word " << word << "\n";
                        insertData(root, word);
                    }
                }
                word = "";
            }
        }
    }
    //print the set
    for (auto it=dataSet.begin(); it != dataSet.end(); ++it) {
        cout << *it << "\n";
    }
    in.close();
    printPreorder(root, 0);
    return root;
}

//TODO all 3 of these accept the root pointer?
int printInorder(const char* inputFilename){
    cout << "printInorder() called with arg " << inputFilename << "\n";
    return 0;
}

void printPreorder(struct node *root, int depth){
    if (root != NULL) {
        //cout << "%*c%d:%-9s ",depth*2,'',depth,(root->key); //TODO replace with print to file
        cout << "depth=" << depth << " " << " key=" << root->key << " data=" << root->data << "\n";
        printPreorder(root->left, depth+1);
        printPreorder(root->right, depth+1);
    }
}

int printPostorder(const char* inputFilename){
    cout << "printPostorder() called with arg " << inputFilename << "\n";
    return 0;
}