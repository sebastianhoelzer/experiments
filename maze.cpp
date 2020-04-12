#include <iostream>
#include <iomanip>
#include "pylike/random.hpp"

template <int width, int height>
struct Maze
{
   Maze()
   {
      init();
   }

   void init()
   {
      for (int y = 0; y < height; ++y)
      {
         for (int x = 0; x < width; ++x)
         {
            if(x%2 != 1 || y%2 != 1)
            {
               grid[x][y] = true;
            }
            else
            {
               grid[x][y] = false;
            }
         }
      }
   }

   void generate()
   {
      Random random;
      for (int y = 1; y < height; y=y+2 )
      {
         for (int x = 1; x < width; x=x+2)
         {
            bool openEast = random.randrange(0,1);
            if ( x == (width - 2))
            {
               openEast = false;
            }
            if ( y == (height -2))
            {
               openEast = true;
            }

            if (openEast)
            {
               grid[x +1][y] = false;
            }
            else
            {
               grid[x][y+1] = false;
            }
         }
      }
   }

   void print()
   {
      std::cout << "    ";
      for (int y = 0; y < height; ++y)
      {
         std::cout << std::setw(2) << y/10 ;
      }
      std::cout << "\n    ";

      for (int y = 0; y < height; ++y)
      {
         std::cout << std::setw(2) << y%10;
      }

      std::cout << "\n";
      for (int y = 0; y < height; ++y)
      {
         std::cout << std::setw(3) << y << " ";
         for (int x = 0; x < width; ++x)
         {
            std::cout << (grid[x][y]?"XX":"  "); 
         }
         std::cout << "\n";
      }
      std::cout << "\n";
   }


private:
   bool grid[width][height];
};

int main()
{
   Maze<25, 25> maze;
   maze.generate();
   maze.print();
   return 0;
}


