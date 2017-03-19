#include <iostream>
#include "moving_avg.h"

using namespace std;

static const char *pf[] = { "FAIL", "PASS" };

static void test1()
{
  // Create a moving_average with 5 maximum samples
  // Put 10 samples of "10"
  // PASS: ma.get() == 10

  moving_avg<int> ma{10};

  for (int i = 0; i < 10; ++i)
  {
    ma.put_sample(10);
  }

  cout << __func__ << ": " << pf[ma.get() == 10] << endl;
}

static void test2()
{
  // Create a moving_avg with 5 samples
  moving_avg<int> ma{5};

  // Put in 10 samples. Only the last 5 should be retained.
  for (int i = 0; i != 10; ++i) ma.put_sample(i);

  // Test that only the last 5 samples are retained
  deque<int> samples = ma.samples();
  for (int j = 0; j != 5; ++j)
  {
    int expected = j + 5;
    if (samples[j] != expected)
    {
      printf("Expected (%d) at index (%d), got (%d).\n",
          expected, j, samples[j]);
      cout << __func__ << ": FAIL" << endl;
      return;
    }
  }

  cout << __func__ << ": PASS" << endl;
}

template<typename T>
static void test3(istream& is, int max_samples)
{
  moving_avg<T> ma(max_samples);

  int sample, expected;
  while (is >> sample >> expected)
  {
    cout << "Sample: " << sample << " Expected: " << expected << endl;
  }
}

int main(int argc, char *argv[])
{
  //test1();
  //test2();
  test3<double>(cin, 5);

  return 0;
}
