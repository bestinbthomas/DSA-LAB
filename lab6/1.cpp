#include<bits/stdc++.h>
using namespace std;
#define nl cout<<endl;

int main() {
    int first = 0, second = 1;   // let assume that first -> 0 and second is -> 1
    int n;
    cin >> n;

    int v[n];
    v[0] = 0;
    v[1] = 1;

    for(int i = 2; i < n; i++) {
        v[i] = v[i-2] + v[i-1];
    }

    cout << "----- generating " << n <<" fibonacci numbers -----\n";
    for(int i = 0; i < n; i++ ){
        cout << v[i] << " ";
    }nl;
    return 0;
}
