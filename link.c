
#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *link;
};


struct Node *head = NULL;


void insertAtBeginning(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = head;
    head = newNode;

    printf("\nInsertion Successful");
}


void insertAtEnd(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *end = head;
    if (end != NULL)
    {
        while (end->link != NULL)
        {
            end = end->link;
        }
        end->link = newNode;
    }
    else
        head = newNode;

    printf("\nInsertion Successful");
}


void insertAfterPosition(int position, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->link = NULL;
    struct Node *curr = head;
    while (curr != NULL && --position)
        curr = curr->link;
    if (curr == NULL)
    {
        printf("\nPosition exceeded list size");
        return;
    }
    newNode->link = curr->link;
    curr->link = newNode;

    printf("\nInsertion Successful");
}


void deleteElement(int element)
{
    struct Node *curr = head, *prev = NULL;
    while (curr != NULL && curr->data != element)
    {
        prev = curr;
        curr = curr->link;
    }
    if (curr == NULL)
    {
        printf("\nElement not found");
        return;
    }
    if (prev == NULL)
        head = head->link;
    else
        prev->link = curr->link;

    free(curr);
    printf("\nDeletion Successful");
}

void deleteFromBeginning()
{
    if (head == NULL)
    {
        printf("\nList is empty. Deletion not possible.");
        return;
    }

    struct Node *temp = head;
    head = head->link;
    free(temp);

    printf("\nDeletion from the beginning successful");
}


void deleteFromEnd()
{
    if (head == NULL)
    {
        printf("\nList is empty. Deletion not possible.");
        return;
    }

    struct Node *curr = head, *prev = NULL;


    while (curr->link != NULL)
    {
        prev = curr;
        curr = curr->link;
    }

    if (prev == NULL)
    {
      
        free(curr);
        head = NULL;
    }
    else
    {
       
        prev->link = NULL;
        free(curr);
    }

    printf("\nDeletion from the end successful");
}

void display()
{
    struct Node *ptr = head;
    if (ptr == NULL)
    {
        printf("\nList empty");
        return;
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}


int main()
{
    int ch, element, pos;
    do
    {
        printf("\n\nChoose operation");
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert at position");
        printf("\n4.Delete node containing a particular element ");
         printf("\n5.Delete from end of linked list");
          printf("\n6.Delete from front of linked list");
        printf("\n7.Display linked list");

        printf("\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAtBeginning(element);
            break;
        case 2:
            printf("\nEnter element to insert  ");
            scanf("%d", &element);
            insertAtEnd(element);
            break;
        case 3:
            printf("\nEnter the position after which node will be inserted ");
            scanf("%d", &pos);
            printf("\nEnter element to insert ");
            scanf("%d", &element);
            insertAfterPosition(pos, element);
            break;
        case 4:
            printf("\nEnter element to delete ");
            scanf("%d", &element);
            deleteElement(element);
            break;
        case 5 :
             deleteFromEnd() ;
            break ;
        case 6 :
             deleteFromBeginning() ;
            break ;
        case 7:
            display();
            break;
       
        }
    } while (ch < 8);

    
}



