#include "util/curl.h"

#include <string>

#include "absl/log/check.h"
#include "absl/log/log.h"
#include "absl/strings/string_view.h"
#include "curl/curl.h"

namespace util {

size_t CurlWriteFn(char* buffer, size_t size, size_t num_membs,
                   std::string& output) {
  size_t total_size = size * num_membs;
  output.append(buffer, total_size);
  return total_size;
}

std::string Curl(absl::string_view url) {
  curl_global_init(CURL_GLOBAL_DEFAULT);

  CURL* curl = curl_easy_init();
  CHECK_NE(curl, nullptr) << "Curl is not initialized!";

  std::string output = "";

  curl_easy_setopt(curl, CURLOPT_URL, url.data());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteFn);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &output);
  curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
  curl_easy_setopt(curl, CURLOPT_ENCODING, "");

  CURLcode res = curl_easy_perform(curl);
  CHECK_EQ(res, CURLE_OK) << "Curl result is not okay. Curl result is: " << res;

  curl_easy_cleanup(curl);
  curl_global_cleanup();

  return output;
}

}  // namespace util
