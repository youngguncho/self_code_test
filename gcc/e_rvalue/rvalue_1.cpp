#include <iostream>

class MyClass
{

};

struct ITEM {};
void GetItem( ITEM& item )
{
    std::cout << "LValue 참조" << std::endl;
}

void GetItem( ITEM&& item )
{
    std::cout << "RValue 참조" << std::endl;
}

int main (void)
{
    // L value = still remains after the line
    // R value = deleted after the line (tmp value)
    
    int d = 13;    // d is L-Value, 13 is R-Value
    int f = 12;     // f is L-Value , 12 is R-Value
 
    // c++ 98 에서 사용하던 L-Value 레퍼런스 부분
    int a = 1;
 
    // int& ra = 3; this will be error
    // L-value 레퍼런스의 오른쪽 값은 반드시 L-Value여야 하므로 에러
    int& ra = a;
 
    ra = 22;
    std::cout << "Original: L-Value(a): " << a << ", L-Value Reference(ra): " << ra << std::endl;
 
    // C++ 11에 새롭게 도입된 R-Value 레퍼런스 부분
    int b = 10;
 
    // R-Value 레퍼런스는 오른쪽 값으로 R-Value나 L-Value 모두 사용 가능
    int && rb = 20;
 
    std::cout << "Original: L-Value(b): " << b << ", R-Value Reference(rb): " << rb << std::endl;
    rb = b;
    std::cout << "Modified: L-Value(b): " << b << ", R-Value Reference(rb): " << rb << std::endl;
 

    ITEM item;
    GetItem( item );
    GetItem( ITEM() );

    return 0;
    
}

