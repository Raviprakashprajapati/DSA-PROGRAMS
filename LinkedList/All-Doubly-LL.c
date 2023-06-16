#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} sn;

sn *head;

void traverse(sn *head)
{
    sn *ptr = head;
    int i = 0;
    printf("\nELEMENT = ");
    while (ptr != NULL)
    {
        printf("%d[%d] ", ptr->data, i++);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtFirst(int data)
{
    sn *ptr = (sn *)malloc(sizeof(sn));
    ptr->data = data;
    if (head == NULL)
    {

        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        sn *p = head;
        ptr->next = head;
        ptr->prev = NULL;
        p->prev = ptr;
        head = ptr;
    }
    traverse(head);
}

void insertBeforeIndex(int data, int index)
{
    if (head == NULL)
    {
        printf("\nNode NULL");
    }
    else
    {
        sn *ptr = (sn *)malloc(sizeof(sn));
        ptr->data = data;
        sn *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next->prev = ptr;
        p->next = ptr;
        ptr->prev = p;
        traverse(head);
    }
}

void insertAtEnd(int data)
{
    if (head == NULL)
    {
        printf("\nNode NULL");
    }
    else
    {
        sn *ptr = (sn *)malloc(sizeof(sn));
        ptr->data = data;
        sn *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;
        ptr->next = NULL;
        traverse(head);
    }
}

void deleteAtFirst()
{
    if (head == NULL)
    {
        /* code */
        printf("\nNode Null");
    }
    else
    {
        sn *p = head;
        head = head->next;
        free(p);
        traverse(head);
    }
}

void deleteAtIndex(int index)
{
    if (head == NULL)
    {
        printf("\nNode Null");
    }
    else
    {

        sn *p = head;
        int i = 0;
        if (index == 0 && head->next!=NULL)
        {
            head = head->next;
            head->prev = NULL;
            free(p);
            traverse(head);
            return;
        }
        else if(index==0 || head->next!=NULL){
            printf("\nNot able to delete single node");
        }
        else
        {
            printf("under else else");
            sn *q = head->next;
            while (i != index - 1)
            {
                p = p->next;
                q = q->next;
                i++;
            }
            q->next->prev = p;
            p->next = q->next;
            free(q);

            traverse(head);
            return;
        }
    }
}

void deleteAtEnd(){
    if (head==NULL )
    {
        printf("\nNode Null");
    }
    else
    {
        if (head->next==NULL)
        {
            head = NULL;
            printf("\nNode Null Now");

        }
        else
        {
            sn *p = head;
            sn * q = head->next;
            while (q->next!=NULL)
            {
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            free(q);
            traverse(head);
            
        }
        

    }
    

}




int main()
{
    int choice, value, index;
    while (choice != 8)
    {
        printf("\n----------Doubly LL----------");
        printf("\nInsertion");
        printf("\n1:First | 2:BeforeIndex | 3:End");
        printf("\nDeletion");
        printf("\n4:First | 5:INDEX       | 6:End");
        printf("\n7:DISPLAY    |   8:EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the Value = ");
            scanf("%d", &value);
            insertAtFirst(value);
            break;
        case 2:
            printf("\nEnter the Value and index  = ");
            scanf("%d %d", &value, &index);
            insertBeforeIndex(value, index);
            break;
        case 3:
            printf("\nEnter the Value = ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            printf("\nEnter the Index = ");
            scanf("%d", &index);
            deleteAtIndex(index);
            break;
            case 6:
                deleteAtEnd();
                break;
            case 7:
                traverse(head);
                break;

        default:
            printf("\nINVALID NUMBER");
            break;
        }
    }
}