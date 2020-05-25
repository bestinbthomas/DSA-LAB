#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right){
    int i = left;
    int pi = (rand() % (right + 1 - left)) + left;

    swap(&a[pi], &a[right]);

    for (int j = left; j < right; j++)
    {
        if(a[j] <= a[right]){
            swap(a[j], a[i]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i;
}

int findithSmallest(int a[], int p, int r, int i){
    if(p == r) return a[p];

    int q = partition(a, p, r);
    int k = q - p + 1;
    if(i == k) return a[q];
    else if(i < k) return findithSmallest(a, p, q - 1, i);
    else return findithSmallest(a, q+1, r, i);
}


int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    int i;
    cin>>i;
    cout<<"----- "<<i<<"th smallest number is "<<findithSmallest(a,0,n-1,i)<<" -----\n";

    return 0;
}
