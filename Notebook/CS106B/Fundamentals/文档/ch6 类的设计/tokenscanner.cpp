/*
 * File: tokenscanner.cpp
 * ----------------------
 * This file implements the TokenScanner class.  Most of the methods
 * are straightforward enough to require no additional documentation.
 */

#include <cctype>
#include <string>
#include "tokenscanner.h"
using namespace std;

TokenScanner::TokenScanner() {
   setInput("");
}

TokenScanner::TokenScanner(string str) {
   setInput(str);
}

void TokenScanner::setInput(string str) {
   buffer = str;
   cp = 0;
}

bool TokenScanner::hasMoreTokens() {
   return cp < buffer.length();
}

/*
 * Implementation notes: nextToken
 * -------------------------------
 * This method starts by looking at the character indicated by the index
 * cp.  If that index is past the end of the string, nextToken returns
 * the empty string.  If that character is alphanumeric, nextToken scans
 * ahead until it finds the end of that word; if not, nextToken returns
 * that character as a one-character string.
 */

string TokenScanner::nextToken() {
   if (cp >= buffer.length()) {
      return "";
   } else if (isalnum(buffer[cp])) {
      int start = cp;
      while (cp < buffer.length() && isalnum(buffer[cp])) {
         cp++;
      }
      return buffer.substr(start, cp - start);
   } else {
      return string(1, buffer[cp++]);
   }
}
