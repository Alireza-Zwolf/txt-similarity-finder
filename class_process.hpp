#ifndef _PROCESS_
#define _PROCESS_

#include "class_doc.hpp"

using namespace std;


class Process{
private:
    Document* main_doc;
    Document* doc1;
    Document* doc2;
    double similarity_rate_doc1 = 0.0;
    double similarity_rate_doc2 = 0.0;

public:
    Process();
    void find_similar_words();
    void process_words(Document* Doc_sample , int i , bool is_doc1);
    void cout_output();
};


#endif
