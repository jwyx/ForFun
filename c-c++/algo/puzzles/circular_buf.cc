#include <vector>
#include <string>
#include <iostream>

// https://evernotechallenge.interviewstreet.com/challenges/dashboard/#problem/4fd6b87d9fc96

using namespace std;

class CircularBuffer {
  private:
    vector<string> buf;
    size_t max_size;
    size_t head;
    size_t tail;

  public:
    CircularBuffer(size_t n = 0);
    void append(const vector<string> &arr);
    void remove(size_t n);
    void show(void);
    bool empty(void) { return head == tail; }
    bool full(void) { return next_pos(tail) == head; }
    size_t next_pos(size_t curr) { return ++ curr % max_size; }
    size_t size(void);
};

CircularBuffer::CircularBuffer(size_t n) {
  max_size = n + 1;
  buf.assign(max_size, string(""));
  head = 0;
  tail = 0;
}

size_t CircularBuffer::size(void) {
  // max_size = 3
  // t = 2, h = 1, size = 1
  if (tail >= head)
    return tail - head;
  // t = 1, h = 2, size = 3
  else
    return tail + max_size - head;
}

// O(n)
void CircularBuffer::append(const vector<string> &arr) {
  size_t curr = tail;
  for (size_t i = 0; i < arr.size(); i ++) {
    curr = tail;
    if (full())
      head = next_pos(head);
    tail = next_pos(tail);
    if (arr.size() > max_size - 1 && i < arr.size() - max_size + 1)
      continue;
    buf[curr] = arr[i];
  }
}

// O(1)
void CircularBuffer::remove(size_t n) {
  if (n >= size())
    head = tail = 0;
  else {
    head += n;
    head %= max_size;
  }
}

// O(n)
void CircularBuffer::show(void) {
  size_t curr = head;
  while (curr != tail) {
    cout << buf[curr] << endl;
    curr = next_pos(curr);
  }
}

int main(int argc, char *argv[]) {
  int size = 0;
  string cmd ("");

  cin >> size;
  CircularBuffer cb (size);

  while (true) {
    size = 0;
    cin >> cmd;

    if (cmd == string("A")) {
      cin >> size;
      vector<string> data;
      string tmp ("");
      while (size > 0) {
        cin >> tmp;
        data.push_back(tmp);
        tmp.clear();
        size --;
      }
      cb.append(data);
    }
    else if (cmd == string("R")) {
      cin >> size;
      cb.remove(size);
    }
    else if (cmd == string("L")) {
      cb.show();
    }
    else if (cmd == string("Q")) {
      break;
    }
  }
  return 0;
}

