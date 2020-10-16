#include "BinaryTree.h"

int main() {
    binaryTree *binaryTree1 = NULL;
    int i = 0;
    for (i = 1; i <= 10; ++i) {
        binaryTree1 = insert(i, binaryTree1);
    }
    post_order_loop(binaryTree1);
}
