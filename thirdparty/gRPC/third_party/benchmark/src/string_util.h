﻿#ifndef BENCHMARK_STRING_UTIL_H_
#define BENCHMARK_STRING_UTIL_H_

#include <sstream>
#include <string>
#include <utility>
#include "internal_macros.h"

namespace benchmark {

void AppendHumanReadable(int n, std::string* str);

std::string HumanReadableNumber(double n);

std::string StringPrintF(const char* format, ...);

inline std::ostream& StringCatImp(std::ostream& out) BENCHMARK_NOEXCEPT {
  return out;
}

template <class First, class... Rest>
inline std::ostream& StringCatImp(std::ostream& out, First&& f,
                                  Rest&&... rest) {
  out << std::forward<First>(f);
  return StringCatImp(out, std::forward<Rest>(rest)...);
}

template <class... Args>
inline std::string StrCat(Args&&... args) {
  std::ostringstream ss;
  StringCatImp(ss, std::forward<Args>(args)...);
  return ss.str();
}

void ReplaceAll(std::string* str, const std::string& from,
                const std::string& to);

}  // end namespace benchmark

#endif  // BENCHMARK_STRING_UTIL_H_
