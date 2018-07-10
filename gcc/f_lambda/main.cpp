#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <array>

using namespace std;
 
template <typename T>
struct product
{
	product( T & storage ) : value(storage) {}
//	template< typename V>
	void operator()( T & v )
	{
		value *= v;
	}
	T & value;
};

struct mod
{
    mod(int m) : modulus(m) {}
    int operator()(int v) { return v % modulus; }
    int modulus;
};
 
int main(void)
{
    int total_elements = 1;
    
    vector <int> cardinal {1, 2, 3, 4, 5};
    

       

    return 0;
}
