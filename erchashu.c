#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TREE_SIZE 100
/*
 * 顺序存储二叉树结点
 * - data：结点数据
 * - used：当前位置是否有结点
 */
typedef struct {
    int data;
    bool used;
} SeqTreeNode;

/*
 * 顺序存储二叉树
 * - nodes：结点数组
 * - size：数组最大容量
 */
typedef struct {
    SeqTreeNode nodes[MAX_TREE_SIZE];
    int size;
} SeqBiTree;
void init_tree(SeqBiTree* tree)
{
    tree->size = MAX_TREE_SIZE;
    for (int i = 0;i<MAX_TREE_SIZE;i++)
    {
        tree->nodes[i].used = false;
    }
}

bool set_root(SeqBiTree* tree,int value)
{
    if (tree->nodes[1].used)
    {
        printf("根节点已存在！\n");
        return false;
    }

    tree->nodes[1].data = value;
    tree->nodes[1].used = true;

    return true;
}
bool set_left_child(SeqBiTree *tree,int parent_node,int value)
{
    if (!tree->nodes[parent_node].used)
    {
        printf("父节点不存在!\n");
        return false;
    }
    
    int left_child = 2 * parent_node;
    
    if (left_child>= MAX_TREE_SIZE)
    {
        printf("左孩子越界!\n");
        return false;
    }

    if (tree->nodes[left_child].used)
    {
        printf("左孩子已存在！\n");
        return false;
    }

    tree->nodes[left_child].data = value;
    tree->nodes[left_child].used = true;

    return true;
}
bool set_right_child(SeqBiTree *tree,int parent_node,int value)
{
    if (!tree->nodes[parent_node].used)
    {
        printf("父节点不存在!\n");
        return false;
    }
    
    int right_child = 2 * parent_node + 1;
    
    if (right_child>= MAX_TREE_SIZE)
    {
        printf("右孩子越界!\n");
        return false;
    }

    if (tree->nodes[right_child].used)
    {
        printf("右孩子已存在!\n");
        return false;
    }

    tree->nodes[right_child].data = value;
    tree->nodes[right_child].used = true;

    return true;
}
void level_order(SeqBiTree *tree)
{
    int level = 1;
    int start = 1;
    int end = 1;
    while (start <MAX_TREE_SIZE)
    {
        bool hasAny = false;
        
        for (int i = start; i <=end && i < MAX_TREE_SIZE; i++)
        {
            if (tree->nodes[i].used)
            {
                printf("%d",tree->nodes[i].data);
            }
            else
            {
                printf("-1");
            }
        }
        printf("\n");

        if (!hasAny) break;

        level++;
        start = end +1;
        end = (1 << level) - 1;
    }
}
int main()
{
    SeqBiTree tree;
    init_tree(&tree);

    set_root(&tree,1);
    set_left_child(&tree,1,2);
    set_right_child(&tree,1,3);
    set_left_child(&tree,2,4);
    set_right_child(&tree,2,5);
    set_left_child(&tree,3,6);
    set_right_child(&tree,3,7);

    printf("层序遍历结果\n");
    level_order(&tree);

    return 0;
}