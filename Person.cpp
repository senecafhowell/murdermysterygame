// Person.cpp

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "Person.h"

using namespace std;

Person::Person() {
    chosen_person = " ";
}

void Person::setPerson() {
    // set the chosen_person to the first person in the list
    chosen_person = persons_list.at(0);
}

string Person::getPerson() {
    return chosen_person;
}

/*
Algorithm:
1. go through persons_list and check for a match
2. return true/false accordingly
*/
bool Person::validatePerson(string person)
{
    int valid = 0;
    
    // while the counter is smaller than the persons_list vector
    for(int i = 0; i < persons_list.size(); i++)
    {
        // if the guessed person is one of the people in the list
        if(person == persons_list.at(i))
        {
            // add to the valid counter
            valid++;
        }
    }
    
    // if no valid person was found
    if(valid == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

/*
Algorithm:
1. open file
2. store data from file into vector
3. close file
*/
void Person::setPersonList(string persons_of_decade_file_name) {
    string line = " ";
    int count = 0;
    
    // open the weapons file
    ifstream persons_file;
    persons_file.open(persons_of_decade_file_name);

    // if the file did not open, print an error
    if(persons_file.fail())
    {
        cout << "The person file did not open properly." << endl;
    }
    else
    {
        // otherwise, populate the person list vector with the people listed in the file
        while(!persons_file.eof())
        {
            getline(persons_file, line);

            persons_list.push_back(line);
        }

        persons_file.close();
    }
}

void Person::getPersonList() {
    // for the size of the person list, print out each individual person
    for(int i = 0; i < persons_list.size(); i++) {
        cout << persons_list.at(i) << endl;
    }
}

/*
Algorithm:
1. check that input is valid
2. store guessed person
3. return true/false accordingly
*/
bool Person::guessPerson(string guessed_person)
{
    int valid = 0;
    
    // while the counter is smaller than the persons_list vector
    for(int i = 0; i < persons_list.size(); i++)
    {
        // if the guessed person is one of the people in the list
        if(guessed_person == persons_list.at(i))
        {
            // add to the valid counter
            valid++;
        }
    }
    
    // if no valid person was found
    if(valid == 0)
    {
        cout << "The person you guessed was not a valid person." << endl;
        return false;
    }
    else
    {
        Person vector;
        vector.storeGuessedPerson(guessed_person);

        // if the guessed_person was the chosen_person, print a correct message and add to the lives count
        if(chosen_person == guessed_person)
        {
            cout << "Correct! The person was in fact " << guessed_person << ". You've gained a random amount of lives!" << endl;
            return true;
        }
        // otherwise, print an incorrect message and subtract from the lives count
        else
        {
            cout << "Incorrect. The person was not " << guessed_person << ". You have lost a random amount of lives." << endl;
            return false;
        }
    }

    // add one to the person guesses counter
    person_guesses++;
}

void Person::storeGuessedPerson(string guessed_person)
{
    // add the guessed person to the end of the guessed persons vector
    guessed_persons.push_back(guessed_person);
}

/*
Algorithm:
Ensure the vector has data, then print all guesses for person
*/
void Person::getGuessedPerson()
{
    int size = guessed_persons.size();

    if(size == 0)
    {
        cout << "You made no simple guesses for the person category." << endl;
    }
    else
    {
        for(int i = 0; i < guessed_persons.size(); i++)
        {
            cout << guessed_persons.at(i) << endl;
        }
    }
}


/*
Algorithm:
Return the number of guesses made for person
*/
int Person::getNumGuessedPerson()
{
    int size = guessed_persons.size();
    return size;
}