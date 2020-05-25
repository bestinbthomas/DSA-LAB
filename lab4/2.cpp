#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

int binarySearch(int a[], int n, int elem){
    int l = 0, r = n-1;

    while(r >= l){
        int mid = l + (r-l)/2;
        if(a[mid] == elem){
            return mid;
        }
        if(a[mid] < elem){
            l = mid+1;
        }
        else if(a[mid] > elem){
            r = mid-1;
        }
    }

    return -1; // not found
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    int elem;
    cin>>elem;
    cout<<binarySearch(a,n,elem);

    return 0;
}
