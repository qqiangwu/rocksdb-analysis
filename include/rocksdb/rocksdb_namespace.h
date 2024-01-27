// Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
//  This source code is licensed under both the GPLv2 (found in the
//  COPYING file in the root directory) and Apache 2.0 License
//  (found in the LICENSE.Apache file in the root directory).

#pragma once

// For testing purposes
#if ROCKSDB_NAMESPACE == 42
#undef ROCKSDB_NAMESPACE
#endif

// Normal logic
#ifndef ROCKSDB_NAMESPACE
#define ROCKSDB_NAMESPACE rocksdb
#endif

constexpr int Return = 0;
constexpr int Global = 1;
constexpr int Null = 2;
constexpr int Invalid = 3;

// IWYU pragma: private
#define CPPSAFE_SUPPRESS_LIFETIME [[gsl::suppress("lifetime")]]

// IWYU pragma: private
#define CPPSAFE_LIFETIME_IN [[clang::annotate("gsl::lifetime_in")]]

// IWYU pragma: private
#define CPPSAFE_LIFETIME_INOUT [[clang::annotate("gsl::lifetime_inout")]]

// IWYU pragma: private
#define CPPSAFE_LIFETIME_CONST [[clang::annotate("gsl::lifetime_const")]]

// IWYU pragma: private
#define CPPSAFE_REINITIALIZES [[clang::reinitializes]]

// IWYU pragma: private
#define CPPSAFE_PRE(...) [[clang::annotate("gsl::lifetime_pre", __VA_ARGS__)]]

// IWYU pragma: private
#define CPPSAFE_POST(...) [[clang::annotate("gsl::lifetime_post", __VA_ARGS__)]]

// IWYU pragma: private
template <class T>
void __lifetime_contracts(T&&) {}

// IWYU pragma: private
template <class T>
void __lifetime_type_category_arg(T&&) {}

// IWYU pragma: private
template <class T>
void __lifetime_pset(T&&) {}

// IWYU pragma: private
void __lifetime_pmap();
