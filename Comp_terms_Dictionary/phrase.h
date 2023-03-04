#ifndef PHRASE 
#define PHRASE
#include <cstring> 
#include <cctype>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

//Header file to proclaim all my public 
//and private data types within my class 

using namespace std;

//initialize 
const int phrase_size = 1000;
const int topic_size = 1000;
const int definition_size = 2000;

//class for the phrase entry functions 
class phrase_entry 
{
    public:
        phrase_entry();
        ~phrase_entry();
        int create_phrase(char * user_phrase, char * user_topic, char * user_definition);
        int copy_phrase(phrase_entry & new_phrase);
        int retrieve(phrase_entry & found);
        int display();
        int match(char * phrase_to_find);
        int match_topic(char * topic_to_find);
    private:
        char * phrase;
        char * topic;
        char * definition;
};

#endif 

