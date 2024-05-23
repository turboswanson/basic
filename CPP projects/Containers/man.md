# Vector

## Initialization

std::vector<int> v1(5); // consist of 5 elements equals 0
std::vector<int> v2(5,2); // consist of 5 elements equals 2
std::vector<int> v3{1,2,3,4,5}; //consist of 1,2,3,4,5

using namespace std;

vector<int> numbers{1,2,3,4,5};

## Calling

cout << numbers.front() << endl; // FRONT
cout << numbers.back() << endl;  // BACK
cout << numbers.at(2) << endl;
cout << numbers[4] << endl;

## RANGE-BASED FOR LOOP

for(auto i : numbers) { // making a copy for each element of numbers, put into x and print it  
    cout << i << " ";
}

for(auto& i : numbers) { // increment each numbers element by using i as a reference
    ++i;
}

## Iterators

vector<int> numbers{1,2,3,4,5};
std::vector<int>::iterator iter = numbers.begin();
auto iter{numbers.begin()}; 
*iter = 125;

const vector<int> numbers{1,2,3,4,5};
std::vector<int>::iterator_const iter = numbers.begin();

auto iter{numbers.begin()}; OR auto iter{numbers.cbegin()};  // BEGIN AND END
auto iter{numbers.end()}; OR auto iter{numbers.cend()}; 

*iter=125; // FORBIDDEN for const

*iter
++iter
--iter
iter comparings

while (iter != numbers.end()){
    cout << *iter << " "; 
    iter++;
}


# User's Input 

#include <string>
#include <sstream>

vector<int> v;
string str;

getline(cin, str);
istringstream iss(str);

int num;

while(iss >> num ){
    v1.push_back(num);
}

# Using

using namespace std; // scope operator 
using value_type = T; // alias

# Move semantics

std::move is using with different signatures because it's a template:
    
    std::vector<int> v1 {1,2,3};
    std::vector<int> v2 {std::move(v1)}; makes rvalue reference(&&) from lvalue v1
    it's using template <class T> constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept signature

    std::vector<int> v3 {4,5,6};
    std::move(v1.begin(),v1.end(),v3.begin()); 
    template <class InputIt> move_iterator<InputIt> move(InputIt it) noexcept signature

# lvalue/rvalue

expression categories

void foo(int& num){ // expects lvalue

}

void function(int&& num){} // expects rvalue reference

int main(){
    int a = 10;
    foo(a);
    foo(10);// wrong, works only if foo has (const int& num) signature
    function(std::move(a));
}

# void front() const 

does not modify the state of the object

# noexcept

it's a method specifier

# Args 

template parameter pack   



# Inheritance // Virtual methods and polymorphism

template <typename T>
class Shape {
public:
  virtual T get_square() = 0;
  virtual T get_perimeter() = 0;
};

template<typename T>
class Rectangle : public Shape<T> {
public:
  Rectangle(T width,T height) : a(width), b(height) {}
  T get_square() override {
    return a*b;
  }

  T get_perimeter() override {
    return 2*(a+b);
  }

private:
  T a,b;
};

template<typename T>
class Circle : public Shape<T> {
public:
  Circle() : radius(0) {}
  Circle(T num) : radius(num) {}
  
  T get_square() override {
    return 3,14*radius*radius;
  }

  T get_perimeter() override{
    return 2*3,14*radius;
  }


private:
  T radius;
};


int main(){ 

Rectangle<double> r(2,3);
Circle<int> c(5);

std::cout << r.get_perimeter() << std:: endl;
std::cout << r.get_square() << std:: endl;
std::cout << c.get_perimeter() << std:: endl;
std::cout << c.get_square() << std:: endl;
return 0;
  
}

