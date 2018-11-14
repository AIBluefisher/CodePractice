#include <iostream>
using namespace std;

void QuickSort(int R[], int s, int t)
{
    if(s >= t) return;
    int i = s, j = t, tmp = R[s];
    while(i != j) {
        while(i < j && R[j] >= tmp) j--;
        R[i] = R[j];
        while(i < j && R[i] <= tmp) i++;
        R[j] = R[i];
    }
    R[i] = tmp;
    QuickSort(R, s, i - 1);
    QuickSort(R, i + 1, t);
}