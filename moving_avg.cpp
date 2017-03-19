#include <numeric>
#include <iostream>
#include <deque>
#include "moving_avg.h"

using namespace std;

template<typename T>
void moving_avg<T>::put_sample(T samp)
{
  if (m_samples.size() == m_max_samples) m_samples.pop_front();

  m_samples.push_back(samp);
}

template<typename T>
int moving_avg<T>::get() const
{
  return avg(m_samples.begin(), m_samples.end(), 0);
}

template<typename T>
deque<T> moving_avg<T>::samples() const
{
  return m_samples;
}
