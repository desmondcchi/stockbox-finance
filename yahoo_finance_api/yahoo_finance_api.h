#ifndef YAHOO_FINANCE_API_YAHOO_FINANCE_API_H_
#define YAHOO_FINANCE_API_YAHOO_FINANCE_API_H_

#include <string>

#include "absl/strings/string_view.h"
#include "absl/time/clock.h"
#include "absl/time/time.h"

namespace YahooFinanceAPI {

class YahooFinanceAPI {
 public:
  /**
   * @brief Constructor.
   *
   */
  YahooFinanceAPI();

  /**
   * @brief Constructor.
   *
   * @param ticker Name of ticker symbol.
   * @param time Time for retrieving ticker information.
   */
  YahooFinanceAPI(absl::string_view ticker,
                  const absl::Time& time = absl::Now());

  /**
   * @brief Set ticker symbol.
   *
   *
   * @param ticker Name of ticker symbol.
   */
  void SetTicker(absl::string_view ticker);

  /**
   * @brief Get name of ticker symbol.
   *
   *
   * @return Name of ticker symbol.
   */
  std::string GetTicker() const;

  /**
   * @brief Set time for retrieving ticker information.
   *
   *
   * @param time Time for retrieving ticker information.
   */
  void SetTime(const absl::Time& time);

  /**
   * @brief Get time for retrieving ticker information.
   *
   *
   * @return Time for retrieving ticker information.
   */
  absl::Time GetTime() const;

  /**
   * @brief Queries Yahoo Finance for information about the given ticker symbol
   * and time.
   *
   *
   * @return CSV of stock information in string format.
   */
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
