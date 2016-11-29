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
//    t.join(); // main thread waits for the thread t to finish
    t.detach();     
    // Note that the detached thread didn't have a change to print its output to stdout because the main thread already finished and exited. This is one of the characteristics of multithreaded programming: we cannot be sure which thread runs first
    return 0;

}
