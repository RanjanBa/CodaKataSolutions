#pragma once

#include <string>

using namespace std;

string strip(const string& str);

string removeComments(const string& str, bool& is_multi_line_comment);

int calculateNumberOfCodeLines(string file_name);