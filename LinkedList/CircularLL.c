
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sn;

void traverse(sn *head){

    sn *ptr= head;
    int i = 0;
    printf("\nELEMENT = ");
    do
    {
        printf("%d[%d]  ", ptr->data,i++);
        ptr= ptr->next;
    } while (ptr!=head);
    
}

sn *insertAtFirst(sn *head,int data){
    sn *ptr = (sn *)malloc(sizeof(sn));
    sn *p = head->next;
    ptr->data = data;
    while (p->next!=head)
    {
        p = p->next;
    }
    p->next = ptr;

    ptr->next = head;
    head = ptr;
    return head;
    
}

sn *insertAtEnd(sn *head,int data){
    sn *ptr =  (sn *)malloc(sizeof(sn));
    sn *p = head->next;
    ptr->data = data;
    while (p->next!=head)
    {
        p = p->next;
    }

    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}

sn *insertAtIndex(sn *head,int data,int index){
    sn *ptr = (sn *)malloc(sizeof(sn));
    sn *p = head;
    ptr->data = data;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
    
}

sn *insertAfterNode(sn *head,int data,sn *prevNode){
    sn *ptr =  (sn *)malloc(sizeof(sn));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}


int main()
{

    printf("---------------------------------------");
    sn *head;
    sn *second;
    sn *third;
    sn *four;
    sn *fifth;
    head = (sn *)malloc(sizeof(sn));
    second = (sn *)malloc(sizeof(sn));
    third = (sn *)malloc(sizeof(sn));
    four = (sn *)malloc(sizeof(sn));
    fifth = (sn *)malloc(sizeof(sn));
    head->data = 100;
    head->next = second;
    second->data = 200;
    second->next = third;
    third->data = 300;
    third->next = four;
    four->data = 400;
    four->next = fifth;
    fifth->data = 500;
    fifth->next = head;

    traverse(head);
    head = insertAtFirst(head,99);
    traverse(head);
    head  = insertAtEnd(head,999);
    traverse(head);
    head = insertAtIndex(head,420,3);
    traverse(head);
    head = insertAfterNode(head,555,third);
    traverse(head);

    printf("\n---------------------------------------");

}