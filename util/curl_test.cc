#include "util/curl.h"

#include "absl/strings/match.h"
#include "gtest/gtest.h"

namespace util {
namespace {

TEST(CurlTest, YahooFinanceHTML) {
  std::string url = "https://finance.yahoo.com/quote/GOOG";

  std::string res = Curl(url);
  EXPECT_TRUE(absl::StrContains(res, "html")) << "Result is: " << res;
  EXPECT_TRUE(absl::StrContains(
      res, '<link rel="preconnect" href="//query1.finance.yahoo.com">')) << "Result is: " << res;
}

TEST(CurlTest, YahooFinanceCSV) {
  std::string url =
      "https://query1.finance.yahoo.com/v7/finance/download/GOOG?period1=1714003200&period2=1714176000&interval=1d&events=history&includeAdjustedClose=true";

  std::string res = Curl(url);
  EXPECT_TRUE(absl::StrContains(res, "173.69")) << "Result is: " << res;
}

// Testing same test second time to see if SSL connection has errors.
TEST(CurlTest, YahooFinanceCSV2) {
  std::string url =
      "https://query1.finance.yahoo.com/v7/finance/download/GOOG?period1=1714003200&period2=1714176000&interval=1d&events=history&includeAdjustedClose=true";

  std::string res = Curl(url);
  EXPECT_TRUE(absl::StrContains(res, "173.69")) << "Result is: " << res;
}

}  // namespace
}  // namespace util
