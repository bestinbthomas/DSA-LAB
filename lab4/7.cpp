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

void quicksort(int a[], int left, int right){
    if(left < right){
        int pi = partition(a,left,right);

        quicksort(a,left, pi - 1);
        quicksort(a,pi + 1, right);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }

    quicksort(a,0,n-1);
    cout<<"\n ----- sorted array ----- \n";
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }nl;

    return 0;
}
