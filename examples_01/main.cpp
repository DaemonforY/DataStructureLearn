#include <iostream>
#include <math.h>

void swap(int x, int y) {
    int tmp;
    tmp=x;
    x=y;
    y = tmp;
}
void swap2(int *x, int *y){
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}
void swap3(int &x, int &y) {
    int tmp;
    tmp=x;
    x=y;
    y = tmp;
}

int solution(int &a, int &b, int &c, double &x1, double &x2){
    int d = b * b - 4 * a * c;
    if (d > 0) {
        x1 = (-b + sqrt(d)) / 2 / a;
        x2 = (-b - sqrt(d)) / 2 / a;
        return 2;
    } else if (d == 0) {
        x1 = x2 = -b / 2 / a;
        return 1;
    } else {
        return 0;
    }
}

int fun(int n, int &s) {
    int i;
    if (n < 0) {
        return 0;
    }
    s = 0;
    for (i = 1; i < n; i++) {
        s += i;
    }
    return 1;
}

int main() {
    int a = 10, b = 0;
    if (fun(a, b)) {
        printf("%d\n", b);
    } else {
        printf("error");
    }
}
