#include "yahoo_finance_api/yahoo_finance_api.h"

#include "absl/log/check.h"
#include "absl/strings/str_cat.h"
#include "absl/strings/string_view.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"
#include "curl/curl.h"

namespace YahooFinanceAPI {

namespace {

size_t write_fn(void* buffer, size_t size, size_t num_memb,
                std::string& output) {
  size_t total_size = size * num_memb;
  output.append(static_cast<char*>(buffer), total_size);
  return total_size;
}

}  // namespace

constexpr int64_t day_duration = 24 * 60 * 60;

YahooFinanceAPI::YahooFinanceAPI() {
  ticker_ = "^GSPC";  // S&P 500
  start_time_ = absl::ToUnixSeconds(
      absl::Now() - absl::Duration(absl::Seconds(24 * 60 * 60)));
  end_time_ = absl::ToUnixSeconds(absl::Now());
  time_ = absl::Now();
}

YahooFinanceAPI::YahooFinanceAPI(absl::string_view ticker,
                                 const absl::Time& time) {
  ticker_ = ticker.data();
  start_time_ = absl::ToUnixSeconds(time) - day_duration;
  end_time_ = absl::ToUnixSeconds(time) + day_duration;
  time_ = time;
}

void YahooFinanceAPI::SetTicker(absl::string_view ticker) {
  ticker_ = ticker.data();
}

std::string YahooFinanceAPI::GetTicker() const { return ticker_; }

void YahooFinanceAPI::SetTime(const absl::Time& time) {
  time_ = time;
  start_time_ = absl::ToUnixSeconds(time) - day_duration;
  end_time_ = absl::ToUnixSeconds(time) + day_duration;
}

absl::Time YahooFinanceAPI::GetTime() const { return time_; }

std::string YahooFinanceAPI::Query() const {
  curl_global_init(CURL_GLOBAL_DEFAULT);

  CURL* curl = curl_easy_init();
  std::string file;
  CURLcode res;

  /*
  yfinance query format:
  https://query1.finance.yahoo.com/v7/finance/download/{ticker}?period1={start_time}&period2={end_time}&interval={interval}&events=history
  */

  std::string url =
      absl::StrCat("https://query1.finance.yahoo.com/v7/finance/download/",
                   ticker_, "?period1=", start_time_, "&period2=", end_time_,
                   "&interval=", interval_, "&events=history");

  CHECK_NE(curl, nullptr) << "Curl is not initialized!";

  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_fn);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &file);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curl, CURLOPT_ENCODING, "");
  // curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);

  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  CHECK_EQ(res, CURLE_OK) << "Curl result not okay! Curl result is : " << res;

  curl_global_cleanup();

  return file;
}

}  // namespace YahooFinanceAPI
