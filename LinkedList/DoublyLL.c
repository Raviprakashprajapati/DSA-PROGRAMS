
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} sn;

void traverse(sn *head){
    printf("\nELEMENT = ");
    int i = 0;
    while (head!=NULL)
    {
        printf("%d[%d]  " , head->data,i++);
        head = head->next;
    }
}

sn *insertAtFirst(sn *head,int data){
    sn *ptr = (sn *)malloc(sizeof(sn));
    ptr->data = data;
    head->prev = ptr;
    ptr->next = head;
    ptr->prev = NULL;
    head = ptr;
    return head;
}

sn *insertAtEnd(sn *head,int data){
    sn *ptr= (sn *)malloc(sizeof(sn));
    ptr->data = data;
    sn *p = head;
    while (p->next!=NULL)
    {
         p =p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
    
}

sn *insertBeforeIndex(sn *head,int data,int index){
    sn *ptr= (sn *)malloc(sizeof(sn));
    ptr->data=  data;
    sn *p = head;
    sn *q = head->next;
    int i=0;
    while (i!=index-1)
    {
        p= p->next;
        q = q->next;
        i++;
    }
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;
    ptr->next = q;
    return head;
    
}

sn *deletionAtFirst(sn *head){
    sn *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    return head;
}

sn *deletionAtEnd(sn *head){
    sn *p = head;
    sn *q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
    
}

sn *deletionAtIndex(sn *head,int index){
    sn *p = head;
    sn *q = head->next;
    int i = 0;
    while (i!=index-1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    q->next->prev = p;
    free(q);
    return head;
}

int main(){
    printf("---------------------------------------");
    sn *head;
    sn *second;
    sn *third;
    sn *four;
    head = (sn *)malloc(sizeof(sn));
    second = (sn *)malloc(sizeof(sn));
    third = (sn *)malloc(sizeof(sn));
    four = (sn *)malloc(sizeof(sn));
    head->prev = NULL;
    head->data = 100;
    head->next = second;
    second->prev = head;
    second->data = 200;
    second->next = third;
    third->prev = second;
    third->data = 300;
    third->next = NULL;
    
    traverse(head);
    head = insertAtFirst(head,99);
    head = insertAtFirst(head,88);
    head = insertAtFirst(head,77);
    traverse(head);
    head = insertAtEnd(head,400);
    traverse(head);
    head = insertBeforeIndex(head,111,3);
    head = insertBeforeIndex(head,222,3);
    traverse(head);
    head = deletionAtFirst(head);
    traverse(head);
    head = deletionAtEnd(head);
    traverse(head);
    head = deletionAtIndex(head,3);
    traverse(head);
    head = deletionAtIndex(head,3);
    traverse(head);


  





    printf("\n---------------------------------------");
}