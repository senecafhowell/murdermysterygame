// gameDriver.cpp

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

// When compiling, use:
// g++ -std=c++17 gameDriver.cpp Game.cpp Weapon.cpp Map.cpp Place.cpp Lives.cpp Person.cpp

#include "Weapon.h"
#include "Map.h"
#include "Place.h"
#include "Lives.h"
#include "Person.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>

#include <chrono>
#include <thread>

    // Reference: CSCI 1300 GitHub
    // allows for time delay

using namespace std;

using namespace std::this_thread;   
using namespace std::chrono_literals;

int main()
{
    // declare a Game object and print title using the function in the Game class
    Game playthrough;
    cout << " " << endl;
    playthrough.printTitle();
    cout << " " << endl;

    sleep_for(2s);

    // create and ofstream variable and use it to clear the known_information.txt file
    ofstream clear_file;

    clear_file.open("known_information.txt");
    clear_file << "";

    clear_file.close();

    // take name as input
    string player_name;
    cout << "Welcome, detective. What is your name? Please enter it below:" << endl;
    cin >> player_name;

    sleep_for(2s);
    
    // get the player's input on what decade they want to play in, and execute the setDecade function
    int decade_choice = 0;
    cout << "\nNice to meet you, Detective " << player_name << ". \nYour adventure could go in one of many ways." << endl;

    sleep_for(2s);
    
    // while the user's input is not a valid one
    while (decade_choice != 1 && decade_choice != 2 && decade_choice != 3 && decade_choice != 4 && decade_choice != 5) {
        // get the user's decade of choice as an input
        cout << "\nWhich decade would you like it to take place in?" << endl;
        cout << "Enter the corresponding number: \n1. 1950s \n2. 1970s \n3. 1980s \n4. 2000s \n5. 2020s" << endl;
        cin >> decade_choice;
    }
    
    // declare objects for the various classes and ifstream needs, as well a number of lives and last_round variable
    Weapon weapons_info;
    Person people_info;
    Place place_info;
    Lives lives_info;
    ifstream monologue_one;
    ifstream monologue_two;
    string monologue_one_file;
    int num_lives = lives_info.getLives();
    bool last_round = false;

    // using user input, set each Object to the appropriate decade's files
    string line = "";

    // sets all objects to the 1950s data
    if(decade_choice == 1)
    {
        monologue_one_file = "50s_monologue_one.txt";

        weapons_info.setWeaponList("50s_weapons_file.txt");
        weapons_info.setWeapon();

        people_info.setPersonList("50s_people_file.txt");
        people_info.setPerson();

        place_info.setPlaceList("50s_place_file.txt");
        place_info.setPlace();

        playthrough.setInterviews("50s_interview_file.txt");
        playthrough.setDiscoveries("50s_discovery_file.txt");
    }
    // sets all objects to the 1970s data
    else if(decade_choice == 2)
    {
        monologue_one_file = "70s_monologue_one.txt";

        weapons_info.setWeaponList("70s_weapons_file.txt");
        weapons_info.setWeapon();

        people_info.setPersonList("70s_people_file.txt");
        people_info.setPerson();

        place_info.setPlaceList("70s_place_file.txt");
        place_info.setPlace();

        playthrough.setInterviews("70s_interview_file.txt");
        playthrough.setDiscoveries("70s_discovery_file.txt");
    }
    // sets all objects to the 1980s data
    else if(decade_choice == 3)
    {
        monologue_one_file = "80s_monologue_one.txt";

        weapons_info.setWeaponList("80s_weapons_file.txt");
        weapons_info.setWeapon();

        people_info.setPersonList("80s_people_file.txt");
        people_info.setPerson();

        place_info.setPlaceList("80s_place_file.txt");
        place_info.setPlace();

        playthrough.setInterviews("80s_interview_file.txt");
        playthrough.setDiscoveries("80s_discovery_file.txt");
    }
    // sets all objects to the 2000s data
    else if(decade_choice == 4)
    {
        monologue_one_file = "00s_monologue_one.txt";

        weapons_info.setWeaponList("00s_weapons_file.txt");
        weapons_info.setWeapon();

        people_info.setPersonList("00s_people_file.txt");
        people_info.setPerson();

        place_info.setPlaceList("00s_place_file.txt");
        place_info.setPlace();

        playthrough.setInterviews("00s_interview_file.txt");
        playthrough.setDiscoveries("00s_discovery_file.txt");
    }
    // sets all objects to the 2020s data
    else
    {
        monologue_one_file = "20s_monologue_one.txt";

        weapons_info.setWeaponList("20s_weapons_file.txt");
        weapons_info.setWeapon();

        people_info.setPersonList("20s_people_file.txt");
        people_info.setPerson();

        place_info.setPlaceList("20s_place_file.txt");
        place_info.setPlace();

        playthrough.setInterviews("20s_interview_file.txt");
        playthrough.setDiscoveries("20s_discovery_file.txt");
    }

    sleep_for(2s);

    // print monologue one (decade's backstory and info)
    cout << endl;
    playthrough.printMonologueOne(monologue_one_file);

    sleep_for(10s);
    
    // keep asking the user to input what characteristic they want until they input a valid one
    int characteristic = 0;
    while (characteristic != 1 && characteristic != 2 && characteristic != 3) {
        cout << "\nNow, Detective " << player_name << ", what do you think your best characteristic is (this trait will become your primary strength- it will affect your gameplay!)?" << endl;
        cout << "Enter the corresponding number: \n1. Strength \n2. Dexterity \n3. Intelligence" << endl;
        cin >> characteristic;
    }                        

    sleep_for(2s);
    cout << endl;

    // print monologue two (rules/objective)            
    monologue_two.open("monologue_two.txt");
    while(!monologue_two.eof())
    {
        getline(monologue_two, line);

        cout << line << endl;
    }

    sleep_for(20s);
    
    // configure map
    Map map_info;
    map_info.resetMap();

    // run menu on loop until game end
    int choice = 0;
    bool end_game = false;

    while (end_game != true) 
    {
        sleep_for(1s);

        // display map
        map_info.displayMap();

        // take user input for menu choice
        choice = playthrough.menuChoice();

        // if the user chose the move option
        if (choice == 1) 
        {
            // move submenu
            cout << "\nMove Submenu:" << endl;

            char move_input = 'q';

            // keep asking the user which direction they want to move in until it is valid
            while (move_input != 'w' && move_input != 'a' && move_input != 's' && move_input != 'd') 
            {
                cout << "w - Up \na - Left \ns - Down \nd - Right" << endl;
                cin >> move_input;
            }

            // execute the move function
            bool map_move = map_info.move(move_input);

            // if the move function returns false, print to the user that it was an invalid move
            if (map_move == false) {
                cout << "\nError - move is invalid due to map constraints. \nPlease try again." << endl;
            }
            
        }
        // if the user chose the interact option
        else if (choice == 2) 
        {
            // interact 

            // declare x and y variables and set them equal to the player's location
            int x_val = map_info.getPlayerRow();
            int y_val = map_info.getPlayerCol();

            // discovery point
            if (map_info.isDiscPoint(x_val, y_val) == true) 
            {
                cout << "\nYou've reached a discovery point." << endl;

                /*
                discovery point algorithm:

                with characteristics:
                if player has desired characteristic, increment lives
                if they do not, decrement lives

                without characteristics:
                display information
                add to known information
                */

                // discovery point one: bedroom
                // strength
                if (x_val == 4 && y_val == 4) 
                {
                    playthrough.displayDiscovery(0);
                    if (characteristic == 1) 
                    {
                        cout << endl;
                        playthrough.displayDiscovery(1);
                        lives_info.incrementLives1();
                        playthrough.addKnownInformation(playthrough.getDiscovery(1));
                    }
                    else 
                    {
                        cout << endl;
                        playthrough.displayDiscovery(2);
                        playthrough.addKnownInformation(playthrough.getDiscovery(2));
                        lives_info.decrementLives1();
                        // lives
                    }
                }

                // discovery point two: living room
                // intelligence
                else if (x_val == 13 && y_val == 28) 
                {
                    playthrough.displayDiscovery(3);
                    if (characteristic == 3) 
                    {
                        cout << endl;
                        playthrough.displayDiscovery(4);
                        playthrough.addKnownInformation(playthrough.getDiscovery(4));
                        lives_info.incrementLives1();
                        // lives
                    }
                    else 
                    {
                        cout << endl;
                        playthrough.displayDiscovery(5);
                        playthrough.addKnownInformation(playthrough.getDiscovery(5));
                        lives_info.decrementLives1();
                        // lives
                    }
                }

                // discovery point three: hallway
                // dexterity
                else if (x_val == 6 && y_val == 28)
                {
                    playthrough.displayDiscovery(6);
                    if (characteristic == 2) 
                    {
                        cout << endl;
                        playthrough.displayDiscovery(7);
                        playthrough.addKnownInformation(playthrough.getDiscovery(7));
                        lives_info.incrementLives1();
                        // lives
                    }
                    else 
                    {
                        cout << endl;
                        playthrough.displayDiscovery(8);
                        playthrough.addKnownInformation(playthrough.getDiscovery(8));
                        lives_info.decrementLives1();
                        // lives
                    }
                }

                // discovery point four: office
                else if (x_val == 3 && y_val == 12) 
                {
                    cout << endl;
                    playthrough.displayDiscovery(9);
                    playthrough.addKnownInformation(playthrough.getDiscovery(9));
                    cout << endl;
                }

                // discovery point five: dining room
                else if (x_val == 3 && y_val == 27)
                {
                    cout << endl;
                    playthrough.displayDiscovery(10);
                    playthrough.addKnownInformation(playthrough.getDiscovery(10));
                    cout << endl;
                }
                
                // discovery point six: bathroom
                else if (x_val == 8 && y_val == 2) 
                {
                    cout << endl;
                    playthrough.displayDiscovery(11);
                    playthrough.addKnownInformation(playthrough.getDiscovery(11));
                    cout << endl;
                }

                // discovery point seven: kitchen
                else if (x_val == 12 && y_val == 16)
                {
                    cout << endl;
                    playthrough.displayDiscovery(12);
                    playthrough.addKnownInformation(playthrough.getDiscovery(12));
                    cout << endl;
                }

                // discovery point eight: entryway
                else if (x_val == 3 && y_val == 19)
                {
                    cout << endl;
                    playthrough.displayDiscovery(13);
                    playthrough.addKnownInformation(playthrough.getDiscovery(13));
                    cout << endl;
                }

                // remove discovery point from map
                map_info.removePoint(x_val, y_val);
            }

            // character point
            else if (map_info.isCharLocation(x_val, y_val) == true)
            {

                /*
                character algorithm:

                if "hostile" :
                increment/decrement lives before giving a clue

                if not:
                give clue  

                add to known information
                */
                
                cout << "\nYou've reached a character." << endl;

                bool hostile = playthrough.isHostile();

                // character point one
                if (x_val == 1 && y_val == 2) 
                {
                    if(hostile == true)
                    {
                        cout << "\nThink about your life decisions." << endl;
                        sleep_for(2s);
                        cout << "Seriously." << endl;
                        sleep_for(3s);
                        cout << "Just a few more seconds..." << endl;
                        sleep_for(3s);
                        cout << "\nGot you. You lost a life." << endl;
                        lives_info.decrementLives1();
                        sleep_for(1s);

                        cout << "Now, you talk to ";
                        playthrough.displayInterview(0);
                        cout << endl;
                    }
                    else
                    {
                        cout << "You talk to ";
                        playthrough.displayInterview(0);
                        cout << endl;
                    }

                    playthrough.addKnownInformation(playthrough.getInterview(0));
                }

                // character point two
                else if (x_val == 2 && y_val == 12) 
                {
                    if(hostile == true)
                    {
                        cout << "\nTake a deep breath." << endl;
                        sleep_for(1s);
                        cout << "In";
                        sleep_for(2s);
                        cout << " and out." << endl;
                        sleep_for(2s);

                        cout << "\nGain a life for being mindful!" << endl;
                        lives_info.incrementLives1();
                        sleep_for(1s);

                        cout << "\nWith a clear state of mind, you talk to ";
                        playthrough.displayInterview(1);
                        cout << endl;
                    }
                    else
                    {
                        cout << "You talk to ";
                        playthrough.displayInterview(1);
                        cout << endl;
                    }

                    playthrough.addKnownInformation(playthrough.getInterview(1));
                }

                // character point three
                else if (x_val == 2 && y_val == 26) 
                {
                    if(hostile == true)
                    {
                        cout << "\nSomething causes you to start contemplating the metaness of this game." << endl;
                        sleep_for(1s);
                        cout << "You start to wonder why literally nobody in this house can give you any concrete information." << endl;
                        sleep_for(1s);
                        cout << "We remind you to use suspension of disbelief. But we're taking away a life before we go, though, for stepping out of line >:(" << endl;
                        lives_info.decrementLives1();
                        sleep_for(1s);

                        cout << "\nNow that that's been cleared up, you talk to ";
                        playthrough.displayInterview(2);
                        cout << endl;
                    }
                    else
                    {
                        cout << "You talk to ";
                        playthrough.displayInterview(2);
                        cout << endl;
                    }

                    playthrough.addKnownInformation(playthrough.getInterview(2));
                }

                // character point four
                else if (x_val == 9 && y_val == 6) 
                {
                    if(hostile == true)
                    {
                        cout << "DO DO DO DO DO DO!" << endl;
                        sleep_for(0.5s);
                        cout << "I" << endl;
                        sleep_for(0.5s);
                        cout << "AM" << endl;
                        sleep_for(0.5s);
                        cout << "YOUR SINGING TELEGRAM!" << endl;
                        sleep_for(0.5s);
                        cout << "If you've ever seen the Clue movie, you know how this one ends (not well): you lost a life." << endl;
                        lives_info.decrementLives1();
                        sleep_for(1s);
                        
                        cout << "\nNonetheless, now you're ready to talk to ";
                        playthrough.displayInterview(3);
                        cout << endl;
                    }
                    else
                    {
                        cout << "You talk to ";
                        playthrough.displayInterview(3);
                        cout << endl;
                    }

                    playthrough.addKnownInformation(playthrough.getInterview(3));
                }

                // character point five
                else if (x_val == 13 && y_val == 11) 
                {
                    if(hostile == true)
                    {   
                        string ss;
                        cout << "\nFor verification purposes, please enter the last four digits of your Social Security Number: " << endl;
                        cin >> ss;

                        cout << "\nThank you. Unforunately, we are now stealing your identity, and you have lost a life." << endl;
                        lives_info.decrementLives1();
                        sleep_for(2s);

                        cout << "\nHowever, you now have the chance to talk to ";
                        playthrough.displayInterview(4);
                        cout << endl;
                    }
                    else
                    {
                        cout << "You talk to ";
                        playthrough.displayInterview(4);
                        cout << endl;
                    }

                    playthrough.addKnownInformation(playthrough.getInterview(4));
                }

                // character point six
                else if (x_val == 10 && y_val == 29) 
                {
                    if(hostile == true)
                    {
                        cout << "Something about the way you approached this next person reminded you of how cool your job is." << endl;
                        sleep_for(1s);
                        cout << "Like, you're a Detective, " << player_name << "! Be proud of yourself." << endl;
                        sleep_for(1s);
                        cout << "With your newfound confidence, we reward you one life." << endl;
                        lives_info.incrementLives1();
                        sleep_for(1s);

                        cout << "\nYou are now ready to speak to ";
                        playthrough.displayInterview(5);
                        cout << endl;
                    }
                    else
                    {
                        cout << "You talk to ";
                        playthrough.displayInterview(5);
                        cout << endl;
                    }

                    playthrough.addKnownInformation(playthrough.getInterview(5));
                }

                // remove character point
                map_info.removePoint(x_val, y_val);
            }

            // neither; player is on a blank space
            else 
            {
                cout << "\nThis isn't a space you can interact with." << endl;
            }

            sleep_for(4s);
        }
        // if the user chose the guess option
        else if (choice == 3) 
        {
            // guess submenu

            /*
            Algorithm: 
            Based on which object the player wants to guess,
            show possible options, validate guess, then increment/decrement lives accordingly
            */
           
            int simple_guess_choice = 0;

            while (simple_guess_choice != 1 && simple_guess_choice != 2 && simple_guess_choice != 3) 
            {
                cout << "\nUnder which category would you like to make a guess?" << endl;
                cout << "Enter the corresponding number: \n1 - Weapon \n2 - Place \n3 - Person \n" << endl;
                cin >> simple_guess_choice;
            }

            // weapon
            if (simple_guess_choice == 1) 
            {
                string weapon_guess;

                cout << "\nAs a reminder, these are the possible weapons:" << endl;
                weapons_info.getWeaponList();

        
                cin.ignore();
                    // Reference: https://cplusplus.com/forum/beginner/39549/
                    // used to ensure getline() properly takes user input

                cout << "\nMake your guess:" << endl;
                getline(cin, weapon_guess);
                
                if (weapons_info.validateWeapon(weapon_guess) == true)
                {
                    weapons_info.storeGuessedWeapon(weapon_guess);

                    if (weapons_info.guessWeapon(weapon_guess) == true) {
                        lives_info.incrementLivesRand();    
                    }
                    else {
                        lives_info.decrementLivesRand();
                    }
                }
                else 
                {
                    cout << "\nError - your guess was invalid. Please try again." << endl;
                }
            }

            // place
            else if (simple_guess_choice == 2) 
            {
                string place_guess;
                
                cout << "\nAs a reminder, these are the possible places:" << endl;
                place_info.getPlaceList();

                cin.ignore();
                    // Reference: https://cplusplus.com/forum/beginner/39549/
                    // used to ensure getline() properly takes user input

                cout << "\nMake your guess: " << endl;
                getline(cin, place_guess);

                if (place_info.validatePlace(place_guess) == true) 
                {
                    place_info.storeGuessedPlace(place_guess);

                    if (place_info.guessPlace(place_guess) == true) {
                        lives_info.incrementLivesRand();
                    }
                    else {
                        lives_info.decrementLivesRand();
                    }
                }
                else 
                {
                    cout << "\nError - your guess was invalid. Please try again." << endl;
                }
            }

            // person
            else if (simple_guess_choice == 3) 
            {
                string person_guess;
            
                cout << "\nAs a reminder, these are the suspects:" << endl;
                people_info.getPersonList();

                cin.ignore();
                    // Reference: https://cplusplus.com/forum/beginner/39549/
                    // used to ensure getline() properly takes user input

                cout << "\nMake your guess:" << endl;
                getline(cin, person_guess);

                if (people_info.validatePerson(person_guess) == true)
                {
                    people_info.storeGuessedPerson(person_guess);
                    
                    if (people_info.guessPerson(person_guess) == true) {
                        lives_info.incrementLivesRand();
                    }
                    else {
                        lives_info.decrementLivesRand();
                    }
                }
                else 
                {   
                    cout << "\nError - your guess was invalid. Please try again." << endl;
                } 
            }

        }
        // if the user chose the print known information option
        else if (choice == 4) 
        {
            // execute the print known information function
            playthrough.printKnownInformation();
        }
        // if the user chose the final guess option
        else if (choice == 5) 
        {

            /*
            Final Guess algorithm:
            1. Display possible options, simple guesses, and take guess for each category
            2. call finalGuess() with user input
            */

            string final_weapon;
            string final_place;
            string final_person;


            cout << "Your journey has almost come to an end. Whether or not you get this guess correctly determines your fate. So, Detective " << player_name << ", guess wisely." << endl;

            cout << endl;

            // collect guess for person

            bool person_validation = false;

            cout << "List of all possible murderers:" << endl;
            people_info.getPersonList();

            cout << "\nList of all your simple guesses:" << endl;
            people_info.getGuessedPerson();

            while (person_validation == false)
            {

                cin.ignore();
                    // Reference: https://cplusplus.com/forum/beginner/39549/
                    // used to ensure getline() properly takes user input
                cout << "\nWho do you think committed the murder?" << endl;
                getline(cin, final_person);

                if (people_info.validatePerson(final_person) == false)
                {
                    cout << "\nError - Please enter a valid person." << endl;
                }
                else
                {
                    person_validation = true;
                }
            }

            // collect guess for weapon

            bool weapon_validation = false;

            cout << "\nList of all possible weapons:" << endl;
            weapons_info.getWeaponList();

            cout << "\nList of all your simple guesses:" << endl;
            weapons_info.getGuessedWeapon();

            cout << "\nWhat do you think " << final_person << " used to committ the murder?" << endl;
            getline(cin, final_weapon);

            if(weapons_info.validateWeapon(final_weapon) == false)
            {
                cout << "\nError - Please enter a valid weapon." << endl;
            }
            else
            {
                weapon_validation = true;
            }

            while(weapon_validation == false)
            {
                cout << "\nWhat do you think " << final_person << " used to committ the murder?" << endl;
                getline(cin, final_weapon);

                if(weapons_info.validateWeapon(final_weapon) == false)
                {
                    cout << "\nError - Please enter a valid weapon." << endl;
                }
                else
                {
                    weapon_validation = true;
                }
            }

            // collect guess for place

            bool place_validation = false;

            cout << "\nList of all possible places:" << endl;
            place_info.getPlaceList();

            cout << "\nList of all your simple guesses:" << endl;
            place_info.getGuessedPlace();

            while(place_validation == false)
            {
                cout << "\nWhere do you think " << final_person << " committed the murder?" << endl;
                getline(cin, final_place);

                if(place_info.validatePlace(final_place) == false)
                {
                    cout << "\nError - Please enter a valid place." << endl;
                }
                else
                {
                    place_validation = true;
                }
            }

            // call finalGuess()

            last_round = true;
            string actual_weapon = weapons_info.getWeapon();
            string actual_place = place_info.getPlace();
            string actual_person = people_info.getPerson();
            int final_lives = lives_info.getLives();
            int lives_threshold = lives_info.getLivesThreshold();
            int num_weapons = weapons_info.getNumGuessedWeapon();
            int num_places = place_info.getNumGuessedPlace();
            int num_people = people_info.getNumGuessedPerson();

            playthrough.finalGuess(final_weapon, final_place, final_person, actual_weapon, actual_place, actual_person, final_lives, lives_threshold, num_weapons, num_places, num_people);
            end_game = true;
        }
        // if the user chose the forfeit game option
        else if (choice == 6) 
        {

            // Forfeit game: ensure player wants to forfeit 

            string confirmation = "";
            cout << "Are you sure you'd like to forfeit the game? \nEnter 'Yes' to confirm:" << endl;
            cin >> confirmation;

            if (confirmation == "Yes") 
            {
                end_game = true;
            }
            else 
            {
                cout << "Glad you chose to continue." << endl;
            }
        }
        else
        {
            cout << "Invalid menu choice. Please try again." << endl;
        }
        
        // if lives = 0, end game
        // otherwise, display game stats and continue
        if(lives_info.getLives() == 0 && end_game == false) {
            cout << "\nYou have lost all your lives. Unfortunately, the game is over. Thank you for playing, and feel free to try again!" << endl;
            end_game = true;
        }
        else if(last_round == true)
        {
            cout << "Thank you for playing!" << endl;
            end_game = true;
        }
        else
        {
            cout << "\nYour current game stats: " << endl;
            cout << weapons_info.getNumGuessedWeapon() << " weapon guess(es)" << endl;
            cout << place_info.getNumGuessedPlace() << " place guess(es)" << endl;
            cout << people_info.getNumGuessedPerson() << " person guess(es)" << endl;
            cout << lives_info.getLives() << " live(s) remaining \n" << endl;
        }

    }

    return 0;
}