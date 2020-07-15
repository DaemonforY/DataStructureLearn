//
// Created by YongbinMiao on 2020/7/5.
//

#include "ArrayStackDemo.h"
#include <iostream>
#include <math.h>
#define MaxSize 50

typedef int ElemType ;
typedef struct {
    ElemType data[MaxSize];     // 存放栈中的数据元素
    int top;                    // 栈顶指针，即存放栈顶元素在data数组中的下标
} SqStack;                      // 顺序栈类型

void InitStack(SqStack *& s) {
    s = (SqStack *) malloc(sizeof(SqStack));
    s->top = -1;
}

void DestroyStack(SqStack *&s) {
    free(s);
}

bool StackEmpty(SqStack *s) {
    return s->top == -1;
}

bool Push(SqStack *&s, ElemType e) {
    if (s->top == MaxSize) {
        return false;
    }
    s->top++;
    s->data[s->top] = e;
    return true;
}

bool Pop(SqStack *&s, ElemType &e) {
    if (StackEmpty(s)) {
        return false;
    }
    e = s->data[s->top];
    s->top--;
    return true;
}

bool GetTop(SqStack *s, ElemType &e) {
    if (StackEmpty(s)) {
        return false;
    }
    e = s->data[s->top];
    return true;
}

/**
 * 设计一个算法利用顺序栈判断一个字符串是否为对称串。所谓对称串指
 * 从左向右读和从右向左读的序列相同。
 *
 * 题解：n个元素连续进栈，产生的连续出栈序列和输入序列正好相反，本算法就是利用这个特点设计的。
 * 对于字符串str，从头到尾将其所有元素连续进栈，如果所有元素连续出栈产生的序列和str
 * 从头到尾的字符依次相同，表示str是一个对称串，返回真；否则表示str不是对称串，返回假。
 * @param str
 * @return
 */

bool symmetry(ElemType str[]) {
    int i;
    ElemType e;
    SqStack *st;
    InitStack(st);
    for (i = 0; i < str[i] != '\0'; i++) {
        Push(st, str[i]);
    }
    for (i = 0; i < str[i] != '\0'; i++) {
        Pop(st, e);
        if (str[i] != e) {
            DestroyStack(st);
            return false;
        }
    }
    DestroyStack(st);
    return true;
}
