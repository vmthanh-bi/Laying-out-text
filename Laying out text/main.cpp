#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void naive(std::vector<std::string>& words,int maxWidth) {
  int n = 0;
  int width = words[n].length();
  std::cout << words[n];
  n++;
  while (n < words.size()) {
    if (width + 1 + words[n].length() <= maxWidth) {
      std::cout << " " << words[n];
      width += 1 + words[n].length();
    }
    else {
      std::cout << std::endl;
      width = words[n].length();
      std::cout << words[n];
    }
    n++;
  }
}

int penalty(int maxWidth, int width) {
    int p = (maxWidth - width)*(maxWidth - width)*(maxWidth - width);
    return p;
}

int recursive(std::vector<std::string>& words,int maxWidth, int start, std::vector<int>& current) {
    int n = start;
    int width = words[n].length();
    n++;
    while (n < words.size()) {
        if (width + 1 + words[n].length() <= maxWidth) {
          width += 1 + words[n].length();
        }
        else {
            break;
        }
        n++;
    }
    if (n == words.size()) {
        current[start] = words.size()-1;
        return 0;
    }
    width = 0;
    int minP = 1000000;
    for (int i = start; i <= n; i++) {
        width += 1 + words[i].length();
        int p = penalty(maxWidth, width);
        int r = recursive(words, maxWidth, i+1, current);
        if (p + r < minP) {
            minP = p + r;
            current[start] = i;
        }
    }
    return minP;
}

int memoizedRecursive(std::vector<std::string>& words,int maxWidth, int start, std::vector<int>& current, std::vector<int>& memo) {
    if(memo[start] < 1000000) return memo[start];
    int n = start;
    int width = words[n].length();
    n++;
    while (n < words.size()) {
        if (width + 1 + words[n].length() <= maxWidth) {
          width += 1 + words[n].length();
        }
        else {
            break;
        }
        n++;
    }
    if (n == words.size()) {
        current[start] = words.size()-1;
        memo[start] = 0;
        return 0;
    }
    width = 0;
    int minP = 1000000;
    for (int i = start; i <= n; i++) {
        width = words[i].length();
        width += 1 + words[i].length();
        int p = penalty(maxWidth, width);
        int r;
        if (memo[i] == 1000000) {
            r = memoizedRecursive(words, maxWidth, i+1, current, memo);
        } else {
            r = memo[i];
        }
        if (p + r < minP) {
            minP = p + r;
            current[start] = i;
        }
    }
    memo[start] = minP;
    return minP;
}

int main()
{
  std::ifstream input;
  input.open("words.txt");
  std::string word;
  std::vector<std::string> words;
  while (input >> word)
    words.push_back(word);
  input.close();
  std::cout << "Read " << words.size() << " words." << std::endl;

  std::cout << "Enter max line length:";
  int maxWidth;
  std::cin >> maxWidth;
  
  std::vector<int> current(words.size(), 0);
  std::vector<int> memo(words.size(), 1000000);
  int totalP = memoizedRecursive(words, maxWidth, 0, current, memo);
  std::cout << totalP;
  int print = 0;
    while (print < words.size()) {
        for (int i = print; i <= current[print]; i++) {
            std::cout << words[i] << " ";
        }
        std::cout << std::endl;
        print = current[print] + 1;
    }

  return 0;
}
