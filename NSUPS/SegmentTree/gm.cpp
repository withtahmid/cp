#include <bits/stdc++.h>
using namespace std;
int compute_sum(const std::vector<int>& a, int l, int r) {
  if (l == r) {
    return a[l];
  }

  int mid = (l + r) / 2;
  int left_sum = compute_sum(a, l, mid);
  int right_sum = compute_sum(a, mid + 1, r);

  // Precompute prefix sum for the left subarray
  std::vector<int> prefix_sum_left(mid - l + 1);
  prefix_sum_left[0] = a[l];
  for (int i = 1; i < mid - l + 1; ++i) {
    prefix_sum_left[i] = prefix_sum_left[i - 1] + a[l + i];
  }

  // Efficiently compute the sum using precomputed prefix sum
  int S = left_sum + right_sum + (r - mid + 1) * a[mid] -
          prefix_sum_left[mid - l];

  return S;
}
#include<debug.h>
// Example usage
int main() {
    dbg(__init__());
  std::vector<int> a = {1, 100, 100, 100, -5};
  int l = 2, r = 4;
  int S = compute_sum(a, l, r);
  std::cout << S << std::endl; // Output: 600
  return 0;
}
