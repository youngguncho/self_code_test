#include <iostream>
#include <thread>

void thread_function()
{
    std::cout << "thread function" << std::endl; 
}

int main ()
{
    std::thread t(&thread_function); // t start running
    std::cout << "main thread" << std::endl;
    t.join(); // main thread waits for the thread t to finish
    return 0;
}
