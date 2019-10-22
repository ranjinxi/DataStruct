/*************************************************************************
	> File Name: 8.thread_tree.cpp
	> Author: ranjinxi 
	> Mail: r1367718372@163.com 
	> Created Time: 2019年10月19日 星期六 14时39分55秒
 ************************************************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define NORMAl 0
#define THREAd 1

typedef struct Node {
    int key;
    int ltag, rtag;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->lchild = p->rchild = NULL;
    p->ltag = p->rtag = NORMAl;
    return p;
}

Node *insert(Node *node, int val) {
    if (node == NULL) return getNewNode(val);
    if (node->key == val) return node;
    if (node->key > val) node->lchild = insert(node->lchild, val);
    else node->rchild = insert(node->rchild, val);
    return node;
}

void build_thread(Node *root) {
    if (root == NULL) return ;
    static Node *pre = NULL;
    build_thread(root->lchild);
    if (root->lchild == NULL) {
        root->lchild = pre;
        root->ltag = THREAd;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = root;
        pre->rtag = THREAd;
    }
    pre = root;
    build_thread(root->rchild);
    return ;

}

Node *most_left(Node *p) {
    while (p && p->ltag == NORMAl && p->lchild) p = p->lchild;
    return p;
}

void clear(Node *node) {
    if (node == NULL) return ;
    if (node->ltag == NORMAl) clear(node->lchild);
    if (node->rtag == NORMAl) clear(node->rchild);
    free(node);
    return ;
}

void in_order(Node *node) {
    if (node == NULL) return ;
    if (node->ltag == NORMAl) in_order(node->lchild);
    printf("%d ", node->key);
    if (node->rtag == NORMAl) in_order(node->rchild);
    return ;
}

void output(Node *node) {
    if (node == NULL) return ;
    Node *p = most_left(node);
    while (p) {
        printf("%d ", p->key);
        if (p->rtag == THREAd) {
            p = p->rchild;
        } else {
            p =most_left(p->rchild);
        }
    }
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Node *root = NULL;
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        root = insert(root, val);
    }
    build_thread(root);
    in_order(root), printf("\n");
    output(root), printf("\n");
    clear(root);
    return 0;
}
