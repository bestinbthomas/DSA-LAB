#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

struct MinHeapNode
{
    int vortex;
    int key;
};

MinHeapNode* newNode(int vortex, int key){
    MinHeapNode *node = new MinHeapNode;
    node->vortex = vortex;
    node->key = key;
    return node;
}

void swap(MinHeapNode **x, MinHeapNode **y) 
{ 
	MinHeapNode* temp = *x; 
	*x = *y; 
	*y = temp; 
}

class MinHeap 
{ 
	MinHeapNode **harr;
	int capacity;
public: 
	int heap_size; 
	MinHeap(int capacity); 

	void MinHeapify(int i); 

	int parent(int i) { return (i-1)/2; } 

	int left(int i) { return (2*i + 1); } 

	int right(int i) { return (2*i + 2); } 

    int findVortex(int val);

	MinHeapNode* extractMin(); 

	bool decreaseKey(int i, int new_val); 

	MinHeapNode* getMin() { return harr[0]; } 

	void deleteKey(int i); 

	void insertKey(MinHeapNode* k); 

}; 

MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new MinHeapNode*[cap]; 
} 

int MinHeap::findVortex(int val) {
    for (int i = 0; i < heap_size; i++)
    {
        if(val == harr[i]->vortex) return i;
    }
    return -1;    
}

void MinHeap::insertKey(MinHeapNode* k) 
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	while (i != 0 && harr[parent(i)]->key > harr[i]->key) 
	{ 
        swap(harr[i], harr[parent(i)]); 
        i = parent(i); 
	} 
} 

bool MinHeap::decreaseKey(int i, int new_val) 
{
    if(new_val < harr[i]->key){
        harr[i]->key = new_val; 
        while (i != 0 && harr[parent(i)]->key > harr[i]->key) 
        { 
            swap(&harr[i], &harr[parent(i)]); 
            i = parent(i); 
        }
        return true;
    }
    return false;
} 

MinHeapNode* MinHeap::extractMin() 
{ 
	if (heap_size <= 0) 
		return newNode(-1,INT_MIN); 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	MinHeapNode* root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 


void MinHeap::deleteKey(int i) 
{ 
	decreaseKey(i, INT_MIN); 
	extractMin(); 
} 

void MinHeap::MinHeapify(int i) 
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l]->key < harr[i]->key) 
		smallest = l; 
	if (r < heap_size && harr[r]->key < harr[smallest]->key) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		MinHeapify(smallest); 
	} 
}

int getMinKey(int keys[], bool mst[], int V){
    int min = INT_MAX, minkey;
    for (int i = 0; i < V; i++)
    {
        if(!mst[i] && min > keys[i]){
            min = keys[i];
            minkey = i;
        }
    }

    return minkey;
    
}

void print(int parent[], int *graph, int V){
    cout<<"s\td\tw\n\n";
    for (int i = 1; i < V; i++)
    {
        cout<<parent[i]<<"\t"<<i<<"\t"<<*((graph + i*V) + parent[i]);nl;
    }
    
}

void PrimMSTUsingArray(int *g, int v){

    int parent[v];
    int key[v];
    bool mst[v];

    for (int i = 0; i < v; i++)
    {
        key[i] = INT_MAX;
        mst[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < v; i++)
    {
        int next = getMinKey(key, mst, v);
        mst[next] = true;

        for (int j = 0; j < v; j++)
        {
            if(*((g + next*v) + j) && !mst[j] && key[j] > *((g + next*v) + j)){
                parent[j] = next;
                key[j] = *((g + next*v) + j);
            }
        }
    }    
    cout<<"----- minimum spanning tree using array -----\n\n";
    print(parent, g, v);

}

void PrimMSTUsingMinHeap(int *g, int v){
    int parent[v];
    bool mst[v];
    MinHeap heap(v);

    heap.insertKey(newNode(0,0));
    mst[0] = false;

    for (int i = 1; i < v; i++)
    {
        heap.insertKey(newNode(i,INT_MAX));
        mst[i] = false;
    }
    

    parent[0] = -1;

    while(heap.heap_size > 0)
    {
        MinHeapNode* next = heap.extractMin();
        mst[next->vortex] = true;


        for (int j = 0; j < v; j++)
        {
            int weight = *((g + next->vortex*v) + j);
            if(weight && !mst[j]){
                int k = heap.findVortex(j);
                if(heap.decreaseKey(k, weight)){
                    parent[j] = next->vortex;
                }
            }
        }
    }    
    cout<<"----- minimum spanning tree using heap -----\n\n";
    print(parent, g, v);
}


int main() {
    int V;
    cin>>V;
    int g[V][V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cin>>g[i][j];
        }
    }
    
    PrimMSTUsingArray((int*)g, V);
    PrimMSTUsingMinHeap((int*)g, V);
    return 0;
}
