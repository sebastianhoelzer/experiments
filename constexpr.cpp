#include <iostream>
#include <array>

template <int SIZE>
class MyArray
{
   int arr[SIZE];
public:
   constexpr MyArray():arr{0}{}
   constexpr int getVal(int index) const {return arr[index];}
   constexpr void setVal(int index, int value)
   {
      arr[index] = value;
   }
};

constexpr MyArray<256> createLookupTable()
{
   MyArray<256> table = MyArray<256>();
   // replace with algorithm for look up table
   for (int i = 0; i < 256; i++)
   {
      table.setVal(i,i);
   }

   return table;
}


int main()
{
   constexpr MyArray<256> table = createLookupTable();
   // check if table isbin binary with
   // readelf -x .rodata a.out
   std::cout << table.getVal(5);

   return 0;
}

