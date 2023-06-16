#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} sn;

sn *head;

void traverse()
{

    printf("\nElement - ");
    sn *ptr = head;
    int i = 0;
    if (head == NULL)
    {
        printf("EMPTY");
    }
    do
    {
        printf("%d[%d] ", ptr->data, i++);
        ptr = ptr->next;

    } while (ptr != head);
    printf("\n");
}

void insertAtFirst(int data)
{
    sn *ptr = (sn *)malloc(sizeof(sn));
    if (head == NULL)
    {
        ptr->data = data;
        head = ptr;
        ptr->next = head;
    }
    else
    {

        ptr->data = data;
        sn *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        head = ptr;
    }
    traverse(head);
}

void insertAtEnd(int data)
{
    sn *ptr = (sn *)malloc(sizeof(sn));
    ptr->data = data;
    ptr->next = NULL;
    if (head == NULL)
    {
        head = ptr;
        ptr->next = head;
    }
    else
    {
        sn *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        traverse(head);
    }
}

void insertBeforeIndex(int data, int index)
{
    if (head == NULL)
    {
        printf("\nNode Null");
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
        p->next = ptr;
        traverse(head);
    }
}

void deleteAtFirst()
{
    if (head == NULL)
    {
        printf("\nNode Null");
    }
    else
    {
        sn *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = head->next;
        sn *temp = head;
        head = head->next;
        free(temp);
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
        sn *temp = head;
        int j = 0;
        while (temp->next != head)
        {
            temp = temp->next;
            j++;
        }

        if (j >= 2)
        {
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
        else
        {
            printf("\n Not sufficient node for deletion at index\n");
        }
    }
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("\nNode Null");
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
    }
    else
    {
        sn *p = head;
        sn *q = head->next;
        while (q->next != head)
        {
            p = p->next;
            q = q->next;
        }
        p->next = head;
        free(q);
        traverse(head);
    }
}

int main()
{
    int choice, value, index;
    while (choice != 8)
    {
        printf("\n----------CIRCULAR LL----------");
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