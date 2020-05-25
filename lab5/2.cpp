#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

struct Edge {
    int s;
    int d;
    int w;
};

struct Graph {
    int V;
    int E;
    Edge *edge;
};

struct subset {
    int parent;
    int rank;
};

int findRoot(subset subsets[], int i){
    if(subsets[i].parent != i){
        subsets[i].parent = findRoot(subsets, subsets[i].parent);
    }

    return subsets[i].parent;
}

void addToSubsets(subset subsets[], int s, int d){
    int sroot = findRoot(subsets, s);
    int droot = findRoot(subsets, d);

    if(subsets[sroot].rank < subsets[droot].rank){
        subsets[sroot].parent = droot;
    }
    else if(subsets[sroot].rank > subsets[droot].rank){
        subsets[droot].parent = sroot;
    }
    else {
        subsets[droot].parent = sroot;
        subsets[sroot].rank++;
    }
}

Edge newEdge(int s, int d, int w){
    Edge e;
    e.s = s;
    e.d = d;
    e.w = w;
    return e;
}

void print(Graph *g){
    cout<<"s\td\tw\n\n";
    for (int i = 0; i < g->E; i++)
    {
        cout<<g->edge[i].s<<"\t"<<g->edge[i].d<<"\t"<<g->edge[i].w;nl;
    }nl;
}

void kruskalMST(Graph *graph){
    int V = graph->V;
    Edge res[V];
    int e = 0, i = 0;

    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), [](const void* a,const void* b){return (int)(((Edge*)a)-> w > ((Edge*)b)->w);});

    subset *subsets = new subset[V];

    for (int j = 0; j < V; j++)
    {
        subsets[j].parent = j;
        subsets[j].rank = 0;
    }

    while(e < V-1 && i < graph->E){
        Edge nextEdge = graph->edge[i++];

        int sroot = findRoot(subsets,nextEdge.s);
        int droot = findRoot(subsets,nextEdge.d);

        if(sroot != droot) { // no cycle
            res[e++] = nextEdge;
            addToSubsets(subsets, sroot, droot);
        }
    }

    Graph MST;
    MST.V = V;
    MST.E = e;
    MST.edge = res;

    cout<<"----- resulting graph is -----\n\n";
    print(&MST);

}


int main() {
    int E, V; // number of edges and number of vertices
    cin>>E>>V;
    Graph *graph = new Graph;
    graph->E = E;
    graph->V = V;
    graph->edge = new Edge[E];
    for (int i = 0; i < E; i++)
    {
        int s,d,w; //source, destination, weight
        cin>>s>>d>>w;
        graph->edge[i] = newEdge(s,d,w);
    }
    cout<<"----- initial graph is -----\n\n";
    print(graph);
    kruskalMST(graph);

    return 0;
}
