// compress the samll cols between bigs into a small col, big col + small col
// e.g. PAYPALISHIRING
//
// P     I     N
// A   L S   I G
// Y A   H R
// P     I
//
// compressed:
// P   I   N
// A L S I G
// Y A H R
// P   I
// nBlock = 6
string convert(string s, int nRows) {
  if (nRows <= 1)
    return s;

  int nBlock = nRows + nRows - 2;
  int moreCount = nBlock - s.size() % nBlock;
  int w = (moreCount + s.size()) / nBlock;
  int h = nRows;
  int pos = 0;
  string result;
  for (int i = 0; i < h; i ++) {
    for (int j = 0; j < w; j ++) {
      pos = nBlock * j + i;
      if (pos < s.size())
        result.push_back(s[pos]);
      pos = nBlock * j + nBlock - i;
      if (i > 0 && i < h - 1 && pos < s.size())
        result.push_back(s[pos]);
    }
  }
  return result;
}
