#include "Contacts.h"

int main() {
    printf("开始创建通讯录:\n");
    contacts *head = create_phone_list();
    printf("通讯录已创建！\n");
    while(1) {
        printf("按任意数字键继续\n");
        int nums;
        scanf("%d",&nums);
        printf("输入序号进入选项:\n"
               "0.退出通讯录\n"
               "1.重置通讯录\n"
               "2.插入某位同学\n"
               "3.录入某位同学的通讯记录\n"
               "4.输出所有成员的记录\n"
               "5.输出某位成员的信息\n"
               "6.删除某位成员的记录\n"
               "7.输出某位成员的通讯记录\n");
        int num = 0;
        scanf("%d",&num);
        if (num==0){
            break;
        }
        char name[20];
        char phone[20];
        switch (num){
            case 0:
                break;
            case 1:
                head = create_phone_list();
                break;
            case 2:
                push_user(head);
                break;
            case 3:;
                printf("请输入同学的名字\n");
                scanf("%s",name);
                printf("请输入同学的电话\n");
                scanf("%s",phone);
                printf("输入通话记录状态\n"
                       "\"拨出\":0;\n"
                       "\"来电\":1;\n"
                       "\"拒接\":2;\n"
                       "\"未接\":3;\n");
                int callTypeCode;
                scanf("%d",&callTypeCode);
                push_history(head,name,callTypeCode,phone);
                break;
            case 4:
                print_contacts(head);
                break;
            case 5:
                printf("请输入同学的姓名\n");
                scanf("%s",name);
                contacts *user = search_user(head,name);
                printf("%s:%s\n",user->name,user->phone_number);
                break;
            case 6:
                printf("请输入同学的姓名\n");
                scanf("%s",name);
                head=delete_user(head,name);
                break;
            case 7:
                printf("请输入同学的姓名\n");
                scanf("%s",name);
                displayUserHistory(head,name);
                break;
        }
        printf("\n");
    }
    return 0;
}
