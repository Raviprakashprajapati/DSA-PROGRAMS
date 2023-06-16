#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sn;

sn *head = NULL;

void traverse(sn *head)
{
    sn *ptr = head;
    printf("\nELEMENT = ");
    int i = 0;
    while (ptr != NULL)
    {
        printf("%d[%d]  ", ptr->data, i++);
        ptr = ptr->next;
    }
    printf("\n");
}

void insertAtFirst(int data)
{
    sn *ptr = (sn *)malloc(sizeof(sn));

    if (head == NULL)
    {
        ptr->data = data;
        ptr->next = NULL;
        head = ptr;
    }
    else
    {
        ptr->data = data;
        ptr->next = head;
        head = ptr;
    }
    traverse(head);
}

void insertAtIndex(int data, int index)
{
    sn *ptr = (sn *)malloc(sizeof(sn));
    if (head == NULL)
    {
        printf("NODE IS EMPTY\n");
    }
    else
    {
        int i = 0;
        sn *p = head;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        traverse(head);
    }
}

void insertAtEnd(int data)
{
    sn *ptr = (sn *)malloc(sizeof(sn));
    if (head == NULL)
    {
        printf("Node is Empty\n");
    }
    else
    {
        sn *p = head;
        ptr->data = data;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
        traverse(head);
    }
}

void deleteAtFirst()
{
    if (head == NULL)
    {
        printf("Node is Empty\n");
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
        printf("Node is Empty\n");
    }
    else
    {
        printf("under else");
        sn *p = head;
        sn *q = head->next;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        free(q);
        traverse(head);
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("Node is Empty\n");
    }
    else
    {
        sn *p = head;
        sn *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
        traverse(head);
    }
}

int main()
{

    printf("====================================");
    int choice;
    int value, index;
    while (choice != 8)
    {
        printf("\n----------------------");
        printf("\nInsertion");
        printf("\n1:First | 2:BeforeIndex | 3:End");
        printf("\nDeletion");
        printf("\n4:First | 5:INDEX       | 6:End");
        printf("\n7:DISPLAY    |   8:EXIT\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the Value = ");
            scanf("%d", &value);
            insertAtFirst(value);
            break;
        case 2:
            printf("Enter the Value and index = ");
            scanf("%d %d", &value, &index);
            insertAtIndex(value, index);
            break;
        case 3:
            printf("Enter the Value = ");
            scanf("%d", &value);
            insertAtEnd(value);
            break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            printf("Enter the Index = ");
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

    printf("\n====================================");
}
