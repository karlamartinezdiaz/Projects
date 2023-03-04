#include "hash.h"
#include "phrase.h"

//This file will hold all my functions 
//for the hash table, it will work with both 
//hash.h and phrase.h and call functions 
//from both separate headers 

//constructor
table::table()
{
    phrase_table_size = 227;      //227
    head = new node * [phrase_table_size];
    int i = 0;
    while(i < phrase_table_size)
    {
        head[i] = nullptr;
        ++i;
    }
    topic_table_size = 227;   //179
    topic_head = new node * [topic_table_size];
    int j = 0;
    while(j < topic_table_size)
    {
        topic_head[j] = nullptr;
        ++j;
    }
}

//destructor
table::~table()
{     
    int j = 0;
    while(j<topic_table_size)
    {
        if(!topic_head[j])
        {
            topic_head[j] = nullptr;
        }
        if(topic_head[j])
        {
            node * topic_temp = topic_head[j];
            
            while(topic_temp != nullptr)
            {
                node * hold = topic_temp -> next;
                delete topic_temp;
                topic_temp = hold; 
            }
        }
        ++j; 
    }
    int i = 0;
    while(i<phrase_table_size)
    {
        if(!head[i])
        {
            head[i] = nullptr;
        }
        if(head[i])
        {
            node * temp = head[i];
            
            while(temp != nullptr)
            {
                node * hold = temp -> next;
                delete temp;
                temp = hold; 
            }
        }
        ++i; 
    }
    delete [] head;
    delete [] topic_head;
}

//displays to user the term they input to look for 
int table::display_by_term(char * phrase_found)
{
   int index = hash_func(phrase_found);
   node * trav = head[index];
   while(trav != nullptr)
   {
       if(trav -> entry.match(phrase_found))
       {
           trav -> entry.display();
       }
       trav = trav -> next;
   }
   return 1;
}

//retrieves the phrase and copies into the object 
int table::retrieve(char * find_phrase, phrase_entry & found)
{
   int index = hash_func(find_phrase);
   node * trav = head[index];
   while(trav != nullptr)
   {
       if(trav -> entry.match(find_phrase))
       {
           trav -> entry.retrieve(found);
       }
       trav = trav -> next;
   }
   return 1;
}

//displays all phrases in the .txt file 
int table::display_all()
{
    int i = 0;
    node * trav = nullptr;
    while(i < phrase_table_size)
    {
        if(head[i])
        {
            trav = head[i];
            while(trav != nullptr)
            {
                trav -> entry.display();
                ++i;
                trav = trav -> next;
            }
        }
        ++i;
    }
    return 1;
}

//inserting file from external .txt
int table::load_all()
{
    char user_phrase[phrase_size];
    char user_topic[topic_size];
    char user_definition[definition_size];

    ifstream load;
    load.open("revised.txt");

    //if file is found do this
    if(load)
    {
        while(!load.eof())
        {
            phrase_entry box; 
            load.get(user_phrase, phrase_size, '|');
            load.ignore(phrase_size, '|');

            load.get(user_topic, topic_size, '|');
            load.ignore(topic_size, '|');

            load.get(user_definition, definition_size, '\n');
            load.ignore(definition_size, '\n');

            box.create_phrase(user_phrase, user_topic, user_definition);
            hash_table(box, user_phrase);
            hash_table_topic(box, user_topic);
            
        }
        load.close();
    }
    return 1;
}

int table::hash_table(phrase_entry & box, char * user_phrase)
{
    int index = hash_func(user_phrase); //gets index for user phrase
    node * milk = new node;             //make a node to put that user stuff in
    milk -> entry.copy_phrase(box);
    milk -> next = nullptr;

    if(!head[index])
    {
        head[index] = milk;
    }
    else
    {
        node * hold = head[index];
        head[index] = milk;
        milk -> next = hold;
        return 1;
    }
    return 1;
}

//Hash function,will return my "key" 
int table::hash_func(char * user_phrase)
{
    int length = strlen(user_phrase);
    int power = strlen(user_phrase);

    int holder = 0;
    int i = 0;
    while(i < length)
    {
        holder += user_phrase[i] * pow(32, power);
        --power;
        ++i;
    }
    
//    holder = holder * 2;
//    holder = holder + 143;
    return abs(holder) % phrase_table_size;
}

//Used to remove a phrase from the phrase table (only) 
int table::remove(char * key)
{
    int i = hash_func(key);
    node * trav = head[i];
    node * current = head[i] -> next;
    while(current != nullptr)
    {
        if(trav -> entry.match(key))
        {
            delete trav;
            head[i] = current;
        }

        if(current -> entry.match(key))
        {
            trav -> next = current -> next;
            delete current;
        }
        trav = trav -> next;
        current = current -> next;
    }
    return 1;
}

//second hash table for the topic 
int table::hash_table_topic(phrase_entry & package, char * user_topic)
{
    int index = hash_func(user_topic); //gets index for user phrase
    node * leche = new node;             //make a node to put that user stuff in
    leche -> entry.copy_phrase(package);
    leche -> next = nullptr;

    if(!topic_head[index])
    {
        topic_head[index] = leche;
    }
    else
    {
        node * hold = topic_head[index];
        topic_head[index] = leche;
        leche -> next = hold;
        return 1;
    }
    return 1;
}

//displays the phrases with the same topic 
int table::display_by_topic(char * user_topic)
{
    int index = hash_func(user_topic);
    node * trav = topic_head[index];
    while(trav != nullptr)
    {
        if(trav -> entry.match_topic(user_topic))
        {
            trav -> entry.display();
        }
        trav = trav -> next;
    }
    return 1;
}

//removes by topic from the topic table(only!)
int table::remove_topic(char * top_name)
{
    int i = hash_func(top_name);
    node * trav = topic_head[i];
    node * current = topic_head[i] -> next;
    while(current != nullptr)
    {
        if(trav -> entry.match_topic(top_name))
        {
            delete trav;
            topic_head[i] = current;
        }

        if(current -> entry.match_topic(top_name))
        {
            trav -> next = current -> next;
            delete current;
        }
        trav = trav -> next;
        current = current -> next;
    }
    return 1;
}




