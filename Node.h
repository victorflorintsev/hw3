//
// Created by Victor on 6/27/2017.
//

#ifndef HW3_NODE_H
#define HW3_NODE_H


class Node {
public:
    Node* left = 0;
    Node* right = 0;
    int data = 0;
    bool init = false;

    Node(int d) {
        data = d;
        init = true;
    }
    Node() { }
    bool hasLeft() {
      if (left == 0) {
          return false;
      }
        else {
          if (left->init == false) return  false;
          else return true;
      }
    };
    bool hasRight() {
        if (right == 0) {
            return false;
        }
        else {
            if (left->right == false) return  false;
            else return true;
        }
    };
};


#endif //HW3_NODE_H
