// swap odd and even bits in an integer (i bit with i+1 bit)
int swapOddEvenBits(int x) {
  return (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));
}
