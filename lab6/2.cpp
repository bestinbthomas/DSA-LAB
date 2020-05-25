#include<bits/stdc++.h>
using namespace std;
#define nl cout<<endl;


int integer_knapsack(int n, int M, int w[], int p[])

{
    int i,j;    
    int tempValue;    
    int knapsack[M+1];
    knapsack[0]=0;

    for(i=1;i<=M;i++){
        knapsack[i]=knapsack[i-1];

        for(j=0;j<n;j++){
            if(i>=w[j])
            {
                tempValue=p[j]+knapsack[i-w[j]];
                if(tempValue>knapsack[i])
                {
                    knapsack[i]=tempValue;
                }
            }
        }
    }
    return knapsack[M];
}

    

int main()
{

    int i;
    int n; 
    int M;   
    cin>>n;
    int w[n];
    int p[n];

    for(i=0;i<n;i++)
    {
        cin>>w[i]>>p[i];
    }
    cin>>M;
    int result=integer_knapsack(n,M,w,p);
    cout<<result;nl;
    return 0;
}
