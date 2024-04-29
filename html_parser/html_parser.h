#ifndef HTML_PARSER_HTML_PARSER_H_
#define HTML_PARSER_HTML_PARSER_H_

#include <string>

#include "absl/strings/string_view.h"

namespace HTMLParser {

class HTMLParser {
 public:
  HTMLParser() = delete;

  /**
   * @brief Constructor for HTML parser.
   *
   * @param url URL of webpage to retrieve its HTML.
   */
  HTMLParser(absl::string_view url);

  /**
   * @brief Retrieves the HTML of the webpage and stores in private member.
   */
  void GetHTML();

  /**
   * @brief Get the URL the HTML parser is set to.
   */
  std::string GetURL() const;

  /**
   * @brief Parse the given webpage and search for the specific attribute type
   * and attribute value (e.g. search for jsname="taco", where `attribute_type`
   * = "jsname" and `attribute_value` = "taco").
   *
   * @param attribute_type (e.g. class, id, href, alt, src, etc.)
   * @param attribute_value Attribute value.
   * @return
   */
  std::string Parse(absl::string_view attribute_type,
                    absl::string_view attribute_value);

 private:
  std::string url_;
  std::string html_;
  std::string res_;
};

}  // namespace HTMLParser

#endif
