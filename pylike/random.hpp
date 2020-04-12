#ifndef _RANDOM_HPP_
#define _RANDOM_HPP_

#include <iostream>
#include <memory>
#include <cstdlib>
#include <random>


class Random
{
public:
   Random() :
      m_mt(rd())
   {
   }

   int randrange(int lowest, int highest)
   {
      std::uniform_int_distribution<int> distribution(lowest, highest);
      return distribution(m_mt);
   }
private:
   std::random_device rd;
   std::mt19937 m_mt;
};


/*
int main()
{
   RandomNumberGenerator rg;
   std::cout << rg.getNumberWithinRange(1,6) << std::endl;

   return 0;
}
*/
#endif
