#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

void BFS(int *a, int n, int source){
    queue<int> q;
    set<int> visited;
    q.push(0);
    visited.insert(0);
    cout<<"\n------ BFS "<<source<<" ------\n";
    nl;
    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        cout<<elem<<"\t";
        for (int i = 0; i < n; i++)
        {
            if(*((a+elem*n)+ i) != 0 && visited.find(i) == visited.end()) {
                q.push(i);
                visited.insert(i);
            }
        }
    }
    nl;
    
}

void DFS(int *a, int n, int source){
    stack<int> s;
    set<int> visited;
    s.push(source);
    visited.insert(source);
    cout<<"\n------ DFS from "<<source<<" ------\n";
    nl;

    while (!s.empty())
    {
        int elem = s.top();
        s.pop();
        cout<<elem<<"\t";
        for (int i = 0; i < n; i++) {
            if(*((a+elem*n)+ i) != 0 && visited.find(i) == visited.end()){
                s.push(i);
                visited.insert(i);
            }
        }
    }
    nl;
    
}

bool checkPathExist(int *a,int n, int v1, int v2){
    queue<int> q;
    set<int> visited;
    q.push(v1);
    visited.insert(v1);
    cout<<"\n------ Check if path exist between "<<v1<<" and "<<v2<<" ------\n";
    nl;
    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {
            if(*((a+elem*n)+ i) != 0 && visited.find(i) == visited.end()) {
                if(i == v2) return true;
                q.push(i);
                visited.insert(i);
            }
        }
        
    }
    nl;

    return false;
}

void shortestDistance(int *a, int n, int *shortestD){
    queue<int> q;
    set<int> visited;
    int parent[n];
    q.push(0);
    visited.insert(0);
    cout<<"\n------ find shortest distnce fom source ------\n";
    nl;
    while (!q.empty())
    {
        int elem = q.front();
        q.pop();
        for (int i = 0; i < n; i++)
        {

            if(*((a+elem*n)+ i) != 0 && visited.find(i) == visited.end()) {
                parent[i] = elem;
                q.push(i);
                visited.insert(i);
            }
        }
        
    }
    nl;

    for (int i = 1; i < n; i++)
    {
        int j = i;
        shortestD[i] = 0;
        while (j != 0)
        {
            shortestD[i]++;
            j = parent[j];
        }
        
    }
    
}

int main() {
    int n;
    cin>>n;
    int a[n][n];
    bool isComplete = true, isDirected = false;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
            if(i != j && a[i][j] == 0) isComplete = false;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] != a[j][i]) {
                isDirected = true;
                break;
            }
        }
        if(isDirected) break;
    }
    if(isComplete) cout<<"the graph is complete";
    else cout<<"the graph is not complete";
    nl;

    for (int i = 0; i < n; i++)
    {
        int indegree = 0, outdegree = 0;
        for (int j = 0; j < n; j++)
        {
            if(a[i][j] != 0) indegree++;
        }

        if(!isDirected){
            cout<<"degree of node "<<i<<" is "<<indegree<<endl;
            continue;
        }

        for (int j = 0; j < n; j++)
        {
            if(a[j][i] != 0) outdegree++;
        }

        cout<<"indegree of node "<<i<<" is "<<indegree<<endl;
        cout<<"outdegree of node "<<i<<" is "<<outdegree<<endl;
    }

    BFS((int *) a, n, 0);
    DFS((int *) a, n, 0);

    int v1,v2;
    cin>>v1>>v2;
    checkPathExist((int *) a, n, v1, v2)? cout<<"true": cout<<"false";nl;

    int *sd = new int[n];
    shortestDistance((int *)a, n, sd);

    for (int i = 0; i < n; i++)
    {
        cout<<"shortest distance of "<<i<<" from source is "<<sd[i];nl;
    }
    
    delete sd;
    nl;

    return 0;
}
