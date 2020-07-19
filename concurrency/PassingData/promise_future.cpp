#include <iostream>
#include <thread>
#include <future>

// Passing promise (rvalue reference)
// Cumbersome!!
void modifyMessage(std::promise<std::string> && prms, std::string message)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(4000)); // simulate work
    std::string modifiedMessage = message + " has been modified"; 
    prms.set_value(modifiedMessage);
}

int main()
{
    // define message
    std::string messageToThread = "My Message";

    // create promise and future
    std::promise<std::string> prms;
    std::future<std::string> ftr = prms.get_future();

    // start thread and pass promise as argument
    // promises can't be copied
    std::thread t(modifyMessage, std::move(prms), messageToThread);

    // print original message to console
    std::cout << "Original message from main(): " << messageToThread << std::endl;

    auto status = ftr.wait_for(std::chrono::milliseconds(1000));
    if (status == std::future_status::ready) {
        // retrieve modified message via future and print to console
        // this will block the main thread, get() can only be called once
        std::string messageFromThread = ftr.get();
        std::cout << "Modified message from thread(): " << messageFromThread << std::endl;
    } else if (status == std::future_status::timeout || status == std::future_status::deferred) {
        std::cout << "Result unavailable" << std::endl;
    }

    // thread barrier
    t.join();

    return 0;
}
