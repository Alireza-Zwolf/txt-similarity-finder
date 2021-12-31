#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
#include <math.h>
#include "class_doc.hpp"


Document:: Document(string filename){
        fstream file;
        file.open(filename);
        string temp;
        if(file.is_open()){
            while(getline(file,temp)){
                this->file_contents += temp += " ";
            }
        }
        file.close();
        this->splitString(file_contents);
        this->sort_alphabetically(words);
        this->calculate_normalization_denaminator();
    }
void Document :: splitString(string str, string delimiter /*= " "*/){   
        int start = 0;
        int end = str.find(delimiter);
        string temp;
        while (end != -1) {
            temp = str.substr(start, end - start);
            int index = 0;
            if(check_repetition(temp , index) == false){
                Word* word = new Word;
                word->name = temp;
                word->count += 1;
                words.push_back(word);
            }
            else{
                 words[index]->count += 1;
            }
            start = end + delimiter.size();
            end = str.find(delimiter, start);
        }
    }
bool Document :: check_repetition(const string &word , int &index){
        int i = 0;
        for(i ; i < words.size() ; i++)
            if(word == words[i]->name)
                return true;
        index = i;
        return false;
    }
void Document :: sort_alphabetically(vector<Word*> &list){                          //check
        sort(list.begin(), list.end(), [](Word* a, Word* b) {
		return a->name < b->name;
	});
    }
void Document :: calculate_normalization_denaminator(){
        double denominator = 0;
        for(int i = 0 ; i < words.size() ; i++)
            denominator += pow(words[i]->count , 2);
        normalizing_denominator = sqrt(denominator);
    }
void Document :: omit_common_words(){
        vector<string> common_words = {"the" , "," , "." , "a" , "and" , "of" , "to" , "is" , "/" , ">" , 
        "<" , "br" , "in" , "I" , "it" , "that" , "'s" , "this" , "was " , "The" , "as" , "for" , ")" , "(" ,
         "but" , "on" , "you" , "are" , "not" , "have" , "his" , "be" , "!" , "he" , "one" , "at" , "by" ,
        "an" , "all" , "who" , "they" , "from" , "like" , "It"};
        for(int i = 0 ; i < words.size() ; i++){
            for(int j = 0 ; j < common_words.size() ; j++){
                if(words[i]->name == common_words[j])
                    words.erase(words.begin() + i);                         //check
            }
        }
    }
vector<Word*> Document ::  get_words(){return words;}
double Document :: get_normalization_denominator(){return normalizing_denominator;}