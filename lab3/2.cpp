#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

struct node {
    int value;
    node *next;
};

void insert(node* root, int val){
    node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
    }

    node *newVal = new node;
    newVal->value = val;
    newVal->next = NULL;
    temp->next = newVal;
}

int count(node* root){
    int count = 0;
    node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
        count++;
    }
    return count;
}

void print(node *root){
    node* temp = root;

    cout<<"----- adjacency list of node "<<temp->value<<" -----";nl;
    while(temp->next != NULL){
        temp = temp->next;
        cout<<temp->value<<" ";
    }
    nl;
}

bool edgeExist(node* root, int val){
    node* temp = root;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp->value == val) return true;
    }
    return false;
}

void BFS(node *a[], int n, node* source){
    queue<int> q;
    set<int> visited;
    q.push(source->value);
    visited.insert(source->value);
    cout<<"\n------ BFS "<<source->value<<" ------\n";
    nl;
    while (!q.empty())
    {
        node* elem = a[q.front()];
        q.pop();
        cout<<elem->value<<"\t";
        while (elem->next != NULL)
        {
            elem = elem->next;
            if(visited.find(elem->value) == visited.end()) {
                q.push(elem->value);
                visited.insert(elem->value);
            }
        }
    }
    nl;
    
}

void DFS(node *a[], int n, node* source){
    stack<int> s;
    set<int> visited;
    s.push(source->value);
    visited.insert(source->value);
    cout<<"\n------ DFS from "<<source->value<<" ------\n";
    nl;

    while (!s.empty())
    {
        node* elem = a[s.top()];
        s.pop();
        cout<<elem->value<<"\t";
        while (elem->next != NULL)
        {
            elem = elem->next;
            if(visited.find(elem->value) == visited.end()){
                s.push(elem->value);
                visited.insert(elem->value);
            }
        }
    }
    nl;
    
}

bool checkPathExist(node *a[],int n, node* v1, node* v2){
    queue<int> q;
    set<int> visited;
    q.push(v1->value);
    visited.insert(v1->value);
    cout<<"\n------ Check if path exist between "<<v1->value<<" and "<<v2->value<<" ------\n";
    nl;
    while (!q.empty())
    {
        node* elem = a[q.front()];
        q.pop();
        while(elem->next != NULL)
        {
            elem = elem->next;
            if(visited.find(elem->value) == visited.end()) {
                if(elem->value == v2->value) return true;
                q.push(elem->value);
                visited.insert(elem->value);
            }
        }
        
    }
    nl;

    return false;
}

void shortestDistance(node *a[], int n, int *shortestD){
    queue<int> q;
    set<int> visited;
    int parent[n];
    q.push(a[0]->value);
    visited.insert(a[0]->value);
    cout<<"\n------ find shortest distnce fom source ------\n";
    nl;
    while (!q.empty())
    {
        node* elem = a[q.front()];
        q.pop();
        node* temp = elem;
        while(temp->next != NULL)
        {
            temp = temp->next;
            if(visited.find(temp->value) == visited.end()) {
                parent[temp->value] = elem->value;
                q.push(temp->value);
                visited.insert(temp->value);
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
    node* a[n];
    int indegree[n];
    bool isComplete = true, isDirected = false;
    for(int i = 0; i < n; i++){
        a[i] = new node;
        a[i]->value = i;
        a[i]->next = NULL;
        indegree[i] = 0;
        for(int j = 0; j < n; j++){
            int in;
            cin>>in;
            if(in == 1) insert(a[i], j);
        }
    }
    for (int i = 0; i < n; i++)
    {
        print(a[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(count(a[i]) < n - 1) isComplete = false;
        bool isbreak = false;

        node* temp = a[i];
        while(temp->next != NULL){
            temp = temp->next;
            if(!edgeExist(a[temp->value],a[i]->value)) {
                isDirected = true;
                isbreak = true;
                break;
            }
        }

        if(isbreak) break;
        
    }
    isComplete? cout<<"the graph is complete": cout<<"the graph is not complete";
    nl;
    isDirected? cout<<"the graph is directed": cout<<"the graph is not directed";
    nl;

    for (int i = 0; i < n; i++)
    {
        int outdegree;
        outdegree = count(a[i]);

        if(!isDirected){
            cout<<"degree of node "<<i<<" is "<<outdegree<<endl;
            continue;
        }

        node* temp = a[i];
        while(temp->next != NULL){
            temp = temp->next;
            indegree[temp->value]++;
        }

        cout<<"outdegree of node "<<i<<" is "<<outdegree<<endl;

    }

    if(isDirected){
        for (int i = 0; i < n; i++)
        {
            cout<<"indegree of node "<<i<<" is "<<indegree[i]<<endl;
        }
    }

    BFS(a, n, a[0]);
    DFS(a, n, a[0]);

    int v1,v2;
    cin>>v1>>v2;
    checkPathExist(a, n, a[v1], a[v2])? cout<<"true": cout<<"false";nl;

    int *sd = new int[n];
    shortestDistance(a, n, sd);

    for (int i = 0; i < n; i++)
    {
        cout<<"shortest distance of "<<i<<" from source is "<<sd[i];nl;
    }
    
    delete sd;
    nl;

    return 0;
}
