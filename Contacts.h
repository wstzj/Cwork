//
// Created by Administrator on 2020/10/7.
//

#ifndef PHONELIST_CONTACTS_H
#define PHONELIST_CONTACTS_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
//通话记录
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
//初始化
history *init(){
    return NULL;
}
//遍历
void display(history *head){
    history *p;
    p = head;
    if (!p){
        printf("为空");
        return;
    }
    while (p!=NULL){
        printf("电话:%s  时间:%s  状态:%s\n",p->phone,ctime(&(p->time)),p->Call);
        p=p->next;
    }
}
//创建通讯录
contacts *create_phone_list(){
    contacts *p = (contacts *)malloc(sizeof(contacts));
    printf("请输入第一个联系人名字和电话:\n");
    scanf("%s %s",p->name,p->phone_number);
    printf("录入成功\n");
    p->next = NULL;
    p->historyHead = init();
    return p;
}
//查找要删除的用户的父节点
contacts *search_last_user(contacts *t,char name[]){
    contacts *p = t;
    while (p->next){
        if (strcmp(p->next->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}
//查找用户
contacts *search_user(contacts *t,char name[]){
    contacts *p = t;
    while (p!=NULL){
        if (strcmp(p->name,name)==0)
            return p;
        p = p->next;
    }
    return NULL;
}
//插入通讯记录
char *callType(int typecode){
    switch (typecode) {
        case 0: return "拨出";
        case 1: return "来电";
        case 2: return "拒接";
        case 3: return "未接";
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
        printf("没有找到这个人！\n");

    return head;
}
//输出与某个人的通讯记录
void displayUserHistory(contacts *head ,char name[]){
    contacts *user = search_user(head,name);
    if(user !=NULL){
        display(user->historyHead);
    }else
        printf("没有找到这个人！\n");
}
//删除用户
contacts *delete_user(contacts *head,char name[]){
    contacts *user = search_last_user(head,name);
    if (user!=NULL){
        contacts *t = user->next;
        user->next = user->next->next;
        free(t);
        printf("删除成功\n");
    } else if (strcmp(head->name, name) == 0){
        contacts *t = head;
        head = head->next;
        free(t);
        printf("删除成功\n");
    } else{
        printf("没有找到这个人！\n");
    }
    return head;
}
//添加用户
void push_user(contacts *head){
    contacts * p = head;
    while (p->next!=NULL){
        p = p->next;
    }
    contacts *t =(contacts*)malloc(sizeof(contacts));
    printf("录入姓名：\n");
    scanf("%s",t->name);
    int name_size = strlen(t->name);
    if (name_size > 20) {
        printf("名字太长了\n");
        return;
    }
    t->next = NULL;
    p->next = t;
    printf("添加成功！,请录入%s同学的电话\n",t->name);
    scanf("%s",p->next->phone_number);
}
//输出通讯录
void print_contacts(contacts *p){
    while (p!=NULL){
        printf("%s:%s \n",p->name,p->phone_number);
        p=p->next;
    }

}
#endif //PHONELIST_CONTACTS_H
