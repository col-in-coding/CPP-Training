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
        ":person_proto",
        # Well known protos should be included as deps in the
        # proto_library rules of the source files importing them.
        # A list of all @com_google_protobuf well known protos can
        # seen with:
        # `bazel query 'kind(proto_library, @com_google_protobuf//:all)'`
        "@com_google_protobuf//:any_proto",
    ]
)

proto_library(
    name = "person_proto",
    srcs = ["person.proto"]
)