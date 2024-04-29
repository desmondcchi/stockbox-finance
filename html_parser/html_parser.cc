#include "html_parser/html_parser.h"

#include <string>

#include "absl/strings/string_view.h"

namespace HTMLParser {

HTMLParser::HTMLParser(absl::string_view url) : url_(url){};

void HTMLParser::GetHTML() {}

std::string HTMLParser::GetURL() const { return url_; }

std::string HTMLParser::Parse(absl::string_view attribute_type,
                              absl::string_view attribute_value) {
  return "";
}

}  // namespace HTMLParser
