#include <glog/logging.h>
#include <vector>
#include "absl/strings/str_join.h"

int main(int argc, char const *argv[])
{
    // This Flag will disable logging to file and print in the terminal
    FLAGS_logtostderr = true;
    // FLAGS_log_dir = "/mnt/d/Github/CPP-Training/Abseil-Project/data/log";
    // 0 - INFO; 1 - WARNING; 2 - ERROR;
    FLAGS_minloglevel = 1;
    google::InitGoogleLogging(argv[0]);

    LOG(INFO) << "Hello " << "Colin";

    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    LOG(INFO) << "DEBUG vector: " << absl::StrJoin(a, ", ");
    LOG(WARNING) << "WARNING MSG";
    LOG(ERROR) << "ERROR MSG";
    return 0;
}
