//
// Created by YongbinMiao on 2020/6/28.
//

#include "LinkTests.h"
#include <iostream>
#include <math.h>

typedef int ElemType ;
typedef struct LNode1
{
    ElemType data;
    struct LNode1 *next;
} LinkList;

//! 1、建立单链表的算法
//! (1)采用头插法建立单链表
//! 该方法从一个空表开始，读取数组a中的元素，生成新节点，将读取的数据存放到新节点的数据域中，
//! 然后将新节点插入到当前链表的表头上，直到结束为止。采用头插法建表的算法ruxia
//! 本算法的时间复杂度为n
void CreateListF(LinkList *&L, ElemType a[], int n){
    LinkList *s;
    L = (LinkList *) malloc(sizeof(LinkList));
    L->next = NULL;
    for (int j = 0; j < n; j++) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->data = a[j];
        s->next = L->next;
        L->next = s;
    }
}

//! (2)采用尾插法建立单链表
//! 利用头插法建立链表虽然简单，但生成的链表中节点的次序和原数组元素的顺序相反。
//! 若希望两者次序一致，可采用尾插法建立。
//! 该方法是将新节点插到当前链表的表尾上，为此，必须增加一个尾结点指针r，
//! 使其始终指向当前链表的尾结点。本算法的时间复杂度为n。
void CreateListR(LinkList *&L, ElemType a[], int n){
    LinkList *s, *r;
    L = (LinkList *) malloc(sizeof(LinkList));
    r = L;
    for (int i = 0; i < n; ++i) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}


//! 2、单链表的基本运算算法
//! (1) 按元素值查找算法
//! 在单链表L中从头开始查找第一个值域与e相等的节点，若存在这样的节点，则返回其逻辑序号，否则返回0。
int LocateElem(LinkList *L, ElemType e){
    int i = 1;
    LinkList *p = L->next;
    while (p != NULL && e != p->data) {
        i++;
        p = p->next;
    }
    if (p == NULL) {
        return 0;
    } else {
        return i;
    }
}

//! 3、有序单链表的归并算法
//! 当一个单链表的元素（这里假定从小到大）有序时，称为有序单链表。
void Merge(LinkList *L1, LinkList *L2, LinkList *&L3){
    LinkList *p = L1->next, *q = L2->next, *s, *r;
    L3 = (LinkList *) malloc(sizeof(LinkList));
    r = L3;
    while (p != NULL && q != NULL) {
        s = (LinkList *) malloc(sizeof(LinkList));
        if (p->data < q->data) {
            s->data = p->data;
            p = p->next;
        } else {
            s->data = q->data;
            q = q->next;
        }
        r->next = s;
        r = s;
    }
    if (q != NULL) {
        p = q;
    }
    while (p != NULL) {
        s = (LinkList *) malloc(sizeof(LinkList));
        s->data = p->data;
        p = p->next;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

//! 本算法没有利用L1、L2链表的节点，而是通过复制新建L3的所有节点，这样没有破坏
//! 原有的L1、L2链表的节点。其时间复杂度和空间复杂度均为M+N
//! 本算法实质上是采用尾插法建立单链表L3
//! 如果上述归并算法要求空间复杂度为1，这样就必须破坏原有的L1和L2单链表由这两个单链表的节点重组成产生L3，算法如下。

void Merge1(LinkList *L1, LinkList *L2, LinkList *&L3){
    LinkList *p = L1->next, *q = L2->next, *s;

}

//! 单链表算法设计归纳起来有以下两种类型
//! 1、基于建表的算法：这类算法直接或间接地转换成建表过程，如果新建表的次序与原来的次序相同，则采用尾插法；
//! 如果新建表的次序与原来的次序相反，则采用头插法。
//! 2、基于查找、插入或删除的算法：这类算法以单链表的基本运算为基础，包含有节点的查找、插入或删除操作。











