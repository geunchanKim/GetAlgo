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
	while (child <= h->heap_size) //heap의 크기가 child 보다 크다면 힙 내부적으로 순서 수정이 필요
	{
		if ((child < h->heap_size) && (h->heap[child]) < h->heap[child + 1]) //각 level에서 몇 번째 힙이 큰지 판단하고 child 증가
			child++;
		if (temp >= h->heap[child]) break; //마지막이 지금 child번째 보다 크면 스탑
		h->heap[parent] = h->heap[child]; //부모 위치에 젤 큰 값을 가진 힙 즉 child 번째 힙을 parent에 넣어줌
		parent = child; //이제 다음 부모를 검사해보아야 함
		child = child * 2; //이제 다음 자식을 검사해보아야 함
	}
	h->heap[parent] = temp; //부모 위치에 temp 즉 마지막 값을 넣어줌
	return item;
}