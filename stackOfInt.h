//
// Created by tangz on 2020/9/5.
//

#ifndef PACKAG_STACKOFINT_H
#define PACKAG_STACKOFINT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct StackOfInt {
    int data;
    struct StackOfInt *nextNode;
} StackNode;

typedef struct Stack {

    StackNode *head, *top;

    //void (*init)(int data);
    int (*isEmpty)();
    int (*getTop)();
    void (*push)(int data);
    void (*printAll)();
    void (*pop)();

} Stack;



Stack stackNode;

//初始化栈
void init(int data) {
    stackNode.head = (StackNode*)malloc(sizeof(StackNode));
    stackNode.head->data = data;
    stackNode.head->nextNode = NULL;
    stackNode.top = stackNode.head;
}
//栈是否为空
int isEmpty() {
    return (stackNode.head == NULL) ? 0 : 1;
}
//获得栈顶数据
int getTop() {
    if(stackNode.top == NULL){
        exit(1);
    }
    return stackNode.top->data;
}
//压入栈顶
void push(int data) {
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
//弹出栈顶
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
//输出栈中所有数据
void printAll(){
    if(isEmpty()){
        return;
    }
    StackNode *loop = stackNode.head;
    while (loop != NULL) {
        printf("%d\n",loop->data);
        loop = loop->nextNode;
    }
}
//初始化函数
void __attribute__((constructor)) function(void) {
    stackNode.isEmpty = isEmpty;
    stackNode.getTop = getTop;
    stackNode.push = push;
    stackNode.getTop = getTop;
    stackNode.printAll = printAll;
    stackNode.pop = pop;
}

#endif //PACKAG_STACKOFINT_H
