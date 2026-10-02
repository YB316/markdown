#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;
int findNode(Node *head,int n)  //查找元素
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
Node* athead(Node *head, int n)  //头插
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = n;
    newNode->next = head;

    return newNode;
}
Node* attail(Node *head,int n)  //尾插
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
Node* createNode(int value)  //创建节点
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;

    newNode->next = NULL;

    return newNode;
}
void printlist(Node *head)  //遍历打印
{
    Node *cur = head;
    while (cur != NULL){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
Node* deleteNode(Node *head,int n)  //删除
{
    if (head == NULL || n<1)
    return false;
    if (n==1){
        Node *temp =head;
        head =head->next;
        free(temp);
        return true;
    }

    Node *prev = head;
    Node *cur = head;
    int i = 1;
    while (cur != NULL && i < n){
        prev = cur;
        cur = cur->next;
        i++;
    }
    if (cur == NULL)
    return true;
    
    prev->next = cur->next;
    free(cur);
    return true;
}
void over(Node *head)  //倒置
{
    Node *prev = NULL;
    Node *cur = head;
    Node *next = NULL;

    while(cur != NULL)
    {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}