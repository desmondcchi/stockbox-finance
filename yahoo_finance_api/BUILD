package(default_visibility = ["//visibility:public"])

cc_library(
    name = "yahoo_finance_api",
    srcs = ["yahoo_finance_api.cc"],
    hdrs = ["yahoo_finance_api.h"],
    linkopts = [
        "-lcurl",
    ],
    deps = [
        "@com_google_absl//absl/log:check",
        "@com_google_absl//absl/strings:string_view",
        "@com_google_absl//absl/time",
    ],
)

cc_test(
    name = "yahoo_finance_api_test",
    srcs = ["yahoo_finance_api_test.cc"],
    deps = [
        ":yahoo_finance_api",
        "@com_google_absl//absl/strings:str_format",
        "@com_google_gtest//:gtest_main",
    ],
)
