#include <iostream>
#include <limits>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

class Interval{
public:
    int low, high;
};

class ITNode{
public:
    Interval *i;
    int max;
    ITNode *left, *right;
};

ITNode * newNode(Interval i){
    ITNode *temp = new ITNode;
    temp->i = new Interval(i);
    temp->max = i.high;
    temp->left = temp->right = NULL;
    return temp;
}

ITNode *insert(ITNode *root, Interval i){
    if (root == NULL)
        return newNode(i);
    int l = root->i->low;
    if (i.low < l)
        root->left = insert(root->left, i);
    else
        root->right = insert(root->right, i);
    if (root->max < i.high)
        root->max = i.high;
    return root;
}

bool doOVerlap(Interval i1, Interval i2){
    if (i1.low <= i2.high && i2.low <= i1.high)
        return true;
    return false;
}

Interval *overlapSearch(ITNode *root, Interval i){
    if (root == NULL) return NULL;
    if (doOVerlap(*(root->i), i))
        return root->i;
    if (root->left != NULL && root->left->max >= i.low)
        return overlapSearch(root->left, i);
    return overlapSearch(root->right, i);
}

void inorder(ITNode *root){
    if (root == NULL) return;
    inorder(root->left);
    inorder(root->right);
}

int main(){
    Interval ints[] = {{4,8}, {7,10}, {15,18}, {5, 11}, {17,19}, {22,23}};
    int n = sizeof(ints)/sizeof(ints[0]);
    ITNode *root = NULL;
    for (int i = 0; i < n; i++)
        root = insert(root, ints[i]);
    
    inorder(root);
    
    Interval x = {14, 16};
    
    Interval *res = overlapSearch(root, x);
    if (res == NULL)
        cout << "No hay Overlap";
    else
        cout << "Overlap con [" << res->low << ", " << res->high << "]"<<endl;
    return 0;
}