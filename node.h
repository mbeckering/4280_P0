/* 
 * File:   node.h
 * Author: Michael Beckering
 * Project 0
 * CS-4280-001-FS2019
 *
 * Created on September 17, 2019, 9:30 AM
 */

#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

struct node {
    char key;
    string data;
    struct node *left, *right;
};

// newNode function accepts a string and returns pointer to the created node
struct node* newNode(char newKey, string data){
    //struct node *temp = (struct node *)malloc(sizeof(struct node)); //TODO REMOVE?
    struct node *temp = new node();
    //node temp;
    temp->key = newKey;
    temp->data = data;
    temp->left = temp->right = NULL;
    cout << "Created new node " << temp->key << "\n";
    return temp;
}

// insertData function inserts new string into the tree
struct node* insertData(struct node* node, string data) {
    char key = data[0];
    // if the tree is empty, return a new node
    if (node == NULL) {
        cout << "parameter node is null, Returning NEWNODE pointer to node " << key << "\n";
        return newNode(key, data);
    }
    // if the tree exists, find the correct insertion point
    // if the key matches existing node, append the data string
    if (key == node->key) {
        string spc = " ";
        node->data = node->data + spc + data;
        cout << "added string. this node now: " << node->data << "\n";
    }
    else if (key < node->key) {
        cout << "adding " << key << " as left child of " << node->key << "\n";
        node->left = insertData(node->left, data);
    }
    else if (key > node->key) {
        cout << "adding " << key << " as right child of " << node->key << "\n";
        node->right = insertData(node->right, data);
    }
    //return the node pointer
    cout << "Returning pointer to node " << node->key << "\n";
    return node;
}

#endif /* NODE_H */

