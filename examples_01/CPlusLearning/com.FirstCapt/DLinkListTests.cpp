//
// Created by YongbinMiao on 2020/6/30.
//

#include "DLinkListTests.h"
#include <iostream>
#include <math.h>

typedef int ElemType ;
typedef struct DNode{
    ElemType data;
    struct DNode *prior;
    struct DNode *next;
} DLinkNode;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//! 1、建立双链表
//! (1)头插法
void CreateDListF(DLinkNode *&L, ElemType a[], int n) {
    DLinkNode *s;
    L = (DLinkNode *) malloc(sizeof(DLinkNode));  //创建头节点
    L->prior = L->next = NULL;
    for (int i = 0; i < n; ++i) {
        s = (DLinkNode *) malloc(sizeof(DLinkNode));
        s->data = a[i];
        s->next = L->next;
        
    }
}





//! (2)尾插法



class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* p = dummyHead;
        ListNode* q = dummyHead;
        for( int i = 0 ; i < n + 1 ; i ++ ){
            q = q->next;
        }
        while(q){
            p = p->next;
            q = q->next;
        }
        ListNode* delNode = p->next;
        p->next = delNode->next;
        delete delNode;
        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;

    }
};



