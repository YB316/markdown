#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
int findNode(Node *head,int n)
{
    int pos = 1;
    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->data == n)
        return pos;
        cur = cur->next;
        pos++;
    }
    return -1;
}

int main()
{

    Node *Head = creatNode(0);
    Node *A = athead(Head,100);

    Head = A;

    Node *B = creatNode(100);

    B = attail(B,200);

    printlist(B);

    fresList(B);


    return 0;
}
Node* athead(Node *head, int n)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = head;

    return newNode;
}
Node* attail(Node *head,int n)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = NULL;

    if (head == NULL)
    {
        return newNode;
    }

    Node *cur = head;
    while (cur->next !=NULL)
    {
        cur = cur->next;
    }
    cur->next = newNode;

    return head;
}
Node* createNode(int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = NULL;

    return newNode;
}
void printlist(Node *head)
{
    Node *cur = head;
    while (cur != NULL){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
Node* deleteNode(Node *head,int n){
    if (head ->data == n){
        Node *temp =head;
        head =head->next;
        free(temp);
        return head;
    }

    Node *cur = head;
    while (cur->next != NULL && cur->next->data !=n){
        cur =cur->next;
    }
    if (cur->next !=NULL){
        Node *temp = cur->next;
        cur->next = temp->next;
        free(temp);
    } else {
        printf("未找到%d\n",n);
    }
    return head;
}
