/*************************************************************************
	> File Name: 7.binary_tree.cpp
	> Author: ranjinxi 
	> Mail: r1367718372@163.com 
	> Created Time: 2019年10月19日 星期六 19时07分22秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int val;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->val = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Node *insertNode(Node *root, int val, int *flag) {
    if (root == NULL) {
        *flag = 1;
        return getNewNode(val);
    }
    if (root->val == val) return root;
    if (root->val < val) root->lchild = insertNode(root->lchild, val, flag);
    if (root->val > val) root->rchild = insertNode(root->rchild, val, flag);
    return root;

}

void insert(Tree *tree, int val) {
    int flag = 0;
    tree->root = insertNode(tree->root, val, &flag);
    tree->n += flag;
    return ;
}

void clearNode(Node *node) {
    if (node == NULL) return ;
    clearNode(node->lchild);
    clearNode(node->rchild);
    free(node);
    return ;
} 

void clearTree(Tree *tree) {
    if (tree = NULL) return ;
    clearNode(tree->root);
    free(tree);
    return ;
}

void outputNode(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->val);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    outputNode(root->lchild);
    printf(",");
    outputNode(root->rchild);
    printf(")");
    return ;
}

void output(Tree *tree) {
    if (tree == NULL) return ;
    printf("tree(%d) = ", tree->n);
    outputNode(tree->root);
    printf("\n");
    return ;
}

void in_order(Tree, *tree) {
    printf("in_order(%d) = ", tree->n);
    in_orderNode(tree->root);
    printf("\n");
    return ;
}

void in_orderNode(Node *node) {
    if (node == NULL) return ;
    in_orderNode(node->lchild);
    printf("%d ",node->val);
    in_orderNode(node->rchild);
    return ;
}

int main() {
    srand(time(0));
    Tree *tree = getNewTree();
    #define max_op 20
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        insert(tree, val);
    }
    output(tree);
    in_order(tree);
    clearTree(tree);
    return 0;
}
