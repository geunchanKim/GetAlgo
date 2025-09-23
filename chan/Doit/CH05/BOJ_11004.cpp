#include <iostream>
#include <vector>
using namespace std;
#define FASTIO cin.tie(NULL); ios::sync_with_stdio(false);

void quickSort(vector<int> &A, int start, int end, int K);
int findPivot(vector<int> &A, int start, int end);
void swap(vector<int> &A, int i , int j);

int main(){
    FASTIO;
    int N, K;
    cin >> N >> K;
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++)
        cin >> A[i];
    
    quickSort(A, 0, N - 1, K - 1);
    cout << A[K - 1];
    return 0;
}

void quickSort(vector<int> &A, int start, int end, int K){
    int pivot = findPivot(A, start, end);
    if(pivot == K)
        return;
    else if(K < pivot)
        quickSort(A, start, pivot - 1, K);
    else
        quickSort(A, pivot + 1, end, K);
}

int findPivot(vector<int> &A, int start, int end){
    if(start + 1 == end){
        if(A[start] > A[end])
            swap(A, start, end);
        return end;
    }

    int mid = (start + end) / 2;
    swap(A, start, mid);
    int pivot = A[start];
    int i = start + 1;
    int j = end;

    while(i <= j){
        while(j >= start + 1 && pivot < A[j])
            j--;
        while(i <= end && pivot > A[i])
            i++;
        if(i < j)
            swap(A, i++, j--);
        else
            break;
    }

    A[start] = A[j];
    A[j] = pivot;
    return j;
}

void swap(vector<int> &A, int i , int j){
    int tmp = A[i];
    A[i] = A[j];
    A[j] = tmp;
}