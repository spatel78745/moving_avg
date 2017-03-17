#include <numeric>
#include <iostream>
#include <deque>
#include "moving_avg.h"

using namespace std;

void moving_avg::put_samp(int samp)
{
  if (m_samps.size() == m_max_samps) m_samps.pop_front();

  m_samps.push_back(samp);
}

int moving_avg::get() const
{
  return accumulate(m_samps.begin(), m_samps.end(), 0);
}

deque<int> moving_avg::samps() const
{
  return m_samps;
}
