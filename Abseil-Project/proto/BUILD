load("@rules_cc//cc:defs.bzl", "cc_library")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cc_proto_library(
    name = "addressbook_cc_proto",
    deps = [":addressbook_proto"]
)

proto_library(
    name = "addressbook_proto",
    srcs = ["addressbook.proto"],
    deps = [
        ":person_proto"
    ]
)

proto_library(
    name = "person_proto",
    srcs = [
        "person.proto"
    ]
)