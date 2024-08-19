using namespace std;
#include <iostream>

typedef struct{
    int heap[100000];
    int heap_size;
}HeapType;

void insertHeap(HeapType* h, int item);
int deleteHeap(HeapType* h);

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    int N;
    cin >> N;
    HeapType h;
    h.heap_size = 0;
    for(int i = 0; i < N; i++){
        int operation;
        cin >> operation;
        if(operation == 0){
            if(h.heap_size)
                cout << deleteHeap(&h) << "\n";
            else
                cout << 0 << "\n";
        }else{
            insertHeap(&h, operation);
        }
    }
}

void insertHeap(HeapType* h, int item){
	int i;
	h->heap_size = h->heap_size + 1;
	i = h->heap_size;
	while ((i != 1) && (item > h->heap[i / 2]))
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

int deleteHeap(HeapType* h)
{
	int parent, child;
	int item, temp;
	item = h->heap[1];
	temp = h->heap[h->heap_size];
	h->heap_size = h->heap_size - 1;
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1])
			child++;
		if (temp >= h->heap[child]) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return item;
}