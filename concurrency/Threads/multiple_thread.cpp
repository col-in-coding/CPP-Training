#include <iostream>
#include <thread>
#include <vector>

void printHello()
{
    // perform work
    std::cout << "Hello from Worker thread #" << std::this_thread::get_id() << std::endl;
}

/**
 * 1. The order in which threads are executed is non-deterministic. 
 * Every time a program is executed, there is a chance for a completely 
 * different order of execution.
 * 
 * 2. Threads may get preempted in the middle of execution and 
 * another thread may be selected to run.
 */

int main()
{
    // create threads
    std::vector<std::thread> threads;
    for (size_t i = 0; i < 5; ++i)
    {
        // 1. copying thread objects causes a compile error
        /*
        std::thread t(printHello);
        threads.push_back(t); 
        */

        // 2. moving thread objects will work
        // threads.emplace_back(std::thread(printHello));


        // 3. create new thread from a Lambda
        // prevent the interleaving of text on the command line 
        threads.emplace_back([i]() {

            // wait for certain amount of time
            std::this_thread::sleep_for(std::chrono::milliseconds(10 * i));

            // perform work
            std::cout << "Hello from Worker thread #" << i << std::endl;
        });
    }




    // do something in main()
    std::cout << "Hello from Main thread #" << std::this_thread::get_id() << std::endl;

    // call join on all thread objects using a range-based loop
    for (auto &t : threads)
        t.join();

    return 0;
}
