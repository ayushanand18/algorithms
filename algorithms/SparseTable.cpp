#include <vector>

class SparseTable {
  int** st;
public:
  SparseTable(int size) {
    int K = log2(size);
    st = (int**)malloc(size*(K+1)*sizeof(int));
  }
  void build(vector<int> arr) {
    for(int i=0; i<A.size(); ++i) {
      st[0][i] = A[i];
    }
    for(int j=0; j<arr.size(); ++j) {
      for(int i=0; i<=log2(arr.size()); ++i) {
        st[j][i] = min(st[j-1][i], sparse[j-1][i+pow(2, j-1)]);
      }
    }
  }
  int query(int l, int r) {
    int j = ceil(log2(r-l+1));
    return min(sparse[j][l], sparse[j][r-pow(2, j)+1]);
  }
}
