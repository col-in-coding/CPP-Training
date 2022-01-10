cc_binary(
  name = "hello_world",
  deps = ["@com_google_absl//absl/strings"],
  srcs = ["hello_world.cc"]
)

cc_binary(
  name = "print_my_pb",
  deps = ["//proto:addressbook_cc_proto"],
  srcs = ["print_my_pb.cc"]
)

cc_binary(
  name = "main_logger",
  srcs = ["main_logger.cc"],
  deps = [
    "@com_google_absl//absl/strings",
    "@com_github_google_glog//:glog"
  ],
)

cc_library(
  name = "utils",
  srcs = ["utils.cc"],
  hdrs = ["utils.h"],
  visibility = ["//visibility:public"],
)