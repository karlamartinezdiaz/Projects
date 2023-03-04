#include "phrase.h"
#include "hash.h"
 
//This is the main file working as the manager 
//and client interface
//here is where I will test that all my functions
//work appropriately and run as intended 


int main()
{
    table noodles;
    int choice = 0;
    char user_phrase[phrase_size];
    char user_topic[topic_size];
    char user_definition[definition_size];

    while(choice < 8)
    {
        phrase_entry found;
        cout<< "\n1. Load all (..) " << endl;
        cout<< "2. Add a new term (3.3)" << endl;
        cout<< "3. Remove a term(x.x)" <<endl;
        cout<< "4. Display by phrase (*-*) " <<endl;
        cout<< "5. Display a certain topic(@.@) "<<endl;
        cout<< "6. Display all(*o*)" <<endl; 
        cout<< "7. Retrieve(>.<) " <<endl;
        cout<< "\n (^O^)/  " <<endl; 
        cout<< "\nWhat do you wanna do? (>o-o)> ";
        cin >> choice;
        cin.ignore(100, '\n');

        if(choice == 1)
        {
            noodles.load_all();
        }
        if(choice == 2)
        {
            cout << "\nPhrase name(>^-^)>: ";
            cin.get(user_phrase, phrase_size, '\n');
            cin.ignore(phrase_size, '\n');
            
            cout << "Topic(>*.*)>: ";
            cin.get(user_topic, topic_size, '\n');
            cin.ignore(topic_size, '\n');

            cout<< "Definition(>-.-)>: ";
            cin.get(user_definition, definition_size, '\n');
            cin.ignore(definition_size, '\n');
            
            found.create_phrase(user_phrase, user_topic, user_definition);
            noodles.hash_table_topic(found, user_topic);
            noodles.hash_table(found, user_phrase);
        }
        if(choice == 3)
        {
            cout << "\nWhat phrase would you like to remove (=^.^=): ";
            cin.get (user_phrase, phrase_size, '\n');
            cin.ignore(100, '\n');
            noodles.remove(user_phrase);
            noodles.remove_topic(user_phrase);
        }
        if(choice == 4)
        {
            cout<< "\nWhat phrase do ya wanna display(^o,o^)? ";
            cin.get(user_phrase, phrase_size, '\n');
            cin.ignore(100, '\n');

            noodles.display_by_term(user_phrase);
        }
        if(choice == 5)
        {
            cout<< "What topic bruv? (>$-$)> : ";
            cin.get(user_topic, topic_size, '\n');
            cin.ignore(100, '\n');
            noodles.display_by_topic(user_topic);
        }
        if(choice == 6)
        {

            cout << "\n<3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3" <<endl;
            noodles.display_all();
            cout << "<3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3 <3" <<endl;
        }
        if(choice == 7)
        {
            cout<< "What you want (-.-)/: ";
            cin.get(user_phrase, phrase_size, '\n');
            cin.ignore(100, '\n');
            noodles.retrieve(user_phrase, found);
            found.display();
        }
        
    }
    return 0;
}

