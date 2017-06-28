//
// Created by Victor on 6/27/2017.
//

#ifndef HW3_TREE_H
#define HW3_TREE_H

#include <queue>
#include "Node.h"

class Tree {

public:
    Node* head = 0;
    Tree(int *preorder, int *inorder, int n);
    void recCons(queue<int> &preorder, int *inorder, int end, int start, Node*& cur);

    int findIn(int *array, int end, int start, int val) ;

    bool isMinHeap();

    bool isMaxHeap();

    bool isMinHeap(Node *cur);

    bool isMaxHeap(Node *cur);
};


#endif //HW3_TREE_H
