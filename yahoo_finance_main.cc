#include <iostream>

#include "yahoo_finance_api/yahoo_finance_api.h"

int main() {
  YahooFinanceAPI::YahooFinanceAPI client =
      YahooFinanceAPI::YahooFinanceAPI("GOOG");

  std::string file = client.Query();

  std::cout << "Output:\n";
  std::cout << file << "\n";
}
