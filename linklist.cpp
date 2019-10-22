/*************************************************************************
	> File Name: linklist.cpp
	> Author: ranjinxi 
	> Mail: r1367718372@163.com 
	> Created Time: 2019年10月04日 星期五 19时56分12秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

typedef struct ListNode {
    int data;
    struct ListNode *next;
}ListNode;

typedef struct List {
    ListNode head;
    int length;
}List;

ListNode *init_node(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

void clear_node(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear_list(List *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}

int insert(List *l, int ind, int val) {
    if (l== NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode *p = &(l->head), *node = init_node(val);
    while (ind--) {p = p->next;}
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    l->length -= 1;
    return 1;
}

void reverse(List *l) {
    if (l == NULL) return ;
    ListNode *p, *q;
    p = l->head.next;
    l->head.next = NULL; //注意
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}

void output(List *l) {
    printf("List(%d) = [", l->length + 1);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d -> ", p->data);
    }
    printf("NULL]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    int op, ind, val;
    List *l = init_list();
    for (int i = 0; i < max_op; i++) {
        op = rand() % 5;
        ind = rand() % (l->length + 3) -1;
        val = rand() % 100;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d to List = %d\n",
                      val, ind, insert(l, ind, val));
                output(l);
                printf("\n");
            } break;
            case 3: {
                printf("erase %d at %d from List = %d\n",
                      ind, erase(l, ind));
                output(l);
                printf("\n");
            } break;
            case 4: {
                printf("reverse the List\n");
                reverse(l);
                output(l);
                printf("\n");
            }
        }
    }
    clear_list(l);
    return 0;
}
