﻿// Copyright 2015 Google Inc. All rights reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#ifndef BENCHMARK_MACROS_H_
#define BENCHMARK_MACROS_H_

#if __cplusplus < 201103L
# define BENCHMARK_DISALLOW_COPY_AND_ASSIGN(TypeName)  \
    TypeName(const TypeName&);                         \
    TypeName& operator=(const TypeName&)
#else
# define BENCHMARK_DISALLOW_COPY_AND_ASSIGN(TypeName)  \
    TypeName(const TypeName&) = delete;                \
    TypeName& operator=(const TypeName&) = delete
#endif

#if defined(__GNUC__)
# define BENCHMARK_UNUSED __attribute__((unused))
# define BENCHMARK_ALWAYS_INLINE __attribute__((always_inline))
# define BENCHMARK_NOEXCEPT noexcept
#elif defined(_MSC_VER) && !defined(__clang__)
# define BENCHMARK_UNUSED
# define BENCHMARK_ALWAYS_INLINE __forceinline
# define BENCHMARK_NOEXCEPT
# define __func__ __FUNCTION__
#else
# define BENCHMARK_UNUSED
# define BENCHMARK_ALWAYS_INLINE
# define BENCHMARK_NOEXCEPT
#endif

#if defined(__GNUC__)
# define BENCHMARK_BUILTIN_EXPECT(x, y) __builtin_expect(x, y)
#else
# define BENCHMARK_BUILTIN_EXPECT(x, y) x
#endif

#endif  // BENCHMARK_MACROS_H_
