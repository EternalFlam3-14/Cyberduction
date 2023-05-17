#ifndef UTILITY_H
#define UTILITY_H
#include <cctype>
#include <string_view>
#include <bit>

// Returns the hash value of string input, for switchs on std::string
//
constexpr uint32_t hash(std::string_view data) noexcept {   uint32_t hash = 5385;    for (auto &c : data)    hash = std::rotl(hash, 5) + c;    return hash; }
//
// Stack Overflow syntax sugar for C++ string switch statements
constexpr inline unsigned int operator "" _(char const * p, size_t) { return hash(p); }
//

//
// Wrapper for std::tolower, modifies the string in-place
constexpr inline void lowercase(std::string &str) noexcept {    for (auto &c : str)    c = std::tolower(c); }
// Wrapper for std::toupper, modifies the string in-place
constexpr inline void uppercase(std::string &str) noexcept {    for (auto &c : str)    c = std::toupper(c); }
//



#endif