#include <iostream>
#include <ctime>
#include <vector>

class X
{
public:
    std::vector<int> m_vec;
 
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
        std::cout << "Copy" << std::endl;
        m_vec = other.m_vec;
        return *this;
    }
 
    X& operator=(X&& other)
    {
        std::cout << "Move" << std::endl;
        m_vec = std::move(other.m_vec);
        return *this;
    }
};
 
int main()
{
    X x1; 
 
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
    std::cout << "Move time: " << msec2 << " msec" << std::endl;
    for (int i=0; i<10; i++)
        std::cout << x3.m_vec[i] << std::endl;
    
    std::cout << "vector example " << std::endl;
    std::vector <double> tmp(1000000);
    for (int i=0; i<1000000; i++)
        tmp[i] = clock();
    
    std::cout << "vector example " << std::endl;
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