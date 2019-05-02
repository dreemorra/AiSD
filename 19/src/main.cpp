#include <iostream>
#include <limits>
#include <vector>
 
unsigned long long merge(std::vector<int>& A, int l, int m, int r) {
  int n1 = m - l + 1, n2 = r - m;
  std::vector<int> L;
  std::vector<int> R;
 
  for (int i = 0; i < n1; i++) {
    L.push_back(A[l + i]);
  }
 
  for (int i = 0; i < n2; i++) {
    R.push_back(A[m + 1 + i]);
  }
 
  L.push_back(INT32_MAX);
  R.push_back(INT32_MAX);
 
  int inversions = 0;
  int i = 0, j = 0;
  for (int k = l; k < r + 1; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
      inversions += n1 - i;
    }
  }
 
  return inversions;
}
 
unsigned long long mergeSort(std::vector<int>& A, int l, int r) {
  if (l < r) {
    int m = (l + r) / 2;
    return mergeSort(A, l, m) + mergeSort(A, m + 1, r) + merge(A, l, m, r);
  } else {
    return 0;
  }
}
 
int main() {
  int n = 0;
  std::cin >> n;
  std::vector<int> A;
 
  for (int i = 0; i < n; i++) {
    int value = 0;
    std::cin >> value;
    A.push_back(value);
  }
 
  std::cout << mergeSort(A, 0, n - 1);
  return 0;
}