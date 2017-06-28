//
// Created by Victor on 6/27/2017.
//
#include <iostream>
#include <queue>

using namespace std;
#include "Tree.h"

Tree::Tree(int *preorder_in, int *inorder, int n) {
    queue<int> preorder; // create a queue because it makes life easier
    for (int j = 0; j < n; ++j) {
        preorder.push(*(preorder_in + j));
    }

    recCons(preorder,inorder,n,0,head);
}


void Tree::recCons(queue<int> &preorder, int *inorder, int end, int start, Node*& cur) {
    cur = new Node(preorder.front()); // start root with first in preorder
    preorder.pop(); // pop it off, this is now the root on the left side

    if (!preorder.empty()) {
        if (preorder.back() == preorder.front()) { // only 1 element
            recCons(preorder, inorder, start+1, start, cur->left);
        }
        else {
            int split = findIn(inorder, end, start, cur->data);

            queue<int> left;
            queue<int> right;
            int temp;
            for (int i = 0; i < end - start - 1; ++i) {
                if (i < split) { // plus one required since
                    temp = preorder.front();
                    left.push(temp);
                    preorder.pop();
                } else {
                    temp = preorder.front();
                    right.push(temp);
                    preorder.pop();
                }
            }

            recCons(left, inorder, split, start, cur->left); // left side
            recCons(right, inorder, end, split + 1, cur->right); // right side
        }
    }
}

int Tree::findIn(int *array, int end, int start, int val) {
    for (int i = start; i < end; ++i) {
        if (*(array+i) == val) {
            return i;
        }
    }
    cout << "didn't find value, returning 999";
    return 999;
}

bool Tree::isMinHeap() {
    return isMinHeap(head);
}

bool Tree::isMaxHeap() {
    return isMaxHeap(head);
}

bool Tree::isMinHeap(Node *cur) {
    if (cur->hasLeft()) {
        if (cur->data > cur->left->data) return false;
        else return isMinHeap(cur->left);
    }
    if (cur->hasRight()) {
        if (cur->data > cur->right->data) return false;
        else return isMinHeap(cur->right);
    }
    else {
        return true;
    }
}

bool Tree::isMaxHeap(Node *cur) {
    if (cur->hasLeft()) {
        if (cur->data < cur->left->data) return false;
        else return isMinHeap(cur->left);
    }
    if (cur->hasRight()) {
        if (cur->data < cur->right->data) return false;
        else return isMinHeap(cur->right);
    }
    else {
        return true;
    }
}

