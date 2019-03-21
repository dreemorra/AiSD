#include <iostream>
#include <vector>

char inverted(char c) {
  return (islower(c) ? toupper(c) : tolower(c));
}

void input_requests(std::vector<std::pair<int, int>>& scopes) {
  int requests = 0;
  std::cin >> requests;

  for(int i = 0; i < requests; ++i) {
    int L = 0;
    int R = 0;
    std::cin >> L >> R;
    
    if(L > R) {
      std::swap(L, R);
    }
    ++scopes[L-1].first;
    ++scopes[R-1].second;
  }
}

void solution(std::string& str, std::vector<std::pair<int, int>>& scopes) {
  int len = str.length();
  bool invert = false;
  for(int i = 0; i < len; ++i) {
    if(scopes[i].first % 2 == 1) {
      invert = !invert;
    }

    std::cout << (invert ? inverted(str[i]) : str[i]);

    if(scopes[i].second % 2 == 1) {
      invert = !invert;
    }
  }
}

int main() {
  std::string str;
  std::cin >> str;

  int len = str.length();
  std::vector<std::pair<int, int>> scopes(len);

  input_requests(scopes);

  solution(str, scopes);

  return 0;
}