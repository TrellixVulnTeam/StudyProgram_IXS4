﻿#ifndef CHECK_H_
#define CHECK_H_

#include <cstdlib>
#include <ostream>

#include "internal_macros.h"
#include "log.h"

namespace benchmark {
namespace internal {

// CheckHandler is the class constructed by failing CHECK macros. CheckHandler
// will log information about the failures and abort when it is destructed.
class CheckHandler {
public:
  CheckHandler(const char* check, const char* file, const char* func, int line)
    : log_(GetErrorLogInstance())
  {
    log_ << file << ":" << line << ": " << func << ": Check `"
          << check << "' failed. ";
  }

  std::ostream& GetLog() {
    return log_;
  }

  BENCHMARK_NORETURN ~CheckHandler() {
      log_ << std::endl;
      std::abort();
  }

  CheckHandler & operator=(const CheckHandler&) = delete;
  CheckHandler(const CheckHandler&) = delete;
  CheckHandler() = delete;
private:
  std::ostream& log_;
};

} // end namespace internal
} // end namespace benchmark

// The CHECK macro returns a std::ostream object that can have extra information
// written to it.
#ifndef NDEBUG
# define CHECK(b)  (b ? ::benchmark::internal::GetNullLogInstance()        \
                      : ::benchmark::internal::CheckHandler(               \
                          #b, __FILE__, __func__, __LINE__).GetLog())
#else
# define CHECK(b) ::benchmark::internal::GetNullLogInstance()
#endif

#define CHECK_EQ(a, b) CHECK((a) == (b))
#define CHECK_NE(a, b) CHECK((a) != (b))
#define CHECK_GE(a, b) CHECK((a) >= (b))
#define CHECK_LE(a, b) CHECK((a) <= (b))
#define CHECK_GT(a, b) CHECK((a) > (b))
#define CHECK_LT(a, b) CHECK((a) < (b))

#endif  // CHECK_H_
