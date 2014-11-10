// 同时查找最小值和最大值

#include <iostream>

using namespace std;

void findMinAndMax(int *a, int n) {
    if (n <= 1) {
        return;
    }
    // 初始化
    int min;
    int max;

    int start;
    if (n % 2 != 0) {
        // 奇数
        min = *a;
        max = *a;
        start = 1;
    }
    else {
        // 偶数
        int first = *a;
        int second = *(a + 1);
        if (first > second) {
            min = second;
            max = first;
        }
        else {
            min = first;
            max = second;
        }
        start = 2;
    }

    int index = start;
    int count = (n - start) / 2;
    for (int i = 1; i <= count; ++i) {
        int n1 = *(a + index);
        int n2 = *(a + index + 1);
        int tmin;
        int tmax;

        // 一次
        if (n1 > n2) {
            tmin = n2;
            tmax = n1;
        }
        else {
            tmin = n1;
            tmax = n2;
        }

        // 两次
        if (tmin < min) {
            min = tmin;
        }

        // 三次
        if (tmax > max) {
            max = tmax;
        }

        index = index + 2;
    }

    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
}

int main() {
    int a[] = {-1, 3, 14, 8, 6, 9, 10, 2, 11, 7};

    findMinAndMax(a, sizeof(a) / sizeof(*a));

    return 0;
}
