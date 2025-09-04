#include <iostream>
#include <vector>
using namespace std;

// 두 부분 배열을 병합하는 함수
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열 생성
    vector<int> L(n1), R(n2);

    // 데이터 복사
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    // 병합 과정
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // 남은 원소들 복사
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// 분할 정복 방식으로 합병 정렬 실행
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; // 가운데 인덱스
        mergeSort(arr, left, mid);           // 왼쪽 반 정렬
        mergeSort(arr, mid + 1, right);      // 오른쪽 반 정렬
        merge(arr, left, mid, right);        // 병합
        cout << left << ' ' << mid << ' ' << right << '\n';
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    mergeSort(arr, 0, N - 1);

    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}
