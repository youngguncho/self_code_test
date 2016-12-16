#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>
#include <array>

using namespace std;
 
template< typename T>
void fill (vector<int> &v, T done)
{
    int i = 0;
    while (!done())    
    {
        v.push_back(++i);
    }

}
 
class gorp
{
    vector <int> values;
    int _m;
public:
    gorp(int mod) : _m(mod) {}
    gorp& put(int v) {values.push_back(v); return *this;}
    int extras()
    {
        int count = 0;
        for_each (values.begin(), values.end(),
                  [=, &count](int v){count += v%_m;});
        return count;
    }
    void print_val()
    {
        int count = 0;
        for_each (values.begin(), values.end(),
        [&](int v)
        {count += 1; if(count < values.size()) cout << v << " "; else cout << v << endl;});
    }
};
 
inline void print_title (int i) 
{
    cout << "\n*** lamda test " << i << " ***" << endl;
}

int main(void)
{
    int total_elements = 1;
    
    vector <int> cardinal {1, 2, 3, 4, 5};
    
    
    // lambda test 
    // 인자로 v 를 받는 클로져가 생성되었는데, (7) 로 이 클로져에 인자로 7 을 전달시키면서 실행
    print_title(1);
    [](int v){cout << v << "*6=" << v*6 << endl;} (7);


    // lambda test 2    
    // 람다 자체가 함수 처럼 자유롭게 사용할 수 있는 것이기 때문에 인자로 (당연히) 레퍼런스 들도 전달 가능
    print_title(2);
	int i = 7;
	[](int & v){ v*= 6; } (i);
	cout << "the correct value is: " << i << endl;
    
    /** Capture
      [&]() { . . . } 외부의 모든 변수들을 레퍼런스로 가져온다. (함수의 Call - by - reference 를 생각)
      [=]() { . . . } 외부의 모든 변수들을 값으로 가져온다. (함수의 Call - by - value 를 생각)
      [=, &x, &y] { . . . }, [&, x, y] { . . . } 외부의 모든 변수들을 값/레퍼런스로 가져오되, x 와 y 만 레퍼런스/값으로 가져온다
      [x, &y, &z] { . . . } 지정한 변수들을 지정한 바에 따라 가져온다. 
    */
    
    // lambda test 3
    // fill 함수는 특정 타입 T 의 변수 done 으로 클로져 객체를 받음
    // 이 때, 클로져 객체 자체는 이미 stuff 를 Capture 해서 stuff 에 대한 레퍼런스를 계속 가지고 있는 상태
    // fill 의 while 문에서 돌면서 stuff 의 크기가 8 이하 일 때 까지 수행
    print_title(3);
    vector<int> stuff;
    fill(stuff, [&]()->bool{return stuff.size()>=8;});
    for_each (stuff.begin(), stuff.end(), [](int i){cout << i << " ";});
    cout << endl;
        
    // lambda test 4
    // stuff 원소 합이 10 이하일때 까지 stuff 원소 추가
    print_title(4);
    stuff.clear();
    fill (stuff, [&]()->bool{int sum=0;
                             for_each(stuff.begin(), stuff.end(), [&](int i){sum += i;});
                             return sum >= 10;
                             });
    for_each (stuff.begin(), stuff.end(), [](int i){cout << i << " ";});
    
    // lambda test 5
    // 람다는 클로져 객체가 처음 생성될때 변수들의 값을 Capture 
    print_title(5);
    int v = 42;
    auto func = [=]{cout << v << endl;};
    v = 8;
    func();
    
    // lambda test 6
    // 람다는 Capture 를 값으로 할 때 주의점은 그 변수들에는 자동으로 const 속성을 부여하므로
    // mutable 속성을 추가
    print_title(6);
    i = 10;
    // errer code: 	auto two_i = [=]()->int{ i*= 2; return i; };
	auto two_i = [=]() mutable ->int{ i*= 2; return i; };
	cout << "2i:" << two_i() << " i:" << i << endl;
    
    // lambda test 7
    // gorp class는 각 원소를 input으로 나눈 나머지를 더한 값을 return
    // 람다에서 어떻게 m_ 을 capture?
    // 람다는 여기서 암묵적으로 (implicit) 클래스의 this 를 Capture 했기 때문에 m_ 을 접근
    print_title(7);
    gorp g(4);
    g.put(3).put(7).put(8);
    g.print_val();
    cout << "extras: " << g.extras() << endl;
    
    
    
    return 0;
    
    
}




