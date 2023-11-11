// Game.cpp

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#include "Weapon.h"
#include "Place.h"
#include "Person.h"
#include "Map.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>

using namespace std;

/*
Algorithm: initializes the private data members to a default value
*/
Game::Game()
{
    vector <int> guesses{};
    vector <string> interviews{};
    vector <string> discoveries{};
}

/*
Algorithm: display menu to the users and let them make a choice
1. Declare the choice variable and initialize it to zero
2. While the choice variable is not equal to one of
1. Display all primary menu choices to user (each option correlated to a number)
2. Have the user input their choice
3. If the input is invalid, print "Invalid option" and let them choose again
4. When the input is valid, determine if the given choice has a secondary menu
5. If the option has a secondary menu, print the secondary menu and get their input (if invalid, print that it's invalid and make them choose again. When valid, return that integer)
6. Otherwise, simply return the integer of the primary menu option
Returns: menu_choice (integer)
*/
int Game::menuChoice()
{
    int choice = 0;
    
    while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6) 
    { 
        cout << "\nMenu:" << endl;
        cout << "1. Move \n2. Interact \n3. Guess \n4. Print Known Information \n5. Final Accusation \n6. Forfeit Game" << endl;
        cin >> choice;
    }

    return choice;
}

/*
Algorithm: get the user to input their final guesses, and, based off that input, determine whether the user has won or not
1. If the guessed_weapon is the chosen_weapon, the guessed_place is the chosen_place, and the guessed_person is the chosen_person, and if the player's lives_count is greater than the lives_threshold, print that the user has won the game, and their game stats (execute sortGuesses function, print the number of lives)
2. Otherwise, print that the user has lost the game (and the game summary)
*/
void Game::finalGuess(string guessed_weapon, string guessed_place, string guessed_person, string actual_weapon, string actual_place, string actual_person, int num_lives, int lives_threshold, int num_weapons, int num_places, int num_people)
{
    Game sort;

    cout << "You thought " << guessed_person << " committed the murder with the " << guessed_weapon << " in the " << guessed_place << "." << endl;

    if(guessed_weapon == actual_weapon && guessed_place == actual_place && guessed_person == actual_person && num_lives >= lives_threshold)
    {
        cout << "Congratulations, Detective! You successfully deduced all elements of the case, and maintained a healthy number of lives! Here is a summary of your adventure:" << endl;

        sort.sortGuesses(num_weapons, num_places, num_people);

        cout << endl;

        cout << "Lives remaining: " << num_lives << endl;
    }
    else if(guessed_weapon == actual_weapon && guessed_place == actual_place && guessed_person == actual_person && num_lives < lives_threshold)
    {
        cout << "Unfortunately, Detective, while you successfully deduced all elements of the case, you did not maintain a healthy number of lives, and, therefore, did not successfully complete the mission." << endl;
        cout << "Here is a summary of your adventure:" << endl;

        sort.sortGuesses(num_weapons, num_places, num_people);

        cout << endl;

        cout << "Lives remaining: " << num_lives << endl;
    }
    else if((guessed_weapon != actual_weapon || guessed_place != actual_place || guessed_person != actual_person) && num_lives >= lives_threshold)
    {
        cout << "Unfortunately, Detective, while you successfully maintained a healthy number of lives, you did not deduce one or more of the elements of the case correctly, and, therefore, did not successfully complete the mission." << endl;
        cout << "As it turns out, " << actual_person << " did it with the " << actual_weapon << " in the " << actual_place << "." << endl;
        cout << "Here is a summary of your adventure:" << endl;

        sort.sortGuesses(num_weapons, num_places, num_people);

        cout << endl;

        cout << "Lives remaining: " << num_lives << endl;
    }
    else if((guessed_weapon != actual_weapon || guessed_place != actual_place || guessed_person != actual_person) && num_lives < lives_threshold)
    {
        cout << "Unfortunately, Detective, you did not deduce one or more of the elements of the case correctly, and you did not maintain a healthy number of lives. Therefore, you did not successfully complete the mission." << endl;
        cout << "As it turns out, " << actual_person << " did it with the " << actual_weapon << " in the " << actual_place << "." << endl;
        cout << "Here is a summary of your adventure:" << endl;

        sort.sortGuesses(num_weapons, num_places, num_people);

        cout << endl;

        cout << "Lives remaining: " << num_lives << endl;
    }
}

/*
Algorithm: Open the text file (known_information.txt) and append information as passed in the parameter
1. Declare the infoFile variable
2. Open the text file and append information as passed in the parameter
3. Write the information (provided through the parameter of the function) into the file
4. Close the file
*/
void Game::addKnownInformation(string info)
{
    ofstream infoFile;

    infoFile.open("known_information.txt", ios::app);
        // Reference: https://cplusplus.com/doc/tutorial/files/
        // ios::app ensures function does not overwrite data already in file 

    infoFile << endl;
    infoFile << info;

    infoFile.close();

}

/*
Algorithm: read the text file (known_information.txt) and print each line, allowing the player to view their found clues and past events.
1. Print a statement about providing all the discovered information
2. Declare the infoFile variable
3. Open the text file (and ensure it actually opens)
4. If it opened, print every line in the file
5. Close the file
*/
void Game::printKnownInformation()
{   
    cout << "Here's all the information you've discovered so far: \n" << endl;

    ifstream infoFile;

    infoFile.open("known_information.txt");

    if(infoFile.fail())
    {
        cout << "File failed to open" << endl;
    }
    else
    {
        string line = " ";

        while(!infoFile.eof())
        {
            getline(infoFile, line);

            cout << line << endl;
        }
        
        infoFile.close();
    }

}

/*
Algorithm: Sort and display the number of guesses the player took to guess the weapon, person, and place from least to greatest
1. Declare all necessary variables
2. If one index is greater than the value one index higher, swap them
*/
void Game::sortGuesses(int weapon_guesses, int place_guesses, int person_guesses)
{
    int guesses[3] = {weapon_guesses, place_guesses, person_guesses};
    int temp;
    int temp2;
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < (2 - i); j++)
        {
            if(guesses[j] > guesses[j + 1])
            {
                temp = guesses[j];
                temp2 = guesses[j + 1];
                guesses[j] = temp2;
                guesses[j + 1] = temp;
            }
        }
    }
    
    // print the sorted array
    cout << "Here is a list of the three simple guess categories, sorted from the least amount of guesses you made to the most amount of guesses you made:" << endl;

    if(guesses[0] == weapon_guesses)
    {
        cout << "Weapon: " << weapon_guesses << " guesses" << endl;

        if(guesses[1] == place_guesses)
        {
            cout << "Place: " << place_guesses << " guesses" << endl;
            cout << "Person: " << person_guesses << " guesses" << endl;
        }
        else
        {
            cout << "Person: " << person_guesses << " guesses" << endl;
            cout << "Place: " << place_guesses << " guesses" << endl;
        }
    }
    else if(guesses[0] == place_guesses)
    {
        cout << "Place: " << place_guesses << " guesses" << endl;

        if(guesses[1] == weapon_guesses)
        {
            cout << "Weapon: " << weapon_guesses << " guesses" << endl;
            cout << "Person: " << person_guesses << " guesses" << endl;
        }
        else
        {
            cout << "Person: " << person_guesses << " guesses" << endl;
            cout << "Weapon: " << weapon_guesses << " guesses" << endl;
        }
    }
    else
    {
        cout << "Person: " << person_guesses << " guesses" << endl;

        if(guesses[1] == weapon_guesses)
        {
            cout << "Weapon: " << weapon_guesses << " guesses" << endl;
            cout << "Place: " << place_guesses << " guesses" << endl;
        }
        else
        {
            cout << "Place: " << place_guesses << " guesses" << endl;
            cout << "Weapon: " << weapon_guesses << " guesses" << endl;
        }
    }
}

/*
Algorithm: Open the title.txt file and print each line
*/
void Game::printTitle()
{
    ifstream title_file;

    title_file.open("title.txt");

    if(title_file.fail())
    {
        cout << "File failed to open" << endl;
    }
    else
    {
        string line = " ";

        while(!title_file.eof())
        {
            getline(title_file, line);

            cout << line << endl;
        }
        
        title_file.close();
    }
}

void Game::printMonologueOne(string monologue_one_file)
{
    /*
    Algorithm:
    Open the monologue_one_file and print each line.
    */

    ifstream mono_one_file;

    mono_one_file.open(monologue_one_file);

    string line = "";
    while(!mono_one_file.eof())
    {
        getline(mono_one_file, line);

        cout << line << endl;
    }
    mono_one_file.close();
}

/*  
Algorithm:
1. Open the interview file
2. Put the contents of each line into the interviews vector
3. Close the file 
*/

void Game::setInterviews(string interviews_file)
{
    ifstream interview_file;
    interview_file.open(interviews_file);
    string line = "";

    while(!interview_file.eof())
    {
        getline(interview_file, line);

        interviews.push_back(line);
    }

    interview_file.close();

}

/*  
Algorithm:
1. Open the discovery point file
2. Put the contents of each line into the discoveries vector
3. Close the file 
*/

void Game::setDiscoveries(string discoveries_file)
{
    ifstream discovery_file;
    discovery_file.open(discoveries_file);
    string line = "";

    while(!discovery_file.eof())
    {
        getline(discovery_file, line);

        discoveries.push_back(line);
    }

    discovery_file.close();
}

/*  
Algorithm:
Print the contents of the interviews vector at a given position 
*/

void Game::displayInterview(int num) 
{
    cout << interviews[num] << endl;
}

/*  
Algorithm:
Print the contents of the discoveries vector at a given position 
*/

void Game::displayDiscovery(int num) 
{
    cout << discoveries[num] << endl;
}

/*  
Algorithm:
Return the contents of the interviews vector at a given position 
*/

string Game::getInterview(int num)
{
    return interviews[num];
}

/*  
Algorithm:
Return the contents of the discoveries vector at a given position 
*/

string Game::getDiscovery(int num)
{
    return discoveries[num];
}

/*  
Algorithm:
1. Use a random formula with a 50% chance 
2. Return true or false accordingly
*/

bool Game::isHostile()
{
    srand(time(0));

    int hostile = rand() % 11;

    if(hostile <= 5)
    {
        return true;
    }
    else
    {
        return false;
    }
}