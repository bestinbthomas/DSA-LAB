#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

bool findSubset(int a[], int n, int i, int currSum, int reqSum, int sol[], int solN){
    if(currSum == reqSum){
        cout<<"\n----- subset found -----\n";
        for (int j = 0; j < solN; j++)
        {
            cout<<sol[j]<<" ";
        }
        nl;
        return true;
    }
    else if(i == n || currSum > reqSum){
        return false;
    }
    else {
        if(findSubset(a, n, i + 1, currSum, reqSum, sol, solN)) return true;
        sol[solN] = a[i];
        if(findSubset(a, n, i + 1, currSum + a[i], reqSum, sol, solN + 1)) return true;
    }

    return false;
}


int main() {
    int n;
    cin>>n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }nl;
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }nl;
    int reqSum;
    cin>>reqSum;
    int sol[n];
    if(!findSubset(a, n, 0, 0, reqSum, sol, 0)) cout<<"\n----- subset not posssible -----\n";    

    return 0;
}
