#include <iostream>
#include <thread>
#include <string>


void thread_function(std::string &s)
{
    std::cout << "thread function ";
    std::cout << "message is = " << s << std::endl;
    s = "Justin Beaver";
}


int main ()
{
    std::string s = "Kathy Perry";
    std::thread t(&thread_function, std::ref(s));
    std::cout << "main thread message = " << s << std::endl;
    std::cout << "main thread id = " << std::this_thread::get_id() << std::endl;
    std::cout << "child thread id = " << t.get_id() << std::endl;
    std::cout << "Number of threads = " 
              <<  std::thread::hardware_concurrency() << std::endl;
    t.join();
    std::cout << "main thread message = " << s << std::endl;
    
    return 0;
}
