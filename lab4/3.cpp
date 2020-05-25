#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

void merge(int a[], int l, int m, int r){
    int i = 0, j = 0, k = l;
    int n1 = (m - l) + 1, n2 = r - m;
    int left[n1], right[n2];

    nl;cout<<"--- left array ---";nl;
    for (int i1 = 0; i1 < n1; i1++)
    {
        left[i1] = a[l + i1];
        cout<<left[i1]<<" ";
    }
    nl;cout<<"--- right array ---";nl;
    for (int i2 = 0; i2 < n2; i2++)
    {
        right[i2] = a[m + 1 + i2];
        cout<<right[i2]<<" ";
    }
    nl;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            a[k] = left[i];
            i++;
        }

        else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    
    while(i < n1){
        a[k] = left[i];
        i++;
        k++;
    }
    while(j < n2){
        a[k] = right[j];
        j++;
        k++;
    }
    nl;cout<<"--- merged array ---";nl;
    for (k = l; k <= r; k++)
    {
        cout<<a[k]<<" ";
    }
    nl;

}

void mergeSort(int a[], int l, int r){
    if(l < r){
        int m = l + (r-l)/2;

        mergeSort(a,l,m);
        mergeSort(a,m+1,r);

        merge(a, l, m, r);
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
        nl;cout<<"----- initial array ------";nl; 
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }

    mergeSort(a, 0, n-1);

    nl;cout<<"----- sorted array ------";nl; 
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    nl; 
    

    return 0;
}
