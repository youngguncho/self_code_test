#include <iostream>
#include <thread>
#include <string>


int main()
{
    std::thread t([]()
    {
        std::cout << "thread function\n";
    }
    );
    std::cout << "main thread\n";
    t.join();     // main thread waits for t to finish
    return 0;
    
    // Note that we are writing inline code and passing into another function which is a thread constructor. The lambda expression is a series of statements enclosed in braces, prefixed with [], called lambda introducer or capture specification which tells the compiler we're creating a lambda function, in our case, taking no argument. So, in essence, we're using [](){} as a task, and assigning it to our thread.
}
