//
// Created by YongbinMiao on 2020/6/28.
//

#include "ArrayTests.h"
#define MaxSize 50

typedef int ElemType ;
typedef struct
{
    ElemType data[MaxSize];
    int length;
} SqList;

//! 1、设计一个算法，从顺序表中删除重复的元素，并使剩余元素的顺序保持不变
void delsame(SqList &L){
    int i, j = 0, k;
    for (i = 1; i < L.length; ++i) {
        k=0;
        while (k < j && L.data[k] != L.data[i]) {
            k++;
        }
        if (k > j) {
            j++;
            L.data[j] = L.data[i];
        }
    }
    L.length = j + 1;
}

void delsame1(SqList &L){
    int j=0,k;
    for (int i = 0; i < L.length; i++) {
        for (k = i+1; k < L.length; k++) {
            if (L.data[i] == L.data[k]) {
                break;
            }
        }
        if (k == L.length) {
            L.data[j] = L.data[i];
            j++;
        }
    }
    L.length = j;
}

//! 2、设计一个算法，从有序顺序表中删除重复的元素，并使剩余元素的顺序保持不变
void delsame2(SqList &L){
    int j=0;
    for (int i = 0; i < L.length - 1; ++i) {
        if (L.data[i] != L.data[i + 1]) {
            L.data[j] = L.data[i];
            j++;
        }
    }
    L.length = j;
}

void delsame3(SqList &L) {
    int i, k = 1;
    ElemType e;
    e = L.data[0];
    for (i = 0; i < L.length; i++) {
        if (L.data[i] != e) {
            L.data[k] = L.data[i];
            k++;
            e = L.data[i];
        }
    }
    L.length = k;
}


//! 3、用顺序表表示集合，设计一个算法实现集合的求交集运算
void Intersection(SqList A, SqList B, SqList &C){
    int k=0;
    for (int i = 0; i < A.length; i++) {
        for (int j = 0; j < B.length; j++) {
            if (A.data[i] == B.data[j]) {
                C.data[k] = A.data[i];
                k++;
            }
        }
    }
    C.length = k;
}

void Intersection1(SqList A, SqList B, SqList &C){
    int i, j, k = 0;
    for (i = 0; i < A.length; i++) {
        j=0;
        while (j < B.length && B.data[j] != A.data[i]) {
            j++;
        }
        if (j < B.length) {
            C.data[k++] = A.data[i];
        }
    }
    C.length = k;
}


//! 4、假设表示集合的顺序表是一个有序顺序表，设计一个高效算法实现集合的求交集运算
void Intersection2(SqList A, SqList B, SqList &C) {
    int i = 0, j = 0, k = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] == B.data[j]) {
            C.data[k++] = A.data[i++];
            j++;
        } else if (A.data[i] < B.data[j]) {
            i++;
        } else {
            j++;
        }
    }
    C.length = k;
}








