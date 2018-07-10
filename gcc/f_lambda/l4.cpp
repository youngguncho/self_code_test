#include <iostream>
#include <ctime>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <array>

using namespace std;
 
inline clock_t tic ()
{
    return clock();
};

inline double toc (clock_t tic_t, string title)
{
    clock_t toc_t = clock();
    double msec = 1000.0 * (toc_t-tic_t) / CLOCKS_PER_SEC;
    cout << title << " ex time " << msec << " [msec]" << endl;
    return msec;
}

// Declaring the type of Predicate that accepts 2 pairs and return a bool
typedef std::function<bool(std::pair<std::string, int>, std::pair<std::string, int>)> Comparator;

// Defining a lambda function to compare two pairs. It will compare two pairs using second field
Comparator compFunctor =
	[](std::pair<std::string, int> elem1 ,std::pair<std::string, int> elem2)
	{
		return elem1.second > elem2.second;
	};


inline void print_title (int i) 
{
    cout << "\n*** lamda test " << i << " ***" << endl;
}

class temp
{
public:
    explicit temp();

    int i;

};


int main(void)
{
	// Creating & Initializing a map of String & Ints
	std::map<std::string, int> mapOfWordCount = { { "aaa", 10 }, { "ddd", 41 },
			{ "bbb", 62 }, { "ccc", 13 } };
 

	// Declaring a set that will store the pairs using above comparision logic
	std::set<std::pair<std::string, int>, Comparator> setOfWords(
			mapOfWordCount.begin(), mapOfWordCount.end(), compFunctor);
 
	// Iterate over a set using range base for loop
	// It will display the items in sorted order of values
	for (std::pair<std::string, int> element : setOfWords)
		std::cout << element.first << " :: " << element.second << std::endl;
		
		
    return 0;
    
    
}




