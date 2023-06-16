#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void traverse(struct node *ptr){
    int i = 0;
    printf("\nELEMENTS IS = ");
    while (ptr!=NULL)
    {
        printf("%d[%d]  ", ptr->data,i++);
        ptr=  ptr->next;
        
    }
    
}

struct node *insertAtBegin(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr;

}

struct node *insertAtEnd(struct node *head,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p =head;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
    return head;
}

struct node *insertAtIndex(struct node *head,int data,int index){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr->data = data;
    int i=0;
    while (i!=index-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
    

}

struct node *insertAfterNode(struct node *head,struct node *prevNode,int data){
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;

}


int main(){

    printf("----------------------------");
    struct node *head;
    struct node *second;
    struct node *third;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    head->data =100;
    head->next = second;
    second->data = 200;
    second->next = third;
    third->data = 300;
    third->next = NULL;

    traverse(head);
    head = insertAtBegin(head,99);
    traverse(head);
    head = insertAtEnd(head,999);
    traverse(head);
    head = insertAtIndex(head,111,2);
    traverse(head);
    head = insertAfterNode(head,head,420);
    traverse(head);



    printf("\n----------------------------");

}
