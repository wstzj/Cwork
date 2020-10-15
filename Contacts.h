//
// Created by Administrator on 2020/10/7.
//

#ifndef PHONELIST_CONTACTS_H
#define PHONELIST_CONTACTS_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
//ͨ����¼
typedef struct phoneCallHistory{
    char phone[13];
    time_t time;
    char Call[2];
    struct phoneCallHistory *next;
}history;
typedef struct contacts{
    char name[20];
    char phone_number[13];
    struct contacts *next;
    history *historyHead;
}contacts;
//��ʼ��
history *init(){
    return NULL;
}
//����
void display(history *head){
    history *p;
    p = head;
    if (!p){
        printf("Ϊ��");
        return;
    }
    while (p!=NULL){
        printf("�绰:%s  ʱ��:%s  ״̬:%s\n",p->phone,ctime(&(p->time)),p->Call);
        p=p->next;
    }
}
//����ͨѶ¼
contacts *create_phone_list(){
    contacts *p = (contacts *)malloc(sizeof(contacts));
    printf("�������һ����ϵ�����ֺ͵绰:\n");
    scanf("%s %s",p->name,p->phone_number);
    printf("¼��ɹ�\n");
    p->next = NULL;
    p->historyHead = init();
    return p;
}
//����Ҫɾ�����û��ĸ��ڵ�
contacts *search_last_user(contacts *t,char name[]){
    contacts *p = t;
    while (p->next){
        if (strcmp(p->next->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}
//�����û�
contacts *search_user(contacts *t,char name[]){
    contacts *p = t;
    while (p!=NULL){
        if (strcmp(p->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}
//����ͨѶ��¼
char *callType(int typecode){
    switch (typecode) {
        case 0: return "����";
        case 1: return "����";
        case 2: return "�ܽ�";
        case 3: return "δ��";
    }
}
contacts *push_history(contacts *head,char name[],int callTypeCode,char phone[]){
    contacts *user = search_user(head,name);
    if (user!=NULL){
        if (!user->historyHead){
            user->historyHead = (history*) malloc(sizeof(history));
            user->historyHead->next =NULL;
            time(&(user->historyHead->time));
            char *str = callType(callTypeCode);
            strcpy(user->historyHead->Call,str);
            strcpy(user->historyHead->phone,phone);
        } else{
            history *p = user->historyHead;
            history *q = (history*) malloc(sizeof(history));
            q ->next =NULL;
            time(&(q->time));
            strcpy(q->Call,callType(callTypeCode));
            strcpy(q->phone,phone);
            while (p ->next != NULL){
                p = p->next;
            }
            p->next= q;
        }
    } else
        printf("û���ҵ�����ˣ�\n");

    return head;
}
//�����ĳ���˵�ͨѶ��¼
void displayUserHistory(contacts *head ,char name[]){
    contacts *user = search_user(head,name);
    if(user !=NULL){
        display(user->historyHead);
    }else
        printf("û���ҵ�����ˣ�\n");
}
//ɾ���û�
contacts *delete_user(contacts *head,char name[]){
    contacts *user = search_last_user(head,name);
    if (user!=NULL){
        contacts *t = user->next;
        user->next = user->next->next;
        free(t);
        printf("ɾ���ɹ�\n");
    } else if (strcmp(head->name, name) == 0){
        contacts *t = head;
        head = head->next;
        free(t);
        printf("ɾ���ɹ�\n");
    } else{
        printf("û���ҵ�����ˣ�\n");
    }
    return head;
}
//����û�
void push_user(contacts *head){
    contacts * p = head;
    while (p->next!=NULL){
        p = p->next;
    }
    contacts *t =(contacts*)malloc(sizeof(contacts));
    printf("¼��������\n");
    scanf("%s",t->name);
    int name_size = strlen(t->name);
    if (name_size > 20) {
        printf("����̫����\n");
        return;
    }
    t->next = NULL;
    p->next = t;
    printf("��ӳɹ���,��¼��%sͬѧ�ĵ绰\n",t->name);
    scanf("%s",p->next->phone_number);
}
//���ͨѶ¼
void print_contacts(contacts *p){
    while (p!=NULL){
        printf("%s:%s \n",p->name,p->phone_number);
        p=p->next;
    }

}
#endif //PHONELIST_CONTACTS_H
