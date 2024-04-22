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