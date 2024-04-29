package(default_visibility = ["//visibility:public"])

cc_library(
    name = "curl",
    srcs = ["curl.cc"],
    hdrs = ["curl.h"],
    linkopts = ["-lcurl"],
    deps = [
        "@com_google_absl//absl/log",
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings:string_view",
    ],
)

cc_test(
    name = "curl_test",
    srcs = ["curl_test.cc"],
    deps = [
        ":curl",
        "@com_google_gtest//:gtest_main",
    ],
)
