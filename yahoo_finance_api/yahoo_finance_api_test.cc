#include "yahoo_finance_api/yahoo_finance_api.h"

#include "absl/strings/match.h"
#include "gtest/gtest.h"

namespace YahooFinanceAPI {
namespace {

TEST(YahooFinanceAPITest, DefaultConstructor) {
  YahooFinanceAPI client = YahooFinanceAPI();

  EXPECT_STREQ(client.GetTicker().c_str(), "^GSPC");
}

TEST(YahooFinanceAPITest, GOOGTest) {
  YahooFinanceAPI client = YahooFinanceAPI(
      "GOOG",
      absl::FromCivil(absl::CivilDay(2024, 4, 26), absl::LocalTimeZone()));

  EXPECT_STREQ(client.GetTicker().c_str(), "GOOG");

  std::string res = client.Query();
  EXPECT_TRUE(absl::StrContains(res, "173.69"));
}

// Testing same test second time to test if SSL connection has errors.
TEST(YahooFinanceAPITest, GOOGTest2) {
  YahooFinanceAPI client = YahooFinanceAPI(
      "GOOG",
      absl::FromCivil(absl::CivilDay(2024, 4, 26), absl::LocalTimeZone()));

  EXPECT_STREQ(client.GetTicker().c_str(), "GOOG");

  std::string res = client.Query();
  EXPECT_TRUE(absl::StrContains(res, "173.69"));
}

}  // namespace
}  // namespace YahooFinanceAPI
