#include <iostream>
#include "moving_avg.h"

using namespace std;

static const char *pf[] = { "FAIL", "PASS" };

static void test1()
{
  // Create a moving_average with 5 maximum samples
  // Put 10 samples of "10"
  // PASS: ma.get() == 10

  moving_avg ma{10};

  for (int i = 0; i < 10; ++i)
  {
    ma.put_samp(10);
  }

  cout << __func__ << ": " << pf[ma.get() == 10] << endl;
}

static void test2()
{
  moving_avg ma{5};

  for (int i = 1; i <= 10; ++i)
  {
    ma.put_samp(i);
  }

  int i, j;
  deque<int> samples = ma.samps();
  for (i = 6, j = 0; i <=10; ++i, ++j)
  {
    if (samples[j] != i)
    {
      printf("Expected (%d) at index (%d), got (%d).\n",
          i, j, samples[i]);
      cout << "FAIL" << endl;
      return;
    }
  }
  cout << "PASS" << endl;
}

int main(int argc, char *argv[])
{
  //test1();
  test2();

  return 0;
}
