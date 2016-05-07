#include <iostream>
#include <string>
#include <map>

#define DATA_STRUCTURES

// Function prototypes

// Testing
void test(const std::string& s, bool expected);

// Functions to determine string uniqueness
bool is_unique(const std::string& s);
bool space_unique(const std::string& s);


// Processes strings via std::cin and determines
// whether they have all unique characters.
// Reports status to std::cout.
int main(int argc, char ** argv) { 
  // Unit test initially.
  test("this is a test", false);
  test("abc", true);
  test("abcdefghijklmnopqrstuv", true);
      
  for (;;) {
    std::string s, message;

    std::cout << "\%\%\% ";
    
    std::cin >> s;
    message = ((is_unique(s)) ? " is" : " is not");
    std::cout << s << message << " unique \n";
  }
  return 0;
}


// Tests the is_unique() and space_unique() functions.
void test(const std::string& s, bool expected) {
  bool unique = is_unique(s);
  bool space = space_unique(s);

  std::string output;

  if (unique == expected && space == expected) { 
    output = "Both functions passed.";
  } 
  else if (unique != expected && space == expected) {
    output = "is_unique() FAILED!";
  }
  else if (unique == expected && space != expected) {
    output = "space_unique() FAILED!";
  }
  else {
    output = "Both functions FAILED!";
  }

  std::cerr << "Input string: " << s << std::endl;
  std::cerr << output << std::endl;
}


// Determines if a string has unique characters.
// If the DATA_STRUCTURES macro is defined, uses a map<char, int>
// with O(n) time and space complexity. Otherwise, does a O(n^2) 
// search with no additional space.
bool is_unique(const std::string& s) { 

  #ifdef DATA_STRUCTURES
  std::map<char, int> char_map;
  for (int i = 0; i < s.length(); i++) { 
    if (char_map[s[i]]++ > 0) {
        return false;
    }
  }
  return true;

  #else // Solution when no data structures are allowed.
  return space_unique(s);
  #endif // DATA_STRUCTURES 

}


// Determines if a string has unique characters by a O(n^2) search
// that takes no additional space.
bool space_unique(const std::string& s) { 
  const int N = s.length();
  for (int i = 0; i < N; i++) { 
    for (int j = i + 1; j < N; j++) {
      if (s[i] == s[j]) { 
          return false;
      }
    }
  }
  return true;
}
