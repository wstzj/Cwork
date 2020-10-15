//
// Created by tangz on 2020/9/25.
//

#ifndef PACKAG_LINKLIST_H
#define PACKAG_LINKLIST_H

#include <stdio.h>
#include <stdlib.h>

//���ݶ���
typedef int dataType;

//�ṹ��
typedef struct LinkList {

    dataType data;
    struct LinkList *next;

} List;

//��ʼ��
List *init() {
    return NULL;
}

//�Ƿ�Ϊ��
int isEmpty(List *head) {
    return (!head) ? 0 : 1;
}

//���
void display(List *head) {
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!");
        return;
    }
    List *p = head;
    while (p) {
        printf("%5d", p->data);
        p = p->next;
    }
    printf("\n");
}

//����
List *find(List *head, int location) {
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!");
        return NULL;
    }
    if (location < 1)
        return NULL;
    List *p = head;
    int j = 1;
    while (p && j != location) {
        p = p->next;
        ++j;
    }
    return p;
}

//���
List *insert(List *head, int location, dataType i) {
    List *p, *q;
    q = find(head, location);
    if (!q && location >= 1) {
        printf("�Ҳ�����������λ�á�\nLocation Not Found\n");
    }
    p = (List *) malloc(sizeof(List));
    p->data = i;
    if (location == 0) {
        p->next = head;
        head = p;
    } else {
        p->next = q->next;
        q->next = p;
    }
    return head;
}

//β�����
List *push(List *head, dataType i) {

    if (head == NULL) {
        head = (List *) malloc(sizeof(List));
        head->data = i;
        head->next = NULL;
        return head;
    }
    List *p = head;
    while (p->next) {
        p = p->next;
    }
    List *q = (List *) malloc(sizeof(List));
    q->next = NULL;
    q->data = i;
    p->next = q;
    return head;
}

//ɾ��
List *delete(List *head, dataType i) {
    List *p, *q = NULL;
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!");
        return head;
    }
    p = head;
    while (p && p->data != i) {
        q = p;
        p = p->next;
    }
    if (p) {
        if (!q)
            head = head->next;
        else
            q->next = p->next;
        free(p);
    }
    return head;
}

//3.2
void Num(List *head) {
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!");
        return;
    }
    List *p = head;
    int i = 0;
    while (p) {
        ++i;
        p = p->next;
    }
    printf("һ����%d�����\nTotal Node has %d", i, i);
}

//3.3
void NumTakeHead(List *head) {
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!");
        return;
    }
    List *p = head;
    int i = 0;
    while (!p) {
        ++i;
        p = p->next;
    }
    printf("һ����%d�����\nTotal Node has %d\n", i, i);
}

//3.4
List *InsertXBeforeY(List *head, dataType x, dataType y) {
    List *p, *q = NULL, *point;
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!\n");
        return head;
    }
    p = head;
    while (p && p->data != y) {
        q = p;
        p = p->next;
    }

    if (p) {
        point = (List *) malloc(sizeof(List));
        point->data = x;
        point->next = head;
        if (!q) {
            head = point;
        } else {
            point->next = p;
            q->next = point;
        }
    } else {
        printf("û���ҵ�Y \n Y is Not Found\n");
    }
    return head;
}

//3.5
/*
 * return
 * -2 ����Ϊ��
 * -1 ����
 *  1 ����
 */
int justice(int q, int p) {
    if (q < p)
        return 1;
    else if (q == p)
        return 0;
    else
        return -1;
}

int isSorted(List *head) {

    int flag;//����:1, С��:-1, ����:0

    int q, p;


    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!\n");
        return -2;
    }
    if (head->next == NULL) {
        return 1;
    }
    q = head->data;
    List *point = head->next;
    p = point->data;
    flag = justice(q, p);
    while (point->next) {
        q = point->data;
        p = point->next->data;
        point = point->next;
        if (flag == 0) {
            flag = justice(q, p);
            continue;
        }
        if (flag != justice(q, p)) {
            return -1;
        }
    }
    return 1;
}

//3.6
List *Reverse(List *head) {
    List *p, *q;
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!\n");
        return head;
    }
    if (head->next == NULL)
        return head;
    p = head->next;
    head->next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = head;
        head = p;
        p = q;
    }
    return head;
}

//3.7
List *spilt(List *head){
    List *p = head;
    List *Even = init();
    int temp = p->data;
    while(p){
        temp = p->data;
        if (temp % 2 == 0){
            Even = push(Even,temp);
            p = p->next;
            head = delete(head,temp);
        } else{
            p = p->next;
        }
    }
    return Even;
}

//3.8
List *DeleteBetweenXY(List *head, dataType x, dataType y) {
    List *p, *q;
    p = head;
    q = p;
    p = p->next;
    if (!isEmpty(head)) {
        printf("�յģ�\n Is Empty!\n");
        return head;
    }
    while (p != NULL) {
        if ((p->data > x) && (p->data < y)) {
            q->next = p->next;
            free(p);
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
    return head;
}

#endif //PACKAG_LINKLIST_H
