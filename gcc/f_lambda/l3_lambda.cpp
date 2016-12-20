#include <iostream>
#include <ctime>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
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


inline void print_title (int i) 
{
    cout << "\n*** lamda test " << i << " ***" << endl;
}

int main(void)
{
    int total_elements = 1;
    clock_t tic_t = tic();
    
    vector <int> cardinal {1, 2, 3, 4, 5};
    map < int, vector<double> > map_cache;

    for (int i=0; i<10; i++) {
        double toc_t = toc(tic_t, "push");    
        vector<double> vec_data = {toc_t};
        map_cache[i] = vec_data;
    }   
    
    vector <double> vec_cpy;
    
    
    cout << "size " << map_cache.size() << endl;
    
    
    return 0;
    
    
}




