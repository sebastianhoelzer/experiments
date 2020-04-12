#include <iostream>
#include <vector>

namespace PyLike

{

class AbstractSequence;


class Var
{
public:

   enum Type
   {
      INTEGER_TYPE,
      DOUBLE_TYPE,
      STRING_TYPE,
      BOOL_TYPE
   };

   Var(float myFloat)
      {
         std::cout << "Float\n";
         m_dataType = DOUBLE_TYPE;
      }
   Var(double MyDouble)
      {
         std::cout << "Double\n";
      }
   Var(std::string MyString)
      {
         std::cout << "String\n";
      }
   Var(int MyInt)
      {
         std::cout << "Integer\n";
      }
   Var(bool MyBool)
      {
         std::cout << "Bool\n";
      }
   Var(const char* charpointer)
      {
         std::cout << "Char pointer\n";
      }

  //todo: implement the in operator
  bool in(const AbstractSequence &sequence)
  {
    return true;
  }
private:
   double doubleValue;
   int intValue;
   bool boolValue;
   std::string stringValue;
   Type m_dataType;
};


class AbstractSequence
{
public:
   virtual int ____len____() = 0;
   //virtual bool all() = 0;
   //virtual bool any() = 0;
   //virtual List enumerate() = 0;
   //virtual List sorted() = 0;
};


class List : public AbstractSequence
{
   //std::vector<boost::any> m_list;
   std::vector<Var> m_list;

   public:
   List(const std::initializer_list<Var> &list)
   {
      // Now initialize our array from the list
      for (auto &element : list)
      {
         m_list.push_back(element);
      }
   }

   int ____len____() override
   {
      return m_list.size();
   }

   //void append(Var);
};

template <typename T>
int len(T dataStructure)
{
   static_assert(std::is_base_of<AbstractSequence, T>(), "Type doesn't implement a len function");
   return dataStructure.____len____();
}

template <typename T>
void print(T value)
{
  std::cout << value <<std::endl;
} 

std::vector<int> range(int stop)
{
  std::vector<int> range;
  for(int i = 0; i < stop; ++i)
  {
    range.push_back(i);
  }

  return range;
}

class Range
{

public:
   int beginIndex();
   int endIndex();

};



} // end of namespace PyLike

int main()
{
   using namespace std::string_literals;
   using namespace PyLike;

   List list = {1, 2.4, "123", true, "1234"s};

   std::cout << len(list) << std::endl;
   int myVariable = 123;
   print(myVariable);

   auto myRange = range(3);

   for (int i: range(3))
   {
      print(myRange.at(i));
   }
   //print(range(25));

   print(Var(5).in(List{1, 2, 3, 4, 5}));
   return 0;
}
