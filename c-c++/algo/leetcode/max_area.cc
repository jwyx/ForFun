int maxArea(vector<int> &height) {

  int max = 0, area = 0;
  int i = 0, j = height.size()-1;
  while (i < j) {
    area = (j - i) * min(height[i], height[j]);
    if (max < area)
      max = area;
    if (height[i] > height[j])
      j--;
    else
      i++;
  }
  return max;
} // O(n)
