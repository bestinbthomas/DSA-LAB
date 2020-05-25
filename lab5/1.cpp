#include <bits/stdc++.h>
using namespace std;
#define nl cout<<endl

struct minHeapNode {
    char value;
    int frequency;
    minHeapNode *left, *right;
};

minHeapNode* newNode(char value, int frequency){
    minHeapNode *node = new minHeapNode;
    node->value = value;
    node->frequency = frequency;
    node->left = NULL; 
    node->right = NULL; 

    return node;
}

void swap(minHeapNode **a, minHeapNode **b){
    minHeapNode *temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap {
    private:
        minHeapNode **heap;
        int capacity;

    public:
        int heapSize;
        MinHeap(int capacity);

        minHeapNode* root(){
            return heap[0];
        }

        int left(int i){
            return (i * 2) + 1; 
        }
        int right(int i){
            return (i + 1) * 2;
        }
        int parent(int i) {
            return (i - 1) / 2;
        }

        bool insert(minHeapNode *e);

        minHeapNode* deleteKey(int i);

        bool decreaseFreq(int i, int newVal);
        
        void maxheapify(int i);

        minHeapNode* extractMin();

        void print();
};
MinHeap::MinHeap(int cap){
    heapSize = 0;
    capacity = cap;
    heap = new minHeapNode*[capacity];
}

bool MinHeap::insert(minHeapNode *e){
    if(heapSize == capacity){
        return false;
    }

    heapSize++;
    int i = heapSize - 1;
    heap[i] = e;
    while(i > 0 && heap[i]->frequency < heap[parent(i)]-> frequency){
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }

    return true;
}

minHeapNode* MinHeap::deleteKey(int i){
    minHeapNode *val = heap[i];
    decreaseFreq(i,INT_MIN);
    extractMin();

    return val;
}

bool MinHeap::decreaseFreq(int i, int newVal){
    if(newVal > heap[i]->frequency) return false;

    heap[i]->frequency = newVal;
    while(heap[i]->frequency < heap[parent(i)]->frequency){
        swap(&heap[i], &heap[parent(i)]);
        i = parent(i);
    }
    return true;
}

minHeapNode* MinHeap::extractMin(){
    if(heapSize <= 0){
        return newNode('_',INT_MIN);
    }

    if(heapSize == 1){
        heapSize--;
        return heap[0];
    }

    minHeapNode *min = heap[0];
    heap[0] = heap[heapSize - 1];
    heapSize--;

    maxheapify(0);

    return min;
}

void MinHeap::maxheapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heapSize && heap[l]->frequency < heap[smallest]->frequency){
        smallest = l;
    }
    if(r < heapSize && heap[r]->frequency < heap[smallest]->frequency){
        smallest = r;
    }
    if(smallest != i){
        swap(&heap[i], &heap[smallest]);
        maxheapify(smallest);
    }
}

void MinHeap::print(){
    nl;
    for (int i = 0; i < heapSize; i++)
    {
        cout<<heap[i]->value<<" -> "<<heap[i]->frequency;nl;
    }
}

void printCodes(minHeapNode* node, string code){
    if(node->left == NULL && node->right == NULL){
        cout<<node->value<<" maps to code : "<<code;nl;
        return;
    }
    printCodes(node->left, code + "0");
    printCodes(node->right, code + "1");
}

void huffmanCoding(char v[], int f[], int n){
    MinHeap minHeap(n);

    for (int i = 0; i < n; i++)
    {
        minHeap.insert(newNode(v[i], f[i]));
    }

    minHeap.print();

    while (minHeap.heapSize > 1)
    {
        minHeapNode *left = minHeap.extractMin();
        minHeapNode *right = minHeap.extractMin();

        minHeapNode *newInternalNode = newNode('_', left->frequency + right->frequency);
        newInternalNode->left = left;
        newInternalNode->right = right;

        minHeap.insert(newInternalNode);
    }

    minHeapNode *top = minHeap.extractMin();

    printCodes(top,"");
    
}


int main() {
    int n;
    cin>>n;
    char v[n];
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    int f[n];
    for (int i = 0; i < n; i++)
    {
        cin>>f[i];
    }

    huffmanCoding(v,f,n);

    return 0;
}
