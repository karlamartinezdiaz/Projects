#include "phrase.h"

//This is phrase functions working 
//with organizing the phrase.txt file 
//this file will only work with phrase.h 
//and will be used by hash.cpp as well
//to do things like display and match 
//phrase names

//constructor
phrase_entry::phrase_entry()
{
    phrase = nullptr;
    topic = nullptr;
    definition = nullptr;
}

//destructor
phrase_entry::~phrase_entry()
{
    if(phrase)
    {
        delete[] phrase;
//        delete phrase;
        phrase = nullptr;
    }
    if(topic)
    {
        delete[] topic;
//        delete topic;
        topic = nullptr;
    }
    if(definition)
    {
        delete[] definition;
//        delete definition;
        definition = nullptr;
    }
}

//enter data: move user info into class info 
int phrase_entry::create_phrase(char * user_phrase, char * user_topic, char * user_definition)
{
    phrase = new char [strlen(user_phrase)+1];
    strcpy(phrase, user_phrase);

    topic = new char [strlen(user_topic)+1];
    strcpy(topic, user_topic);

    definition = new char [strlen(user_definition)+1];
    strcpy(definition, user_definition);
    return 1;
}

//Fill the class nodes
int phrase_entry:: copy_phrase(phrase_entry & new_phrase)
{
    if(phrase)
    {
        delete [] phrase;
        phrase = nullptr;
    }
    if(topic)
    {
        delete [] topic;
        topic = nullptr;
    }
    if(definition)
    {
        delete [] definition;
        definition = nullptr;
    }

    phrase = new char [strlen(new_phrase.phrase)+1];
    strcpy(phrase, new_phrase.phrase);

    topic = new char [strlen(new_phrase.topic)+1];
    strcpy(topic, new_phrase.topic);

    definition = new char [strlen(new_phrase.definition)+1];
    strcpy(definition, new_phrase.definition);

    return 1;
}

//function to display the phrases
int phrase_entry::display()
{
    if(!phrase && !topic && !definition)
    {
        return 0;
    }
    
    else
    {
        cout << "\nPhrase: " << phrase << endl;
        cout << "Topic: " << topic << endl;
        cout << "Definition: " << definition << endl;
    }
    return 1;
}

//Retrieves user phrase and puts into an object
int phrase_entry::retrieve(phrase_entry & found)
{
    if(phrase && topic && definition)
    {
        found.phrase = new char [strlen(phrase) +1];
        strcpy(found.phrase, phrase);

        found.topic = new char [strlen(phrase) + 1];
        strcpy(found.topic, topic);

        found.definition = new char [strlen(definition)+1];
        strcpy(found.definition, definition);
    }
    return 1;
}

//matches the phrase needed to find to a phrase in table
int phrase_entry::match(char * phrase_to_find) 
{
    if(!strcmp(phrase_to_find, phrase))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//matches the topic with topic in topic table 
int phrase_entry::match_topic(char * topic_to_find)
{
    if(!strcmp(topic_to_find, topic))
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

