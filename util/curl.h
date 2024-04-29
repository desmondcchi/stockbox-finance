#ifndef UTIL_CURL_H_
#define UTIL_CURL_H_

#include <string>

#include "absl/strings/string_view.h"

namespace util {

/**
 * @brief Write function for Curl.
 * @param buffer Input buffer.
 * @param size Size of input data.
 * @param num_membs Number of members.
 * @param output String to store the output of the curl.
 * @return Size of the data.
 */
size_t CurlWriteFn(char* buffer, size_t size, size_t num_membs,
                   std::string& output);

/**
 * @brief Use curl on a given URL to retrieve the data.
 * @param url URL of webpage to be curled.
 * @return Output of the data.
 */
std::string Curl(absl::string_view url);

}  // namespace util

#endif
