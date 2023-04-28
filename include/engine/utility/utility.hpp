#ifndef UTILITY_H
#define UTILITY_H
#include <cctype>

// Returns the hash value of string input, for switchs on std::string
//
// Stack Overflow solution for C++ string switch statements
// C++17 (claimed)
constexpr uint32_t hash(const std::string_view data) noexcept {   uint32_t hash = 5385;    for (const auto &e : data)     hash = ((hash << 5) + hash) + e;    return hash; }
//
// Stack Overflow syntax sugar for C++ string switch statements
constexpr inline unsigned int operator "" _(char const * p, size_t) { return hash(p); }
//

//
// Wrapper for std::tolower, modifies the string in-place
constexpr void lowercase(std::string& str) noexcept {    for (auto& c : str)    c = std::tolower(c); }
// Wrapper for std::toupper, modifies the string in-place
constexpr void uppercase(std::string& str) noexcept {    for (auto& c : str)    c = std::toupper(c); }
//

#endif