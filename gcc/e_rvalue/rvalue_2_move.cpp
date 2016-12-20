#include <iostream>
#include <ctime>
#include <vector>

class MYVec
{
public:
    int num;
    std::vector<int> my_vec;
    
    MYVec () : my_vec(1000)
    {
    }
    
    MYVec (int num_) : num(num_)
    {
        my_vec.reserve(num);
        for (int i=0; i<num; ++i)
            my_vec[i] = clock();
    }
    
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
 
    //복사 생성자
    X(const X& other) : m_vec(other.m_vec) {}
 
    //이동 생성자
    X(X&& other) : m_vec(std::move(other.m_vec)) {}
 
    X& operator=(const X& other)
    {
        std::cout << "Copy =" << std::endl;
        m_vec = other.m_vec;
        return *this;
    }
 
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
    MYVec vec_in_fcn(9999);
    vec_in_fcn.my_vec.resize(10000000);
    vec_in_fcn.my_vec[0] = 1234;
    this->tmp_vec = std::move(vec_in_fcn);
}


int main()
{
    X x1; 
    x1.tmp_vec.my_vec.resize(3);
 
    //복사 시간 확인

    X x2;
    clock_t ct1 = clock();
    x2 = x1;    
//    X x2(x1);
    clock_t ct2 = clock();
    double msec = 1000.0 * (ct2-ct1) / CLOCKS_PER_SEC;
    std::cout << "Copy time: " << msec << " msec" << std::endl;
    for (int i=0; i<10; i++)
        std::cout << x2.m_vec[i] << std::endl;
 
    // 이동 시간 확인
    X x3;
    for (int i=0; i<10; i++)
        x1.m_vec[i] = 999;
    clock_t mt1 = clock();
    x3 = std::move(x1);
//    X x3(std::move(x1));
    clock_t mt2 = clock();
    double msec2 = 1000.0 * (mt2-mt1) / CLOCKS_PER_SEC;
    std::cout << "Move time: " << msec2 << " msec / my_vec size " << x1.tmp_vec.my_vec.size() << " / " <<  x3.tmp_vec.my_vec.size() << std::endl;
    for (int i=0; i<10; i++)
        std::cout << x3.m_vec[i] << std::endl;
        
        
    std::cout << "For tmp func " << std::endl;
    x3.run();
    std::cout << "New x3 size by tmp " <<  x3.tmp_vec.my_vec.size() << " / " << x3.tmp_vec.my_vec[0] << std::endl;
    
    
    // vector examples
    std::cout << "vector example " << std::endl;
    std::vector <double> tmp(1000000);
    for (int i=0; i<1000000; i++)
        tmp[i] = clock();
    
    std::vector <double> tmp2;
    std::vector <double> tmp3;
    
    clock_t c1 = clock();
    tmp3 = tmp;
    clock_t c2 = clock();
    tmp2 = std::move(tmp);
    clock_t c3 = clock();
    msec = 1000.0 * (c2-c1) / CLOCKS_PER_SEC;  
    msec2 = 1000.0 * (c3-c2) / CLOCKS_PER_SEC;
    std::cout << "copy time: " << msec << " move time " << msec2 << std::endl;
    std::cout << "1 / 2 " << tmp.size() << " / " << tmp2.size() << std::endl;


    return 0;
}
