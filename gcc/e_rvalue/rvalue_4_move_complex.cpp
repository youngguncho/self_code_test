#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

struct cpc {
    double x;
    double y;
    double z;
};

class line 
{
public:
    cpc start;
    cpc end;
};

class MYVec
{
public:
    int num;
    std::vector<int> my_vec;
    std::vector<cpc> my_cpc;
    line my_line;
    
    MYVec () : my_vec(1000)
    {
    }
    
//    
//    MYVec& operator=(MYVec&& other)
//    {
//        std::cout << "Move" << std::endl;
//        my_vec = std::move(other.my_vec);
//        return *this;
//    }
};

class X
{
public:
    std::vector<int> m_vec;
    MYVec tmp_vec;
    
public:
    X() : m_vec(10000000)
    {
        for (size_t i = 0 ; i < 10000000; ++i )
            m_vec[i] = i;

    }
    
    X (MYVec vec_) : tmp_vec (vec_) { }
 
    // copy constructor
    X(const X& other) : m_vec(other.m_vec), tmp_vec(other.tmp_vec) {}
 
    // move constructor
    X(X&& other) : m_vec(std::move(other.m_vec)), tmp_vec(move(other.tmp_vec)) {}
 
    // copy operator
    X& operator=(const X& other)
    {
        std::cout << "Copy =" << std::endl;
        m_vec = other.m_vec;
        return *this;
    }
 
    // move operator
    X& operator=(X&& other)
    {
        std::cout << "Move =" << std::endl;
        m_vec = std::move(other.m_vec);
        tmp_vec = std::move(other.tmp_vec);
        return *this;
    }
    
    void run ();
};


void X::run ()
{
    MYVec vec_in_fcn;
    vec_in_fcn.my_vec.resize(1234);
    vec_in_fcn.my_vec[0] = 1234;
    vec_in_fcn.my_cpc.resize(2222);
    cpc ccc = {1, 1, 1};
    vec_in_fcn.my_cpc[0] = ccc;
    
    cpc start = {2, 3, 3};
    cpc end = {4, 4, 4};
    vec_in_fcn.my_line.start = start;
    vec_in_fcn.my_line.end = end;

    
    this->tmp_vec = std::move(vec_in_fcn);

}

inline clock_t tic ()
{
    return clock();
};

inline void toc (clock_t tic_t, string title)
{
    clock_t toc_t = clock();
    double msec = 1000.0 * (toc_t-tic_t) / CLOCKS_PER_SEC;
    cout << title << " ex time " << msec << " [msec]" << endl;
}



int main()
{

    X x1;
    x1.run();
    cout << "x1 vec size = " << x1.tmp_vec.my_vec.size() << " / vec 0 " << x1.tmp_vec.my_vec[0] << endl;
    cout << "x1 cpc size = " << x1.tmp_vec.my_cpc.size() << " / vec 0 " << x1.tmp_vec.my_cpc[0].x << endl;
    cout << "x1 line " << x1.tmp_vec.my_line.start.x << " / " << x1.tmp_vec.my_line.end.x << endl;
    X x2;
    x2 = move(x1);
    cout << "x2 vec size = " << x2.tmp_vec.my_vec.size() << " / vec 0 " << x2.tmp_vec.my_vec[0] << endl;
    cout << "x2 cpc size = " << x2.tmp_vec.my_cpc.size() << " / vec 0 " << x2.tmp_vec.my_cpc[0].x << endl;    
    cout << "x2 line " << x2.tmp_vec.my_line.start.x << " / " << x2.tmp_vec.my_line.end.x << endl;    
    
    clock_t tic_t = tic();
    X x3(move(x2));
    toc(tic_t, "x3 move");
    
//    x3 = move(x2);
    cout << "x3 vec size = " << x3.tmp_vec.my_vec.size() << " / vec 0 " << x3.tmp_vec.my_vec[0] << endl;
    cout << "x3 cpc size = " << x3.tmp_vec.my_cpc.size() << " / vec 0 " << x3.tmp_vec.my_cpc[0].x << endl;
    cout << "x3 line " << x3.tmp_vec.my_line.start.x << " / " << x3.tmp_vec.my_line.end.x << endl;    
    
    tic_t = tic();
    X x4(x3);
    toc(tic_t, "x3 copy");
    cout << "x4 vec size = " << x4.tmp_vec.my_vec.size() << " / vec 0 " << x4.tmp_vec.my_vec[0] << endl;
    cout << "x4 cpc size = " << x4.tmp_vec.my_cpc.size() << " / vec 0 " << x4.tmp_vec.my_cpc[0].x << endl;
    cout << "x4 line " << x4.tmp_vec.my_line.start.x << " / " << x4.tmp_vec.my_line.end.x << endl;  
    
    MYVec main_vec;  
    

    return 0;
}
