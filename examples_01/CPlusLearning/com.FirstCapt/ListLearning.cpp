/**
* Created by YongbinMiao on 2020/6/27.
*/

#include "ListLearning.h"
#include <iostream>
#include <math.h>

typedef int ElemType ;
typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LinkNode;

//! 建立单链表：1、头插法
void CreatListF(LinkNode *&L , ElemType a[], int n){
    LinkNode *s;
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = NULL;
    for (int i = 0; i < n; i++) {
        s = (LinkNode *) malloc(sizeof(LinkNode));
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}
//! 建立单链表：2、尾插法
void CreateListR(LinkNode *&L, ElemType a[], int n) {
    LinkNode *s, *r;
    L = (LinkNode *) malloc(sizeof(ElemType));
    r = L;
    for (int i = 0; i < n; ++i) {
        s = (LinkNode *) malloc(sizeof(ElemType));
        s->data = a[i];
        r->next = s;
        r = s;
    }
}

/**
 * 整体创建单链表的两个算法特别是尾插法创建表算法是很多其他复杂算法的基础，必须牢固掌握。
 * 例如：将两个单链表合并成一个单链表等都是利用尾插法创建表算法实现的
 */

//! 线性表基本运算在单链表中的实现
//! 1、初始化线性表InitList(&L)
void InitList(LinkNode *&L) {
    L = (LinkNode *) malloc(sizeof(LinkNode));
    L->next = NULL;
}

//! 2、销毁线性表 DestroyList(&L)
void DestroyList(LinkNode *&L){
    LinkNode *pre, *p = L->next;
    while (p->next != NULL) {
        free(pre);
        pre = p;
        p = pre->next;
    }
    free(pre);
}

//! 3、判断线性表是否为空 ListEmpty(L)
bool ListEmpty(LinkNode *L){
    return (L->next == NULL);
}

//! 4、求线性表的长度 ListLength(L)
int ListLength(LinkNode *L) {
    int l = 0;
    LinkNode *s = L;
    while (L->next != NULL) {
        l++;
        s = s->next;
    }
    return l;
}

//! 5、输出线性表 DispList(L)
void DispList(LinkNode *L){
    LinkNode *p = L->next;
    while (p->next != NULL) {
        std::cout << p->data << std::endl;
        p = p->next;
    }
}

//! 6、求线性表中某个数据元素的值 GetElem(L,i,&e)
bool GetElem(LinkNode *L, int i, ElemType &e){
    LinkNode *p = L;
    int s = 0;
    while (p != NULL && s < i) {
        s++;
        p = p->next;
    }
    if (s == i) {
        e = p->next->data; //!自己写的，和书上不一样，有待确认
        return true;
    } else {
        return false;
    }
}

//! 7、按元素值查找 LocateElem(L,e)
int LocateElem(LinkNode *L, ElemType e) {
    LinkNode *p = L->next;
    int i;
    while (p != NULL && p->data != e) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        return 0;
    } else {
        return i;
    }
}

//! 8、插入数据元素 ListInert(L,i,e)
bool ListInert(LinkNode *L, int i, ElemType e){
    int j=0;
    LinkNode *p = L, *s;
    if (i<=0) return false;
    while (j < i) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        s->data = e;
        s->next = p->next;
        p->next = s;
        return true;
    }
}

//! 9、删除数据元素 ListDelete(L,i,&e)
bool ListDelete(LinkNode *L, int i, ElemType &e){
    int j = 0;
    LinkNode *p = L, *s;
    while (j < i - 1 && p != NULL) {
        j++;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    } else {
        s = p->next;
        if (s == NULL) {
            return false;
        }
        e = s->data;
        p->next = s->next;
        free(s);
        return true;
    }
}


//! 习题1：
void split(LinkNode *&L, LinkNode *&L1, LinkNode *&L2){

}

//! 习题2：找到链表中值最大的节点，并删除它
void delMaxNode(LinkNode *&L){
    LinkNode *pre = L, *p = L->next, *maxp = L->next, *maxpPre = pre;
    while (p != NULL) {
        if (p->data > maxp->data) {
            maxp = p;
            maxpPre->next = maxp;
        }
        pre->next = p;  // pre=p;
        p = p->next;  //p=p->next;
    }
    maxpPre->next = maxp->next;
    free(maxp);
}

//! 习题3：对一个带头结点的单链表L设计算法使其有序递增
void sort(LinkNode *&L) {
    LinkNode *p, *pre, *q;
    p = L->next->next;
    L->next->next = NULL;
    while (p != NULL) {
        q = p->next;
        pre = L;
        while (pre->next != NULL && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = q;
    }
}


