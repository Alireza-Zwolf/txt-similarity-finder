#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
#include <math.h>
#include "class_process.hpp"


Process:: Process(){
        this->main_doc = new Document("main.txt");
        this->doc1 = new Document("doc1.txt");
        this->doc2 = new Document("doc2.txt");
        this->find_similar_words();
        this->cout_output();
    }

void Process:: find_similar_words(){
        for(int i = 0 ; i < main_doc->get_words().size() ; i++){
            process_words(doc1 , i , true);
            process_words(doc2 , i , false);
        }
    }
void Process:: process_words(Document* Doc_sample , int i , bool is_doc1){
        for(int j = 0 ; j < Doc_sample->get_words().size() ; j++){                            // O(n) ~ o(n^2)
            //if(main_doc->get_words()[i]->name[0] != Doc_sample->get_words()[j]->name[0])
            //    break;
            if(main_doc->get_words()[i]->name == Doc_sample->get_words()[j]->name){
                double parameter_a = main_doc->get_words()[i]->count / main_doc->get_normalization_denominator();
                double parameter_b = Doc_sample->get_words()[j]->count / Doc_sample->get_normalization_denominator();
                if(is_doc1 == true) similarity_rate_doc1 += parameter_a * parameter_b;
                else similarity_rate_doc2 += parameter_a * parameter_b;
            }
        }
    }
void Process:: cout_output(){
        cout << "similarity rate of main doc and doc #1 is:" << similarity_rate_doc1 << endl;
        cout << "similarity rate of main doc and doc #2 is:" << similarity_rate_doc2 << endl;
        if(similarity_rate_doc1 > similarity_rate_doc2)
            cout << "doc1 is more similiar to main doc than doc2" << endl;
        else 
            cout << "doc2 is more similiar to main doc than doc2" << endl;
    }