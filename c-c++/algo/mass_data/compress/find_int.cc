// Credit:
//    http://blog.csdn.net/v_july_v/article/details/6712171
//
// Question:
//    7、腾讯面试题：给40亿个不重复的unsignedint的整数，没排过序的，然后再给一个数，如何快速判断这个数是否在那40亿个数当中？
//
// Analysis:
//    4*10e9
//    if unsigned int: 4 byte
//    B->KB->MB->GB
//    => need less than 4*4 GB
//    32bit memory => 2^32 => 4GB
//    so use one byte to represent 8 int, only need 1/32 original memory
//    16 GB / 32 => 512 MB

#include <map>
#include <bitset>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
using namespace std;

class FindInt {
  private:
    map<unsigned long, bitset<512> > dict;
  public:
    void prepare_data(const char *filename);
    bool find_target(const unsigned long &target) const;
};

void FindInt::prepare_data(const char *filename) {
  vector<unsigned long> data;
  unsigned long temp;
  string line;

  ifstream fin(filename);
  if (fin.is_open()) {
    while(getline(fin, line)) {
      istringstream iss(line);
      iss >> temp;
      data.push_back(temp);
    }
  }

  for (vector<unsigned long>::iterator it = data.begin(); it != data.end(); ++ it) {
    unsigned long k1 = (*it) / 512;
    unsigned k2 = (*it) % 512;
    assert(!dict[k1].test(k2));
    dict[k1].set(k2);
  }
}

bool FindInt::find_target(const unsigned long &target) const {
  unsigned long k1 = target / 512;
  unsigned k2 = target % 512;
  if (dict.count(k1))
    // NOTE: not use [], it's not const
    return dict.at(k1).test(k2);
  return false;
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    cout << "usage: xx data_file" << endl;
    return 1;
  }

  FindInt c;
  c.prepare_data(argv[1]);

  unsigned long t;
  cin >> t;

  cout << c.find_target(t) << endl;

  return 0;
}
