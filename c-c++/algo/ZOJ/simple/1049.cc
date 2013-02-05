#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;

int main ()
{
  int num = 0;
  int years = 0;
  float x = 0.0, y = 0.0;
  cin >> num;
  for (int i = 1; i <= num; i ++) {
    cin >> x >> y;
    years = ceil(PI * (x*x + y*y) / 100.0);
    cout << "Property " << i
         << ": This property will begin eroding in year " << years
         << "." << endl;
  }
  cout << "END OF OUTPUT."<< endl;
}
