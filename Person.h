// Person.h

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

/**
 * Algorithm:
 * 1. Define the Person class
 * 2. Define all private and public class members, including the constructors
*/

class Person {

    public:

        Person();

        void setPerson();
        string getPerson();
        bool validatePerson(string person);

        void setPersonList(string persons_of_decade_file_name);
        void getPersonList();

        bool guessPerson(string guessed_person);
        void storeGuessedPerson(string guessed_person);
        void getGuessedPerson();
        int getNumGuessedPerson();

    private:

        string chosen_person;
        vector<string> guessed_persons;
        vector<string> persons_list;
        int person_guesses = 0;


};