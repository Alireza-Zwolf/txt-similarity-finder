#ifndef _DOCUMENT_
#define _DOCUMENT_

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

struct Word{
    int count = 0;
    string name;
};


class Document{
private:
    int doc_num;
    double normalizing_denominator = 0.0;
    string file_contents;
    vector<Word*> words;
public:
    Document(string filename);
    void splitString(string str, string delimiter = " ");
    bool check_repetition(const string &word , int &index);
    void sort_alphabetically(vector<Word*> &list);
    void calculate_normalization_denaminator();
    void omit_common_words();
    vector<Word*> get_words();
    double get_normalization_denominator();
};

#endif
