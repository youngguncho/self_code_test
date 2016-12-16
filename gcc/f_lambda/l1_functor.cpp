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
    
    
    // Product functor
    for_each( cardinal.begin(), cardinal.end(), product<int>(total_elements));
    cout << "Product functor total_elements " << total_elements << endl;
    
    // Product lambda
    total_elements = 1;
    for_each(cardinal.begin(), cardinal.end(), [&total_elements](int i){total_elements *= i;});
    cout << "Product lambda total_elements " << total_elements << endl;

    vector <int> in {9, 10, 3, 8, 33};
    int m_mod = 8;
    // Mod functor
    
    
    // Mod 
    transform(in.begin(), in.end(), in.begin(), [m_mod](int v) ->int {return v%m_mod;});
    for_each(in.begin(), in.end(), []   (int i){cout << i << " ";});

       

    return 0;
}
