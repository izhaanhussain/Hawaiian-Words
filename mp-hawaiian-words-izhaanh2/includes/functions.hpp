#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cctype>
#include <map>
#include <string>
#include <vector>

// Your function declarations should go in this header file.

bool CheckCharHawaiian(char input);

bool CheckWordHawaiian(std::string input);

bool CheckConsonant(char input);

bool CheckVowel(char input);

bool CheckVG(const std::string& vgInput);

std::string WordLower(std::string input);

std::string PushBackWord(std::string input1, std::string input2);

std::string ReplaceVG(const std::string& input);

std::string ReplaceVowel(const std::string& input);

char ReplaceCons(const std::string& input);

std::string Replace(std::string input);

#endif