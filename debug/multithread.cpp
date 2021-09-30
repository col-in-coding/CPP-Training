/*
 Basic Command Line Instructions
 g++ -pthread -g multithread.cpp -o multithread
 gdb multithread
 
 gdb commands:
 b or break multithread.cpp:30 // create a break point
 r or run
 i threads // show threads
 bt full // display backetrace
 thread thread-id // checkin a thread
 set scheduler-locking on // run this thread only
 c
*/

#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

std::mutex g_display_mutex;

void task()
{
    int i = 0;
    while (1)
    {
        std::thread::id this_id = std::this_thread::get_id();

        g_display_mutex.lock();
        std::cout << "thread " << this_id << " num: " << i++ << std::endl;
        g_display_mutex.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main()
{
    std::thread t1(task);
    std::thread t2(task);

    for (size_t i = 0; i < 100; i++)
    {
        std::cout << "Main : " << i << std::endl;
    }
    
    t1.join();
    t2.join();
    return 0;
}