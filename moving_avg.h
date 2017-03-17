#include <deque>
#include <vector>

class moving_avg
{
  public:
    moving_avg(int max_samps): m_max_samps{max_samps} {}
    moving_avg()             : m_max_samps{-1}        {}

    void             put_samp(int samp);
    int              get     ()         const;
    std::deque<int> samps   ()         const;

  private:
    int             m_max_samps;
    int             m_sum;
    std::deque<int> m_samps;
};
