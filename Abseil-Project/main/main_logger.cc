#include <glog/logging.h>
#include <vector>
#include "absl/strings/str_join.h"

int main(int argc, char const *argv[])
{
    FLAGS_logtostderr = true;
    FLAGS_minloglevel = 0;
    google::InitGoogleLogging(argv[0]);

    LOG(INFO) << "Hello " << "Colin";

    std::vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    LOG(INFO) << absl::StrJoin(a, ", ");
    return 0;
}
