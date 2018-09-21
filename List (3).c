#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node node;

node *head = 0;

void append(int data)
{
    if(head == 0)
    {
        head = (node *)malloc(sizeof(node));
        head->data = data;
        head->next = 0;
    }
    else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp = head;
        while(temp->next != 0)
        {
            temp = temp->next;
        }
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data;
        new_node->next = 0;
        temp->next = new_node;
    }
}
void insert_tail(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while(temp->next != 0)
    {
        temp = temp->next;
    }
    node *tail = (node *)malloc(sizeof(node));
    tail->data = data;
    tail->next = 0;
    temp->next = tail;
}

void count()
{
    int count = 1;
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while(temp->next != 0)
    {
        temp = temp->next;
        count++;
    }
    printf("Total Number = %d\n", count);
}

void modify_num(int pos, int data)
{
    int i;
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    for(i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    temp->data = data;
}

void delete_node(int pos)
{
    int i;
    node *temp = (node *)malloc(sizeof(node));
    node *prev = (node *)malloc(sizeof(node));
    temp = head;
    for(i = 0; i < pos - 1; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
}

void search(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while(temp->next != 0)
    {
        temp = temp->next;
        if(temp->data == data)
        {
            printf("Found!\n");
            return;
        }
    }
    printf("Not Found!\n");
}

void display()
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    while(temp->next != 0)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d\n", temp->data);
}

int main()
{
    append(12);
    append(19);
    append(19);
    append(18);
    append(15);
    display();
    delete_node(3);
    display();
    printf("\n80 : ");
    search(head, 80);
    printf("\n");
    display();
    printf("\n");
    count();

    return 0;
}
