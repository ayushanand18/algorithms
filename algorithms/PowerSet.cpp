vector<vector<int>> generatePowerSet(vector<int> arr) {
  int len = arr.size();
  int total = 1<<len;
  vector<int> ans;
  for(int i=0; i<total; ++i) {
    vector<int> temp;
    for(int j=0; j<len; ++j) {
      if(i & (1 << j) != 0) temp.push_back(arr[j]);
    }
    ans.push_back(temp);
  }

  return ans;
}
