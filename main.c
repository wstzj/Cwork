#include "Contacts.h"

int main() {
    printf("��ʼ����ͨѶ¼:\n");
    contacts *head = create_phone_list();
    printf("ͨѶ¼�Ѵ�����\n");
    while(1) {
        printf("���������ּ�����\n");
        int nums;
        scanf("%d",&nums);
        printf("������Ž���ѡ��:\n"
               "0.�˳�ͨѶ¼\n"
               "1.����ͨѶ¼\n"
               "2.����ĳλͬѧ\n"
               "3.¼��ĳλͬѧ��ͨѶ��¼\n"
               "4.������г�Ա�ļ�¼\n"
               "5.���ĳλ��Ա����Ϣ\n"
               "6.ɾ��ĳλ��Ա�ļ�¼\n"
               "7.���ĳλ��Ա��ͨѶ��¼\n");
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
                printf("������ͬѧ������\n");
                scanf("%s",name);
                printf("������ͬѧ�ĵ绰\n");
                scanf("%s",phone);
                printf("����ͨ����¼״̬\n"
                       "\"����\":0;\n"
                       "\"����\":1;\n"
                       "\"�ܽ�\":2;\n"
                       "\"δ��\":3;\n");
                int callTypeCode;
                scanf("%d",&callTypeCode);
                push_history(head,name,callTypeCode,phone);
                break;
            case 4:
                print_contacts(head);
                break;
            case 5:
                printf("������ͬѧ������\n");
                scanf("%s",name);
                contacts *user = search_user(head,name);
                printf("%s:%s\n",user->name,user->phone_number);
                break;
            case 6:
                printf("������ͬѧ������\n");
                scanf("%s",name);
                head=delete_user(head,name);
                break;
            case 7:
                printf("������ͬѧ������\n");
                scanf("%s",name);
                displayUserHistory(head,name);
                break;
        }
        printf("\n");
    }
    return 0;
}
