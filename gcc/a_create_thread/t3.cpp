#include <iostream>
#include <thread>
#include <string>

using namespace std;

class MyFunctor
{
  public:
    void operator()() {
        cout << "functor" << endl;
    }
};

int main ()
{
    MyFunctor functor;
    thread t(functor);
    // or thread t((MyFunctor)) not thread t(MyFunctor)
    cout << "main thread" << endl;
    t.join();

    return 0;

}
