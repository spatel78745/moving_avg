#include <numeric>
#include <deque>
#include <vector>

template<typename Q, typename T>
Q avg(T begin, T end)
{
  return std::accumulate(begin, end, 0) / (end - begin);
}

template<typename T>
class moving_avg
{
  public:
    // Constructors
    moving_avg(int max_samples): m_max_samples{max_samples} {}
    moving_avg()               : m_max_samples{-1}          {}

    // Methods
    void          put_sample (T sample);
    T             get        ()         const;
    std::deque<T> samples    ()         const;
    int           max_samples()         const;

  private:
    int           m_max_samples;
    std::deque<T> m_samples;
};

template<typename T>
void moving_avg<T>::put_sample(T samp)
{
  if (m_samples.size() == m_max_samples) m_samples.pop_front();

  m_samples.push_back(samp);
}

template<typename T>
T moving_avg<T>::get() const
{
  return avg<T>(m_samples.begin(), m_samples.end());
}

template<typename T>
std::deque<T> moving_avg<T>::samples() const
{
  return m_samples;
}
