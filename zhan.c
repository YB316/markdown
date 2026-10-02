#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {       //定义树命名为TreeNode
    int data;                       
    struct TreeNode *left;          
    struct TreeNode *right;         
} TreeNode;
typedef struct Stack {          //定义树节点命名为Stack
    TreeNode **arr;             //存放树节点指针的数组
    int top;                    //栈顶索引，-1表示空栈
    int capacity;               //栈的最大容量
} Stack;
Stack *createStack(int capacity) {        //创建并初始化一个指定容量的栈
    Stack *stack = malloc(sizeof(Stack)); //为数组分配内存，大小为容量乘以指针大小
    stack->arr = malloc(sizeof(TreeNode *) * capacity);
    stack->top = -1;                      //初始化栈顶指针
    stack->capacity = capacity;
    return stack;
}
int isEmpty(Stack *stack) {               //判断栈是否为空
    return stack->top == -1;
}
void push(Stack *stack, TreeNode *node) { //入栈操作
    if (stack->top == stack->capacity - 1) {
        return;                           //栈已满，直接返回
    }
    stack->arr[++stack->top] = node;      //先移动栈顶指针，再赋值
}
TreeNode *pop(Stack *stack) {             //出栈操作
    if (isEmpty(stack)) {
        return NULL;                      //如果栈为空，返回NULL
    }
    return stack->arr[stack->top--];      //返回当前栈顶元素，并将栈顶指针减1
}

void preorderTraversal(TreeNode *root)  // 补全这个函数
{
    if (root == NULL){
        return;
    }
    Stack *stack = createStack(100);   //创建一个足够大的栈

    push(stack,root);                   //将根节点压入栈

    while (!isEmpty(stack)){            //循环处理，直到栈空
        TreeNode *current = pop(stack);
        printf("%d ",current->data);

        if (current->right != NULL){     //因为先进后出，前序遍历先打印左孩子，所以先压入右孩子
            push(stack,current->right);
        }
        if(current->left !=NULL){
            push(stack,current->left);
        } 
    }

    free(stack->arr);                    //释放内存
    free(stack);
}
TreeNode* create_node(int value)
{
    TreeNode *p = (TreeNode*)malloc(sizeof(TreeNode));

    if (p == NULL)
    {
        return NULL;
    }

    p->data = value;
    p->left = NULL;
    p->right = NULL;

    return p;
}
int main()
{
    TreeNode *root = create_node(7);
    TreeNode *n1 = create_node(4);
    TreeNode *n2 = create_node(6);
    TreeNode *n3 = create_node(2);
    TreeNode *n4 = create_node(1);
    TreeNode *n5 = create_node(3);
    TreeNode *n6 = create_node(5);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    preorderTraversal(root);

    return 0;
}