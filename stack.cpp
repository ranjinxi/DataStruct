/*************************************************************************
	> File Name: stack.cpp
	> Author: ranjinxi 
	> Mail: r1367718372@163.com 
	> Created Time: 2019年10月05日 星期六 18时06分45秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack {
    int *data;
    int top, size;
}Stack;

Stack *init(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (int *)malloc(sizeof(int) * n);
    s->size = n;
    s->top = -1;
    return s;
}

void clear(Stack *s) {
    if (s == NULL) return ;
    free(s->data);
    free(s);
    return ;
}

int empty(Stack *s) {
    return s->top == -1;
}


int expand(Stack *s) {
    int extr_size = s->size;
    int *p;
    while (extr_size) {
        p = (int *)realloc(s->data, sizeof(int) * (s->size + extr_size));
        if (p) break;
        extr_size /= 2;
    }
    if (p == NULL) return 0;
    s->size += extr_size;
    s->data = p;
    return 1;
}

int top(Stack *s) {
    if (empty(s)) return 0;
    return s->data[s->top];
}


int push(Stack *s, int val) {
    if (s == NULL) return 0;
    if (s->top + 1 == s->size) {
        if (!expand(s)) return 0;
        printf("expand Stack success! = (%d)\n", s->size);
    } 
    s->top += 1;
    s->data[s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (s == NULL) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void output(Stack *s) {
    printf("Stack = [");
    for (int i = s->top; i >= 0; i--) {
        i != s->top && printf(", ");
        printf("%d", s->data[i]);
    }
    printf("]\n");
    return ;
}


int main() {
    srand(time(0));
    #define max_op 30
    Stack *s = init(5);
    int op, val;
    for (int i = 0; i < max_op; i++) {
        op = rand() % 4;
        val = rand() % 100;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to Stack = %d\n", val, push(s, val));
                output(s);
                printf("\n");
            } break;
            case 3: {
                printf("pop %d from the Stack = %d\n", top(s), pop(s));
                output(s);
                printf("\n");
            }
        }
    }
    clear(s);
    return 0;
}
