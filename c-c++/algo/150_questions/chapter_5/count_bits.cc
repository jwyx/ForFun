// count 1 in the integer

int countBits(int a) {
  int count = 0;
  for (int c = a; c != 0; c = c >> 1) {
    count += c & 1;
  }
  return count;
}
