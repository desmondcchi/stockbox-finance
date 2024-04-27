#ifndef YAHOO_FINANCE_API_YAHOO_FINANCE_API_H_
#define YAHOO_FINANCE_API_YAHOO_FINANCE_API_H_

#include <string>

#include "absl/strings/string_view.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

namespace YahooFinanceAPI {

class YahooFinanceAPI {
 public:
  YahooFinanceAPI();
  YahooFinanceAPI(absl::string_view ticker, const absl::Time& time = absl::Now());
  void SetTicker(absl::string_view ticker);
  std::string GetTicker() const;
  void SetTime(const absl::Time& time);
  absl::Time GetTime() const;
  std::string Query() const;

 private:
  std::string ticker_;
  int64_t start_time_;
  int64_t end_time_;
  absl::Time time_;
  std::string interval_ = "1d";
};

}  // namespace YahooFinanceAPI

#endif
