// Credit: http://blog.csdn.net/v_july_v/article/details/6712171
// Question:
//   问题描述：海量日志数据，提取出某日访问百度次数最多的那个IP。
//
// Category:
//   hashing

#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define N 32
#define MEM_SIZE (128*1024*1024)
#define ID(x) (x>>27)
#define VALUE(x) (x&0x07ffffff)
#define MAKE_IP(x, y) ((x<<27)|y)

using namespace std;

void prepare_data(const char *outfile, const unsigned &n) {
  srand(time(0));
  fstream fout (outfile, ios::out | ios::binary);
  if (fout.is_open()) {
    for (unsigned i = 0; i < n; i ++) {
      unsigned val = unsigned(rand());
      val = (val << 24) | val;
      fout.write((char*)&val, sizeof(unsigned));
    }
  }
}

void find_most_common_ip(const char *datafile) {
  fstream temp_files[N];

  for (unsigned i = 0; i < N; i ++) {
    char temp_name[128] = "";
    sprintf(temp_name, "./tmp%d.dat", i);
    temp_files[i].open(temp_name, ios::trunc | ios::in | ios::out | ios::binary);

    if (!temp_files[i].is_open()) {
      cout << "open file error" << endl;
      exit(1);
    }
  }

  unsigned temp;
  fstream fin (datafile, ios::in|ios::binary);
  while (fin.read((char*)&temp, sizeof(unsigned))) {
    unsigned val = VALUE(temp);
    temp_files[ID(temp)].write((char*)&val, sizeof(val));
  }

  for (unsigned i = 0; i < N; i ++)
    temp_files[i].seekg(0);

  unsigned max_ip = 0;
  unsigned max_times = 0;

  unsigned *count = new unsigned[MEM_SIZE];

  for (unsigned i = 0; i < N; ++ i) {
    memset(count, 0, sizeof(unsigned)*MEM_SIZE);

    unsigned temp;
    while (temp_files[i].read((char*)&temp, sizeof(unsigned)))
      ++ count[temp];

    for (unsigned j = 0; j < MEM_SIZE; j ++) {
      if (count[j] > max_times) {
        max_times = count[j];
        max_ip = MAKE_IP(i, j);
      }
    }
  }

  delete[] count;

  unsigned char *result = (unsigned char *)&max_ip;
  char ip_addr[4] = "";
  sprintf(ip_addr, "%u.%u.%u.%u", result[0], result[1], result[2], result[3]);
  cout << "ip:" << ip_addr\
    << "; times:" << max_times\
    << endl;

  for (unsigned i = 0; i < N; i ++) {
    char temp_name[128] = "";
    sprintf(temp_name, "./tmp%d.dat", i);
    if (remove(temp_name)) {
      cout << "delete file error" << endl;
      exit(2);
    }
  }
}

int main(int argc, char* argv[]) {
  char data_file[] = "test.dat";

  prepare_data(data_file, 1000000);
  find_most_common_ip(data_file);
  remove(data_file);

  return 0;
}
