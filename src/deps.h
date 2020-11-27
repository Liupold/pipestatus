# pragma once
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<string> parseTemplate(const string Template); // returs key array.
void parse_fifo_input(const string fifo_input, const vector<string> &keys, vector<string> &values);
void cat_string(const vector<string> &curr_data);
