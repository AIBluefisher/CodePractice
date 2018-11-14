#include <iostream>
using namespace std;

const int MAX_N  = 1 << 17;

// 布满线段数的全局数组
int n, dat[2 * MAX_N -1];

void init(int n_) {
    // 为了简单起见，把元素个数扩大到2的幂
     n = 1;
     while(n < n_) n *= 2;

    // 把所有的值都设为INT_MAX
    for(int  i = 0; i < 2 * n - 1; i++) dat[i] = INT_MAX;
}

// 把第k个值（0-indexed）更新为a
void update(int k, int a) {
    k += n - 1;
    dat[k] = a;
    // 向上更新
    while(k > 0) {
        k = (k - 1) / 2;
        dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
    }
}

// 求