#include "phrase.h"

//This is the hashtable header file 
//This file will hold all my prototypes 
//for the hash table, private and public 
//data and my node for my
//hash table functions.

//node struct for the hash class
struct node 
{
    phrase_entry entry;
    node * next;
};

//class for the hash table 
class table 
{
    public: 
        table();
        ~table();
        //int insert (char * key_val, phrase_entry);
        int hash_func(char * user_phrase);
        int retrieve(char * find_phrase, phrase_entry & found);
        int display_all();
        int remove_topic(char * top_name);
        int remove(char * key);
        int load_all();
        int display_by_term(char * phrase_found);
        int display_by_topic(char * user_topic); 
        int hash_table(phrase_entry & box, char * user_phrase);
        int hash_table_topic(phrase_entry & package, char * user_topic);

    private: 
        node ** head;   //dynamically allocated array of 
        node ** topic_head;
        int phrase_table_size;
        int topic_table_size;
};






