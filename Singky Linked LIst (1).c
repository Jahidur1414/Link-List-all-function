/*
Jahidur Rahman Fahim
Id - 171-15-1414
Dep _ CSE
*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node node;

node *head = NULL;

void append(int data)
{
    if(head ==  NULL){
        node *first = (node *)malloc(sizeof(node));;
        first->data = data;
        first->next = NULL;
        head = first;
    }
    else{
        node *temp = (node *)malloc(sizeof(node));
        temp = head;
        while(temp->next != 0){
            temp = temp->next;
        }
        node *newn = (node *)malloc(sizeof(node));
        newn->data = data;
        newn->next = NULL;

        temp->next = newn;
    }
}

void display()
{
    node *temp = (node *)malloc(sizeof(node));
    temp = head;
    printf("%d\n", temp->data);
    while(temp->next != 0){
        temp = temp->next;
        printf("%d\n", temp->data);
    }
}

void del(int data)
{
    node *temp;
    temp = head;
    node *prev = NULL;
    while(temp->data != data){
        prev = temp;
        temp = temp->next;
    }
    if(temp == head){
        node *tem = head;
        head = head->next;
        free(tem);
    }
    else{
        prev->next = temp->next;
        free(temp);
    }
}

int main()
{
    int i , n , size;
    scanf("%d", &size);
    for(i = 0; i < size; i++){
        scanf("%d", &n);
        append(n);
    }
    display();
    int dell;
    scanf("%d", &dell);
    del(dell);
    display();
}
