#pragma once

#include "pch.h"
#include "counting_code_lines.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string strip(const string& str) {
    int start_idx = 0;
    while (start_idx < str.size() && str[start_idx] == ' ')
    {
        start_idx++;
    }

    int end_idx = str.size() - 1;
    while (end_idx > start_idx && str[end_idx] == ' ')
    {
        end_idx--;
    }

    if (end_idx >= start_idx) {
        int len = end_idx - start_idx + 1;
        return str.substr(start_idx, len);
    }

    return "";
}

string removeComments(const string& str, bool& is_multi_line_comment) {
    string strip_str = strip(str);

    if (strip_str.empty()) return "";

    if (is_multi_line_comment) {
        size_t multi_end_pos = strip_str.find("*/");
        if (multi_end_pos != string::npos) {
            is_multi_line_comment = false;

            if (multi_end_pos + 2 >= strip_str.size()) {
                return "";
            }
            strip_str = strip_str.substr(multi_end_pos + 2);
        }
        else {
            return "";
        }
    }

    while (true)
    {
        size_t multi_start_pos = strip_str.find("/*");
        size_t single_comment_pos = strip_str.find("//");

        if (single_comment_pos < multi_start_pos) {
            break;
        }

        if (multi_start_pos != string::npos) {
            size_t multi_end_pos = strip_str.find("*/", multi_start_pos + 2);
            if (multi_end_pos != string::npos) {
                strip_str = strip_str.substr(0, multi_start_pos) + strip_str.substr(multi_end_pos + 2);
            }
            else {
                is_multi_line_comment = true;
                strip_str = strip_str.substr(0, multi_start_pos);
            }
        }
        else {
            break;
        }
    }

    size_t single_comment_pos = strip_str.find("//");

    if (single_comment_pos != string::npos) {
        strip_str = strip_str.substr(0, single_comment_pos);
    }

    return strip_str;
}

int calculateNumberOfCodeLines(string file_name) {
    ifstream inputFile(file_name);

    if (!inputFile.is_open())
    {
        cerr << "Error opening file: " << file_name << endl;
        return -1;
    }

    string line;
    int code_lines = 0;
    bool is_multi_comments = false;
    while (getline(inputFile, line))
    {
        string str = removeComments(line, is_multi_comments);
        if (!str.empty()) {
            cout << str << endl;
            code_lines++;
        }
    }

    return code_lines;
}