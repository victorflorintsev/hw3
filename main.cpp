using namespace std;
#include <iostream>
#include <fstream>
#include <cstring>
#include "Tree.h"

int readArray(string basic_string, int *&pInt);

int main() {
    // never any duplicated numbers in the file.
    string filename_preorder = "preorder1.txt";
    string filename_inorder  = "inorder1.txt";

    int* preorder;
    int size = readArray(filename_preorder,preorder);
    int* inorder;
    if (readArray(filename_inorder,inorder) != size) cout << "Error, text file size inequality";

    // we now have the arrays of equal size, preorder and inorder, stored in their respective pointers
    // from here we can construct the tree by passing it to a tree class
    Tree T(preorder,inorder,size);

    bool isHeap = false;
    if (T.isMinHeap() || T.isMaxHeap()) isHeap = true;

    if (isHeap) cout << "yes";
    else cout << "no";


    return 0;
}

int readArray(string filename, int*& out_array) {
    int size = 0;
    ifstream in(filename);
    string toparse = "";
    string temp;
    if (in.is_open()) {
        while (in.good()) {
            getline(in,temp);
            toparse.append(" " + temp + " ");
        }
    }
    //cout << toparse << endl;
    char c = 0;
    int start = 0;
    bool isnum = false;
    for (int i = 0; i < strlen(toparse.c_str()); ++i) { // find size first
        c = toparse.at(i);
        if (c >= '0' && c <= '9') {
            if (isnum == false) size++;
            isnum = true;
        }
        else isnum = false;
    }
    // then construct integer array of correct size
    out_array = new int[size];
    isnum = false;
    int out_i = 0;
    for (int i = 0; i < strlen(toparse.c_str()); ++i) {
        c = toparse.at(i);
        if ((c >= '0' && c <= '9') || (c == '-')) {
            if (isnum == false) start = i;
            isnum = true;
        }
        else {
            if (isnum == true) {
                int x = atoi(toparse.substr(start,i-start).c_str());
                *(out_array+out_i)  = x;
                //cout << *(out_array+out_i) << " ";
                out_i++;
            }
            isnum = false;
        }
    }
    return size;
}