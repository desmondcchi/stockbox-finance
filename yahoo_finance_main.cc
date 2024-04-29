#include <iostream>

#include "yahoo_finance_api/yahoo_finance_api.h"

int main() {
  YahooFinanceAPI::YahooFinanceAPI client = YahooFinanceAPI::YahooFinanceAPI(
      "GOOG",
      absl::FromCivil(absl::CivilDay(2024, 4, 26), absl::LocalTimeZone()));

  std::string file = client.Query();

  std::cout << "Output:\n";
  std::cout << file << "\n";
}
