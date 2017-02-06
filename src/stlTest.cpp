// function template variations
#include <vector>
#include <iterator>
#include <iostream>
#include <cmath>
#include <string>
#include <utility>
#include <cstring>
#include <algorithm>
#include <initializer_list>

using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::iter_swap;
using std::ostream_iterator;
//using std::initializer_list;

template<typename T>
void myReverse(T& input) {
  typename T::iterator it;
  typename T::iterator et;
  for (it = input.begin(), et = input.end(); it < et; it++, et--) {
    iter_swap(it, et - 1);
  }
  return;
}

template<typename T>
void showContents(T& input) {
  typename T::iterator it;
  for (it = input.begin(); it != input.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;
}

int zero() { return 0; }

int isOdd(int n) {return n%2;}

template <class S, class T>
class Iota
{
    S cur;
    T inc;
  public:
    Iota (const S& initial, const T& increment)
    {
      cur = initial;
      inc = increment;
    }
    S operator()() {
      S tmp (cur);
      cur += inc;
      return tmp;
    }
};

template <class T>
class InRange
{
    const T& low;
    const T& high;
  public:
    InRange (const T& l, const T& h) : low (l), high (h) { }
    bool operator()(const T& t) {
      return (t > low) && (t < high);
    }
};

/*function addOffset(vector<int>& v, int n)
{

  // we want to add n to each element of v
  struct AddN : public unary_function<int>
    { AddN(int n) : _n (n) {};
      int operator() (const int& k) { return k + n; }
    };
  transform (v.begin(), v.end(), v.begin(), AddN(n));
}*/

//typedef ostream_iterator<int> output;

void myprint(std::initializer_list<int> vals) {
  for (auto p = vals.begin(); p != vals.end(); ++p) {  // process a list of values
    std::cout << *p << "\n";
  }
}

int main()
{
  int x[] = { 1, 2, 3, 4, 5 };
  vector<int> MyVec(x, x + 5);
  showContents(MyVec);
  myReverse(MyVec);
  showContents(MyVec);

  string str = "This is a C++ string";
  vector<char> data(str.begin(), str.end());
  showContents(data);
  myReverse(data);
  showContents(data);

  string MyString("This is a C++ string container");
  showContents(MyString);
  myReverse(MyString);
  showContents(MyString);

  char Cstr[] = "This is a C string char array";
  vector<char> data1(Cstr, Cstr + (strlen(Cstr)));
  showContents(data1);
  myReverse(data1);
  showContents(data1);

  vector<string> fruit;  // This is a string vector
  fruit.push_back("apple");
  fruit.push_back("banana");
  fruit.push_back("orange");
  fruit.push_back("strawberry");
  showContents((fruit));
  myReverse(fruit);
  showContents((fruit));

  vector<int> v (10);
  generate (v.begin(), v.end(), Iota<int,int> (0, 1));
  showContents(v);
  //cout << v << endl;

//  vector<int>::iterator iter = find_if (v.begin(), v.end(), isOdd);
  vector<int>::iterator iter = find_if (v.begin(), v.end(), InRange<int>(5,8));
  copy (iter, v.end(), ostream_iterator<int>(cout, " ")); cout << endl;
  showContents(v);

  auto n=8;
  cout << n <<endl;

//  myprint({12,3,5,7,11,13,17}); // pass a list of values to print()


}
