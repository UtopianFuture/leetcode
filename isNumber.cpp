#include <bits/stdc++.h>
// #include "../dbg.hpp"
using namespace std;
#define REOPEN_READ freopen("/home/guanshun/GDB/cpp/input.txt", "r", stdin);

/*
class Solution {
public:
  bool isInt(string s) {
    int size = s.size();
    int i = 0;
    if (s[i] == '-' || s[i] == '+') {
      i++;
    } else if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
      return false;
    }

    for (; i < size; i++) {
      if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
        return false;
      }
    }
    return true;
  }

  bool isDec(string s) {
    int size = s.size();
    int i = 0;
    if (s[i] == '-' || s[i] == '+') {
      i++;
    } else if (s[i] == '.') {
    } else if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
      return false;
    }

    for (; i < size; i++) {
      if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
        // do nothing
      } else if (s[i] == '.') {
        // after '.' must be number
        for (; i < size; i++) {
          if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
            return false;
          }
        }
      } else {
        // not '.' or numbers, return false
        return false;
      }
      // the last number, return true
      if (i == size - 1) {
        return true;
      }
    }
    return false;
  }

  bool isNumber(string s) {
    string tmp_dec, tmp_int;
    int size = s.size();
    int i = 0;
    for (int j = 0; j < size; j++) {
      if (s[j] == ' ')
        i++;
    }

    for (; i < size; i++) {
      tmp_dec.push_back(s[i]);
      tmp_int.push_back(s[i]);
      if (s[i + 1] == 'e' || s[i + 1] == 'E' || i == size - 1 ||
          s[i + 1] == ' ') {
        if (!(isDec(tmp_dec) || isInt(tmp_int))) {
          return false;
        }
      } else if (s[i] == '-' || s[i] == '+') {
      } else if (!(s[i] - '0' >= 0 && s[i] - '0' <= 9)) {
        return false;
      } else if (s[i] == ' ') {
      }
      if (i == size - 1) {
        return true;
      }
    }
    return false;
  }
}; */

class Solution {
public:
  enum State {
    STATE_INITIAL,
    STATE_INT_SIGN,
    STATE_INTEGER,
    STATE_POINT,
    STATE_POINT_WITHOUT_INT,
    STATE_FRACTION,
    STATE_EXP,
    STATE_EXP_SIGN,
    STATE_EXP_NUMBER,
    STATE_END
  };

  enum CharType {
    CHAR_NUMBER,
    CHAR_EXP,
    CHAR_POINT,
    CHAR_SIGN,
    CHAR_SPACE,
    CHAR_ILLEGAL
  };

  CharType toCharType(char ch) {
    if (ch >= '0' && ch <= '9') {
      return CHAR_NUMBER;
    } else if (ch == 'e' || ch == 'E') {
      return CHAR_EXP;
    } else if (ch == '.') {
      return CHAR_POINT;
    } else if (ch == '+' || ch == '-') {
      return CHAR_SIGN;
    } else if (ch == ' ') {
      return CHAR_SPACE;
    } else {
      return CHAR_ILLEGAL;
    }
  }

  bool isNumber(string s) {
    unordered_map<State, unordered_map<CharType, State>> transfer{
        {STATE_INITIAL,
         {{CHAR_SPACE, STATE_INITIAL},
          {CHAR_NUMBER, STATE_INTEGER},
          {CHAR_POINT, STATE_POINT_WITHOUT_INT},
          {CHAR_SIGN, STATE_INT_SIGN}}},
        {STATE_INT_SIGN,
         {{CHAR_NUMBER, STATE_INTEGER}, {CHAR_POINT, STATE_POINT_WITHOUT_INT}}},
        {STATE_INTEGER,
         {{CHAR_NUMBER, STATE_INTEGER},
          {CHAR_EXP, STATE_EXP},
          {CHAR_POINT, STATE_POINT},
          {CHAR_SPACE, STATE_END}}},
        {STATE_POINT,
         {{CHAR_NUMBER, STATE_FRACTION},
          {CHAR_EXP, STATE_EXP},
          {CHAR_SPACE, STATE_END}}},
        {STATE_POINT_WITHOUT_INT, {{CHAR_NUMBER, STATE_FRACTION}}},
        {STATE_FRACTION,
         {{CHAR_NUMBER, STATE_FRACTION},
          {CHAR_EXP, STATE_EXP},
          {CHAR_SPACE, STATE_END}}},
        {STATE_EXP,
         {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SIGN, STATE_EXP_SIGN}}},
        {STATE_EXP_SIGN, {{CHAR_NUMBER, STATE_EXP_NUMBER}}},
        {STATE_EXP_NUMBER,
         {{CHAR_NUMBER, STATE_EXP_NUMBER}, {CHAR_SPACE, STATE_END}}},
        {STATE_END, {{CHAR_SPACE, STATE_END}}}};

    int len = s.length();
    State st = STATE_INITIAL;

    for (int i = 0; i < len; i++) {
      CharType typ = toCharType(s[i]);
      if (transfer[st].find(typ) == transfer[st].end()) {
        return false;
      } else {
        st = transfer[st][typ];
      }
    }
    return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION ||
           st == STATE_EXP_NUMBER || st == STATE_END;
  }
};

int main(int argc, char *argv[]) {
  REOPEN_READ;
  int n;
  cin >> n;
  string str;
  char tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    str.push_back(tmp);
  }

  Solution *s = new Solution;
  cout << s->isNumber(str) << "\n";

  return 0;
}
