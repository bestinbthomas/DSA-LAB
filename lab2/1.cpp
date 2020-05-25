#include <bits/stdc++.h>
using namespace std;

stack<int> stk[3];
int itr=0;
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << "  " << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
int getTo(int from, int to){
    for(int i = 0; i<3; i++){
        if(i!=from && i!=to) return i;
    }
    //never reaching
    return -1;
}
void move(int from, int to, int num){
    int mFrom = from;
    for(int i=num-1; i>0; i--){
        int mTo = getTo(mFrom,to);
        move(mFrom,mTo,i);
        int elem = stk[mFrom].top();
        stk[mFrom].pop();
        stk[to].push(elem);
        mFrom = mTo;
        cout<<"stk 1 : ";
        showstack(stk[0]);
        cout<<"stk 2 : ";
        showstack(stk[1]);
        cout<<"stk 3 : ";
        showstack(stk[2]);
        cout<<"\n ------------------------- \n";
    }
    int elem = stk[mFrom].top();
    stk[mFrom].pop();
    stk[to].push(elem);
    cout<<"stk 1 : ";
    showstack(stk[0]);
    cout<<"stk 2 : ";
    showstack(stk[1]);
    cout<<"stk 3 : ";
    showstack(stk[2]);
    cout<<"\n ------------------------- \n";
}
int main(){
    int n;
    cin>>n;
    for(int i = n; i>0; i--){
        stk[0].push(i);
    }
    cout<<"stk 1 : ";
    showstack(stk[0]);
    cout<<"stk 2 : ";
    showstack(stk[1]);
    cout<<"stk 3 : ";
    showstack(stk[2]);
    cout<<"\n ------------------------- \n";
    move(0,2,n);
}
