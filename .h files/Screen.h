#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <string_view>

namespace fs = std::filesystem;
using std::cout; 
using std::cin;
using std::endl; 
using std::string;
using std::vector;
using std::filesystem::directory_iterator;
using namespace std::literals;

bool hasEnding(string fullString, string  ending);
void readFiles(vector<string>& screenFiles);







#endif
