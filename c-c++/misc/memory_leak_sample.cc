#include <cstdlib>
#include <mcheck.h>
using namespace std;

int main (int argc, char *argv[]) {
  mtrace();
  char *buf = (char *)malloc(sizeof(char) * 4);
  muntrace();
  return 0;
}
