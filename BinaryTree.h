//
// Created by tangz on 2020/10/15.
//

#ifndef PACKAG_BINARYTREE_H
#define PACKAG_BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef  struct BinaryTree{

    int num;
    struct BinaryTree *LeftNode;
    struct BinaryTree *RightNode;

}binaryTree;


typedef struct StackOfBinaryTree {
    binaryTree *data;
    struct StackOfBinaryTree *nextNode;
} StackNode;

typedef struct Stack {

    StackNode *head, *top;

    int (*isEmpty)();
    binaryTree *getTop();
    void (*push)(binaryTree *data);
    void (*printAll)();
    void (*pop)();

} Stack;

Stack stackNode;

//��ʼ��ջ
void init(binaryTree *data) {
    stackNode.head = (StackNode*)malloc(sizeof(StackNode));
    stackNode.head->data = data;
    stackNode.head->nextNode = NULL;
    stackNode.top = stackNode.head;
}
//ջ�Ƿ�Ϊ��
int isEmpty() {
    return (stackNode.head == NULL) ? 0 : 1;
}
//���ջ������
binaryTree *getTop() {
    if(stackNode.top == NULL){
        return NULL;
    }
    return stackNode.top->data;
}
//ѹ��ջ��
void push(binaryTree *data) {
    if(!isEmpty()){
        init(data);
        return;
    }
    StackNode *loop = stackNode.head;
    StackNode *push = (StackNode *) malloc(sizeof(StackNode));
    push->nextNode=NULL;
    while (loop->nextNode != NULL) {
        loop = loop->nextNode;
    }
    push->data = data;
    loop->nextNode = push;
    stackNode.top = push;
}
//����ջ��
void pop(){
    if(!isEmpty()){
        return;
    }
    if(stackNode.head == stackNode.top){
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


void insert(const int x,binaryTree *t){

    if(t == NULL) {
        binaryTree *p = (binaryTree*)malloc(sizeof(binaryTree));
        p->LeftNode = p->RightNode = NULL;
        p->num = x;
    }
    else if(x < t->num )
    insert(x, t->LeftNode);
    else if(t->num < x)
        insert(x, t->RightNode);
    else;
}

void pre_order(binaryTree *t){
    if( t == NULL)
        return;
    printf("%d\n",t->num);
    pre_order(t->LeftNode);
    pre_order(t->RightNode);
}
void mid_order(binaryTree *t){
    if( t == NULL)
        return;
    mid_order(t->LeftNode);
    printf("%d\n",t->num);
    mid_order(t->RightNode);
}
void post_order(binaryTree *t){
    if(t == NULL)
        return;
    post_order(t->LeftNode);
    post_order(t->RightNode);
    printf("%d\n",t->num);
}

void pre_order_loop(binaryTree *t){
    if(t == NULL)
        return;
    stackNode.push(t);
    while (!stackNode.isEmpty()){
        binaryTree *p = stackNode.getTop();
        stackNode.pop();
        printf("%d\n",p->num);
        binaryTree *pLeft = p->LeftNode;
        binaryTree *pRight = p->RightNode;
        if (pRight)
            stackNode.push(pRight);
        if(pLeft)
            stackNode.push(pLeft);
    }
}

#endif //PACKAG_BINARYTREE_H
