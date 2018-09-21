#include <stdio.h>
#include <stdlib.h>

struct Node{
int data;

struct Node *next;
};

typedef struct Node node;

node *head=0;

void append(int data)
{
    if(head==0)
    {
        head = (node *)malloc(sizeof(node));
        head->data=data;
        head->next=0;
    }
    else{
        node *temp = (node *)malloc(sizeof(node));
        temp=head;

        while(temp->next!=0)
        {
            temp=temp->next;
        }

        node *new_node = (node *)malloc(sizeof(node));
        new_node->data=data;
        new_node->next=0;
        temp->next=new_node;
    }
}

void dispaly()
{
    node *temp = (node *)malloc(sizeof(node));
    temp=head;

    while(temp->next!=0)
    {
        printf("%d\n", temp->data);
        temp=temp->next;
    }
    printf("%d\n", temp->data);
}
void search(node *head, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp=head;

    while(temp->next!=0)
    {
        temp=temp->next;

        if(temp->data==data)
        {
            printf("Found!!!!!\n");
            return;
        }
    }
    printf("Not Found!!!\n");
}

void delet(int pos)
{
    int i;
    node *temp = (node *)malloc(sizeof(node));
    node *prev = (node *)malloc(sizeof(node));
    temp=head;
    for(i=0; i<pos-1; i++)
    {
        prev=temp;
        temp=temp->next;
    }
    prev->next=temp->next;
    free(temp);
}

void insert_tail(int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp=head;

    while(temp->next!=0)
    {
        temp=temp->next;
    }
    node *tail = (node *)malloc(sizeof(node));
    tail->data=data;
    tail->next=0;
    temp->next=tail;
}
void modify(int pos, int data)
{
    node *temp = (node *)malloc(sizeof(node));
    temp=head;
    int i;
    for(i=0; i<pos-1; i++)
    {
        temp=temp->next;
    }
    temp->data=data;
}
int main()
{
    int n, i, num;

    printf("Enter the size\n");
    scanf("%d", &n);

    for(i=1; i<=n; i++)
    {
        scanf("%d", &num);
        append(num);
    }
    printf("All elements are\n");
    dispaly();
    printf("Enter the data which will found\n");
    int s;
    scanf("%d", &s);
    search(head, s);
    printf("Enter the data position which will delete\n");
    int d;
    scanf("%d", &d);
    delet(d);
    dispaly();
    printf("Enter the element which will insert in tail\n");
    int num2;
    scanf("%d", &num2);
    insert_tail(num2);
    dispaly();
    printf("Enter the data position which will modify\n");
    int ps;
    scanf("%d", &ps);
    printf("Enter the new data\n");
    int nd;
    scanf("%d", &nd);
    modify(ps, nd);
    printf("After modify the data\n");
    dispaly();
}
