#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int data;                       // 节点存储的数据
    struct TreeNode *left;          // 左子树指针
    struct TreeNode *right;         // 右子树指针
} TreeNode;
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
void freeTree(TreeNode *root)
{
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
int main()
{
    TreeNode *root = create_node(1);
    TreeNode *n1 = create_node(2);
    TreeNode *n2 = create_node(3);
    TreeNode *n3 = create_node(4);
    TreeNode *n4 = create_node(5);
    TreeNode *n5 = create_node(6);
    TreeNode *n6 = create_node(7);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    printf("前序遍历：");
    qianxu(root);
    printf("\n");

    printf("中序遍历：");
    zhongxu(root);
    printf("\n");

    printf("后序遍历：");
    houxu(root);

    freeTree(root);
    return 0;
}
void qianxu(TreeNode *root)
{
    if (root == NULL) return;
    printf("%d",root->data);
    qianxu(root->left);
    qianxu(root->right);
}
void zhongxu(TreeNode *root)
{
    if(root == NULL) return;
    zhongxu(root->left);
    printf("%d",root->data);
    zhongxu(root->right);
}
void houxu(TreeNode *root)
{
    if(root == NULL) return;
    houxu(root->left);
    houxu(root->right);
    printf("%d",root->data);
}
int depth(TreeNode *root,int current_depth,int max_depth)
{
    if (root == NULL){
        return max_depth;
    }

    if (current_depth > max_depth){
        max_depth = current_depth;
    }

    int left_max = depth(root->left,current_depth+1,max_depth);

    int right_max = depth(root->right,current_depth,left_max);

    return right_max;
}