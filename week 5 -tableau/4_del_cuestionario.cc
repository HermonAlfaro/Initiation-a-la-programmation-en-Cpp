#include <iostream>
#include <vector>
using namespace std;

int f(int n)
{
  vector<int> v;
  int j(0);

  while (n != 0) {
    v.push_back(n % 100);
    n = n / 100;
  }

  if (not v.empty()) {
    for (size_t i(v.size()-1); i != 0; --i) {
      for (++j; v[i] >= j; j = j + 2) {
        v[i] = v[i] - j;
      }

      j = 10 * (j-1);
      v[i-1] = v[i-1] + 100 * v[i];
    }

    for (++j; v[0] >= j; j = j + 2) {
      v[0] = v[0] - j;
    }

    // code manquant
    return (j-1) / 2;
  }
  
}

int main()
{
  cout << f(20000) << endl;
  return 0;
}
