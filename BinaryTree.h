//
// Created by tangz on 2020/10/15.
//

#ifndef PACKAG_BINARYTREE_H
#define PACKAG_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTree {

    int num;
    struct BinaryTree *LeftNode;
    struct BinaryTree *RightNode;

} binaryTree;


typedef struct StackOfBinaryTree {
    binaryTree *data;
    struct StackOfBinaryTree *nextNode;
} StackNode;

typedef struct Stack {

    StackNode *head, *top;

    int (*isEmpty)();

    binaryTree *(*getTop)();

    void (*push)(binaryTree *data);

    void (*printAll)();

    void (*pop)();

} Stack;

Stack stackNode;

//初始化栈
void init(binaryTree *data) {
    stackNode.head = (StackNode *) malloc(sizeof(StackNode));
    stackNode.head->data = data;
    stackNode.head->nextNode = NULL;
    stackNode.top = stackNode.head;
}

//栈是否为空
int isEmpty() {
    return (stackNode.head == NULL) ? 0 : 1;
}

//获得栈顶数据
binaryTree *getTop() {
    if (stackNode.top == NULL) {
        return NULL;
    }
    return stackNode.top->data;
}

//压入栈顶
void push(binaryTree *data) {
    if (!isEmpty()) {
        init(data);
        return;
    }
    StackNode *loop = stackNode.head;
    StackNode *push = (StackNode *) malloc(sizeof(StackNode));
    push->nextNode = NULL;
    while (loop->nextNode != NULL) {
        loop = loop->nextNode;
    }
    push->data = data;
    loop->nextNode = push;
    stackNode.top = push;
}

//弹出栈顶
void pop() {
    if (!isEmpty()) {
        return;
    }
    if (stackNode.head == stackNode.top) {
        stackNode.head = NULL;
        stackNode.top = NULL;
        return;
    }
    StackNode *loop = stackNode.head;
    while (loop->nextNode->nextNode != NULL) {
        loop = loop->nextNode;
    }
    stackNode.top = loop;
    stackNode.top->nextNode = NULL;
    loop = loop->nextNode;
    loop = NULL;
}

void __attribute__((constructor)) function(void) {
    stackNode.isEmpty = isEmpty;
    stackNode.getTop = getTop;
    stackNode.push = push;
    stackNode.getTop = getTop;
    stackNode.pop = pop;
}


binaryTree *insert(const int x, binaryTree *t) {

    if (t == NULL) {
        binaryTree *p = NULL;
        t = p = (binaryTree *) malloc(sizeof(binaryTree));
        p->LeftNode = p->RightNode = NULL;
        p->num = x;
    } else if (x < t->num)
        t->LeftNode = insert(x, t->LeftNode);
    else if (t->num < x)
        t->RightNode = insert(x, t->RightNode);
    return t;

}

void pre_order(binaryTree *t) {
    if (t == NULL)
        return;
    printf("%d\n", t->num);
    pre_order(t->LeftNode);
    pre_order(t->RightNode);
}

void mid_order(binaryTree *t) {
    if (t == NULL)
        return;
    mid_order(t->LeftNode);
    printf("%d\n", t->num);
    mid_order(t->RightNode);
}

void post_order(binaryTree *t) {
    if (t == NULL)
        return;
    post_order(t->LeftNode);
    post_order(t->RightNode);
    printf("%d\n", t->num);
}

void pre_order_loop(binaryTree *t) {
    if (t == NULL)
        return;
    stackNode.push(t);
    while (stackNode.isEmpty()) {
        binaryTree *p = stackNode.getTop();
        stackNode.pop();
        printf("%d\n", p->num);
        binaryTree *pLeft = p->LeftNode;
        binaryTree *pRight = p->RightNode;
        if (pRight)
            stackNode.push(pRight);
        if (pLeft)
            stackNode.push(pLeft);
    }
}

void mid_order_loop(binaryTree *t) {
    if (t == NULL)
        return;
    binaryTree *p = t;
    while (p) {
        stackNode.push(p);
        p = p->LeftNode;
    }
    while (stackNode.isEmpty()) {
        binaryTree *q = stackNode.getTop();
        stackNode.pop();
        printf("%d\n", q->num);
        q = q->RightNode;
        while (q) {
            stackNode.push(q);
            q = q->LeftNode;
        }
    }
}

void post_order_loop(binaryTree *t) {
    if (t == NULL)
        return;
    binaryTree *p = t;
    while (p) {
        stackNode.push(p);
        if (p->LeftNode)
            p = p->LeftNode;
        else
            p = p->RightNode;
    }
    while (stackNode.isEmpty()) {
        binaryTree *q = stackNode.getTop();
        stackNode.pop();
        printf("%d\n", q->num);
        if (!stackNode.isEmpty() && q == stackNode.getTop()->LeftNode) {
            q = stackNode.getTop()->RightNode;
            while(q){
                stackNode.push(q);
                if (q->LeftNode)
                    q = q->LeftNode;
                else
                    q = q->RightNode;
            }

        }
    }
}

#endif //PACKAG_BINARYTREE_H
