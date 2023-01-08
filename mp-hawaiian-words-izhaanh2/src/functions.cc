#include "functions.hpp"
// Your function definitions should go in this source file.

// Replaces a word with its Hawaiian pronounciation
std::string Replace(std::string input) {
  input = WordLower(input);
  if (!CheckWordHawaiian(input)) {
    return input + " contains a character not a part of the Hawaiian language.";
  }
  std::string pronounciation;
  std::string temp_str;
  for (unsigned int i = 0; i < input.length(); ++i) {
    if (CheckConsonant(input.at(i))) {
      if (i != 0 && input.at(i) == 'w' &&
          (input.at(i - 1) == 'i' || input.at(i - 1) == 'e')) {
        pronounciation.push_back(ReplaceCons("wie"));
      } else {
        pronounciation.push_back(ReplaceCons(std::string(1, input.at(i))));
      }
    } else if (CheckVowel(input.at(i))) {
      temp_str = "";
      if (i != input.length() - 1) {
        temp_str.push_back(input.at(i));
        temp_str.push_back(input.at(i + 1));
      }
      if (CheckVG(temp_str)) {
        pronounciation = PushBackWord(pronounciation, ReplaceVG(temp_str));
        ++i;
      } else {
        pronounciation = PushBackWord(
            pronounciation, ReplaceVowel(std::string(1, input.at(i))));
      }
      if (i != input.length() - 1 && input.at(i + 1) != ' ' &&
          input.at(i + 1) != '\'') {
        pronounciation.push_back('-');
      }
    } else {
      pronounciation.push_back(input.at(i));
    }
  }
  return pronounciation;
}

// Checks if passed word is all Hawaiian letters
bool CheckWordHawaiian(std::string input) {
  bool check = true;
  for (unsigned int i = 0; i < input.length(); ++i) {
    if (!CheckCharHawaiian(input.at(i))) {
      check = false;
    }
  }
  return check;
}

// Checks if passed letter is in Hawaiian alphabet
bool CheckCharHawaiian(char input) {
  std::vector<char> hawaiian_letters{
      'a', 'e', 'i', 'o', 'u', 'p', 'k', 'h', 'l', 'm', 'n', 'w', ' ', '\''};
  bool check = false;
  for (unsigned int i = 0; i < hawaiian_letters.size(); ++i) {
    if (hawaiian_letters.at(i) == input) {
      check = true;
    }
  }
  return check;
}

// Checks if passed character is a consonant
bool CheckConsonant(char input) {
  std::vector<char> consonants{'p', 'k', 'h', 'l', 'm', 'n', 'w'};
  bool check = false;
  for (unsigned int i = 0; i < consonants.size(); ++i) {
    if (consonants.at(i) == input) {
      check = true;
    }
  }
  return check;
}

// Checks if passed character is a vowel
bool CheckVowel(char input) {
  std::vector<char> vowels{'a', 'e', 'i', 'o', 'u'};
  bool check = false;
  for (unsigned int i = 0; i < vowels.size(); ++i) {
    if (vowels.at(i) == input) {
      check = true;
    }
  }
  return check;
}

// Checks if passed string is a vowel group
bool CheckVG(const std::string& vgInput) {
  std::map<std::string, std::string> vowel_groups;

  vowel_groups.insert(std::pair<std::string, std::string>("ai", "eye"));
  vowel_groups.insert(std::pair<std::string, std::string>("ae", "eye"));
  vowel_groups.insert(std::pair<std::string, std::string>("ao", "ow"));
  vowel_groups.insert(std::pair<std::string, std::string>("au", "ow"));
  vowel_groups.insert(std::pair<std::string, std::string>("ei", "ay"));
  vowel_groups.insert(std::pair<std::string, std::string>("eu", "eh-oo"));
  vowel_groups.insert(std::pair<std::string, std::string>("iu", "ew"));
  vowel_groups.insert(std::pair<std::string, std::string>("oi", "oy"));
  vowel_groups.insert(std::pair<std::string, std::string>("ou", "ow"));
  vowel_groups.insert(std::pair<std::string, std::string>("ui", "ooey"));

  return vowel_groups.contains(vgInput);
}

// Makes word lowercase
std::string WordLower(std::string input) {
  std::string temp;
  for (unsigned int i = 0; i < input.length(); ++i) {
    temp.push_back(tolower(input.at(i)));
  }
  return temp;
}

// Replaces a vowel group with the correct pronounciation
std::string ReplaceVG(const std::string& input) {
  std::map<std::string, std::string> vowel_groups;

  vowel_groups.insert(std::pair<std::string, std::string>("ai", "eye"));
  vowel_groups.insert(std::pair<std::string, std::string>("ae", "eye"));
  vowel_groups.insert(std::pair<std::string, std::string>("ao", "ow"));
  vowel_groups.insert(std::pair<std::string, std::string>("au", "ow"));
  vowel_groups.insert(std::pair<std::string, std::string>("ei", "ay"));
  vowel_groups.insert(std::pair<std::string, std::string>("eu", "eh-oo"));
  vowel_groups.insert(std::pair<std::string, std::string>("iu", "ew"));
  vowel_groups.insert(std::pair<std::string, std::string>("oi", "oy"));
  vowel_groups.insert(std::pair<std::string, std::string>("ou", "ow"));
  vowel_groups.insert(std::pair<std::string, std::string>("ui", "ooey"));

  return vowel_groups.at(input);
}

// Replaces a vowel with the correct prounounciation
std::string ReplaceVowel(const std::string& input) {
  std::map<std::string, std::string> vowels;

  vowels.insert(std::pair<std::string, std::string>("a", "ah"));
  vowels.insert(std::pair<std::string, std::string>("e", "eh"));
  vowels.insert(std::pair<std::string, std::string>("i", "ee"));
  vowels.insert(std::pair<std::string, std::string>("o", "oh"));
  vowels.insert(std::pair<std::string, std::string>("u", "oo"));

  return vowels.at(input);
}

// Replaces a consonant with the correct pronounciation
char ReplaceCons(const std::string& input) {
  std::map<std::string, char> consonants;

  consonants.insert(std::pair<std::string, char>("p", 'p'));
  consonants.insert(std::pair<std::string, char>("k", 'k'));
  consonants.insert(std::pair<std::string, char>("h", 'h'));
  consonants.insert(std::pair<std::string, char>("l", 'l'));
  consonants.insert(std::pair<std::string, char>("m", 'm'));
  consonants.insert(std::pair<std::string, char>("n", 'n'));
  consonants.insert(std::pair<std::string, char>("w", 'w'));
  consonants.insert(std::pair<std::string, char>("wie", 'v'));

  return consonants.at(input);
}

std::string PushBackWord(std::string input1, std::string input2) {
  for (unsigned int i = 0; i < input2.length(); i++) {
    input1.push_back(input2.at(i));
  }
  return input1;
}
