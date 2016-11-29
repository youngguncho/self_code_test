#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex mu;

void shared_cout(std::string msg, int id)
{
	mu.lock();
	std::cout << msg << ":" << id << std::endl;
	mu.unlock();
}
void thread_function()
{
	for (int i = -100; i < 0; i++)
		shared_cout("thread function", i);
}

int main()
{
	std::thread t(&thread_function);
	for (int i = 100; i > 0; i--)
	    shared_cout("main thread", i);
	t.join();
	return 0;
}
