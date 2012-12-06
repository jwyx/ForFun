#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// max heap, increase!
void max_heapify(vector<int> &arr, int curr, int heap_size) {
  int l = curr * 2;
  int r = curr * 2 + 1;
  int largest = curr;

  if (l <= heap_size && arr[l] > arr[largest])
    largest = l;
  if (r <= heap_size && arr[r] > arr[largest])
    largest = r;
  if (largest != curr) {
    swap(arr[largest], arr[curr]);
    max_heapify(arr, largest, heap_size);
  }
}

// iterative version
void max_heapify_iter(vector<int> &arr, int curr, int heap_size) {
  int tmp = arr[curr];
  int largest = curr;
  int i = 0;
  for (i = curr * 2; i <= heap_size; i *= 2) {
    // find the larger one between left and right
    if (i < heap_size && arr[i + 1] > arr[i])
      i++;
    // check if larger than parent
    if (arr[i] <= tmp)
      break;
    // keep down
    arr[i / 2] = arr[i];
  }
  // find position
  arr[i / 2] = tmp;
}

void build_heap(vector<int> &arr) {
  int heap_size = arr.size() - 1;
  for (int i = heap_size / 2; i >= 1; i --) {
    // max_heapify(arr, i, heap_size);
    max_heapify_iter(arr, i, heap_size);
  }
}

void heap_sort(vector<int> &arr) {
  build_heap(arr);

  int heap_size = arr.size() - 1;
  for (int i = heap_size; i >= 2; i --) {
    swap(arr[i], arr[1]);
    heap_size -= 1;
    // max_heapify(arr, 1, heap_size);
    max_heapify_iter(arr, 1, heap_size);
  }
}

int main(int argc, char *argv[]) {
  int a[] = {-1, 1, 5, 3, 2, 4, 8, 7 };
  vector<int> arr (a, a + sizeof(a) / sizeof(int));

  heap_sort(arr);

  for (int i = 1; i < arr.size(); i ++)
    cout << arr[i] << " ";
  cout << endl;
}

