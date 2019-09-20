/*
 * File:   tree.h
 * Author: Michael Beckering
 * Project 0
 * CS-4280-001-FS2019
 *
 * Created on September 17, 2019, 9:29 AM
 */

#ifndef TREE_H
#define TREE_H
 
struct node* buildTree(const char*); //TODO buildTree should return root pointer
int printInorder(struct node*, int); //TODO accept node pointer instead of file?
void printPreorder(struct node*, int); 
int printPostorder(struct node*, int); 
 
//TODO declare struct or array of nodes (the tree)

#endif /* TREE_H */
