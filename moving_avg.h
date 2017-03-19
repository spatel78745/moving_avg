#include <deque>
#include <vector>

template<typename T>
T avg(T* begin, T* end)
{
  return accumulate(begin, end, 0) / (end - begin);
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
    int           get        ()         const;
    std::deque<T> samples    ()         const;
    int           max_samples()         const;

  private:
    int           m_max_samples;
    std::deque<T> m_samples;
};
