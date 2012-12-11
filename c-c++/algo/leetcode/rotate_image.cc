void rotate(vector<vector<int> > &matrix) {
  int n = matrix.size();
  for (int i = 0; i < n/2; ++ i) {
    for (int j = i; j < n - i - 1; ++ j) {
      int temp = matrix[i][j];
      // left-top
      matrix[i][j] = matrix[n-1-j][i];
      // left-bottom
      matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
      // right-bottom
      matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
      // right-top
      matrix[j][n-1-i] = temp;
    }
  }
}
