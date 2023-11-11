// Lives.cpp

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#include <iostream>
#include <string>
#include <vector>
#include <cassert>

#include "Lives.h"

using namespace std;

Lives::Lives() {
    setLives();
}

void Lives::setLives() {
    // set lives to starting number
    playerLives = 25;
}

int Lives::getLives() {
    return playerLives;
}

void Lives::updateLives(int lives)
{
    playerLives = lives;
}

int Lives::getLivesThreshold()
{
    return livesThreshold;
}

bool Lives::evaluateLives() {
    // if the amount of lives is greater than the threshold, return true
    if (playerLives > livesThreshold) {
        return true;
    }
    // otherwise, return false
    else {
        return false;
    }
}

void Lives::incrementLives1() {
    // add one to playerLives
    playerLives += 1;   
}

void Lives::incrementLives5() {
    // add five to playerLives
    playerLives += 5;
}

void Lives::decrementLives1() {
    // subtract one from playerLives
    if(playerLives >= 1)
    {
        playerLives -= 1;
    }
    else
    {
        playerLives == 0;
    }
}

void Lives::decrementLives5() {
    // subtract five from playerLives
    if(playerLives >= 5)
    {
        playerLives -= 5;
    }
    else
    {
        playerLives == 0;
    }
}

void Lives::incrementLivesRand()
{
    srand(time(0));

    int rand_lives = 0;

    while(rand_lives == 0)
    {
        rand_lives = rand() % 6;
    }

    playerLives += rand_lives;
}

void Lives::decrementLivesRand()
{
    srand(time(0));

    int rand_lives = 0;

    while(rand_lives == 0)
    {
        rand_lives = rand() % 6;
    }

    if(playerLives >= rand_lives)
    {
        playerLives -= rand_lives;
    }
    else
    {
        playerLives == 0;
    }
}