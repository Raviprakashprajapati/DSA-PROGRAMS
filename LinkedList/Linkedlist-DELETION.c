#include<stdio.h>
#include<stdlib.h>

 typedef struct node
{
    int data;
    struct node  *next;
}sn;

void traverse(sn *ptr){
    int i = 0;
    printf("\nELEMENTS IS = ");
    while (ptr!=NULL)
    {
        printf("%d[%d]  ", ptr->data,i++);
        ptr=  ptr->next;
        
    }
    
}

sn *deleteAtFirst(sn *head){
    sn *p = head;
    head = head->next;
    free(p);
    return head;

}

sn *deleteAtIndex(sn *head,int index){
    sn * p = head;
    int i=0;
    while (i!=index-1)
    {
        p= p->next;
        i++;
    }
    sn *q = p->next;
    p->next = q->next;
    free(q);
    return head;

    
}

sn *deleteAtLast(sn *head){
    sn *p = head;
    sn *q = head->next;
    while (q->next!=NULL)
    {
        p = p->next;
        q = q->next;
    }
    free(q);
    p->next = NULL;
    return head;

}

sn *deleteAtElement(sn *head,int n){
    sn *p = head;
    sn *q = head->next;
    while (q->data!=n && q->next!=NULL)
    {
        p = p->next;
        q= q->next;
    }
    
    if (q->data==n)
    {
        p->next = q->next;
    }
    

    free(q);
    return head;

    
}



int main(){

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
    head->data =100;
    head->next = second;
    second->data = 200;
    second->next = third;
    third->data = 300;
    third->next = four;
    four->data = 400;
    four->next = fifth;
    fifth->data = 500;
    fifth->next =  NULL;

    traverse(head);
    head = deleteAtFirst(head);
    traverse(head);
    head = deleteAtIndex(head,2);
    traverse(head);
    head = deleteAtLast(head);
    traverse(head);
    head = deleteAtElement(head,300);
    traverse(head);




    printf("\n---------------------------------------");
}
