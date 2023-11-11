// Map.cpp

// CSCI 1300 Fall 2022
// Authors: Seneca Howell & Sam Jarzembowski
// Project 3

#include "Map.h"

using namespace std;

Map::Map()
{
    resetMap();

    // initialize floorplan
}

/*
 * Algorithm: Resets positions of player, NPCs, and rooms and clears map_data_
 * Set Player position coordinates to 0
 * Set npc_count_ to false
 * Set room_count_ to 0
 * loop i from 0 to max_npcs_
 *      Set row and col of location to -1
 * loop i from 0 to max_rooms
 *      Set row and col of room location to -1
 * loop i from 0 to num_rows_
 *      loop j from 0 to num_cols_
 *          Set (i,j) location on map_data_ to '-'
 * Parameters: none
 * Return: nothing (void)
 */
void Map::resetMap()
{
    // resets player position to (2,21)
    player_position_[0] = 1;
    player_position_[1] = 20;

    // set discovery points and reset to not found
    disc_points_[0][0] = 4;
    disc_points_[0][1] = 4;
    disc_points_[0][2] = 0; 
    
    disc_points_[1][0] = 3;
    disc_points_[1][1] = 12;
    disc_points_[1][2] = 0; 

    disc_points_[2][0] = 3;
    disc_points_[2][1] = 27;
    disc_points_[2][2] = 0; 

    disc_points_[3][0] = 6;
    disc_points_[3][1] = 28;
    disc_points_[3][2] = 0; 

    disc_points_[4][0] = 8;
    disc_points_[4][1] = 2;
    disc_points_[4][2] = 0; 

    disc_points_[5][0] = 3;
    disc_points_[5][1] = 19;
    disc_points_[5][2] = 0; 

    disc_points_[6][0] = 12;
    disc_points_[6][1] = 16;
    disc_points_[6][2] = 0; 

    disc_points_[7][0] = 13;
    disc_points_[7][1] = 28;
    disc_points_[7][2] = 0; 

    // set character locations and reset to not found
    char_positions_[0][0] = 1;
    char_positions_[0][1] = 2;
    char_positions_[0][2] = 0;

    char_positions_[1][0] = 2;
    char_positions_[1][1] = 12;
    char_positions_[1][2] = 0;

    char_positions_[2][0] = 2;
    char_positions_[2][1] = 26;
    char_positions_[2][2] = 0;

    char_positions_[3][0] = 9;
    char_positions_[3][1] = 6;
    char_positions_[3][2] = 0;

    char_positions_[4][0] = 13;
    char_positions_[4][1] = 11;
    char_positions_[4][2] = 0;

    char_positions_[5][0] = 10;
    char_positions_[5][1] = 29;
    char_positions_[5][2] = 0;

    // door locations

}

// return player's row position
int Map::getPlayerRow()
{
    return player_position_[0];
}

// return player's column position
int Map::getPlayerCol()
{
    return player_position_[1];
}

// set player position, if in range
void Map::setPlayerPosition(int row, int col)
{
    if (isOnMap(row, col))
    {
        player_position_[0] = row;
        player_position_[1] = col;
    }
}

// returns member variable num_rows_
int Map::getNumRows()
{
    return num_rows_;
}

// returns member variable num_cols_
int Map::getNumCols()
{
    return num_cols_;
}

/*
 * @brief Checks if the given (row, col) position is on the map
 *
 * Algorithm:
 *  if 0 <= row < num_rows_ and 0 <= col < num_cols_:
 *      return true
 *  else:
 *      return false
 *
 * Parameters: row (int), col (int)
 * Returns: bool
 */
bool Map::isOnMap(int row, int col)
{
    if (0 <= row && row < num_rows_ && 0 <= col && col < num_cols_)
    {
        return true;
    }
    return false;
}

/*
Algorithm:
If position is a wall character, return true
Otherwise, return false
*/
bool Map::isWallLocation(int row, int col)
{
    char maybe_wall;
    
    maybe_wall = blank_map[row][col];
    
    if(maybe_wall == '|' || maybe_wall == '-')
    {
        return true;
    }
    else
    {
        return false;
    }
}

/*
 * Algorithm: Checks if the location is an NPC location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to npc_count_
 *      if (row,col) is a npc location
 *          return true
 * return true
 * Parameters: row (int), col (int)
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isCharLocation(int row, int col)
{
    if (blank_map[row][col] == CHARACTER)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/*
 * Algorithm: Checks if the location is an room location
 * if (row, col) is not within the map boundaries
 *      return false
 * loop i from 0 to room_count_
 *      if (row,col) is a room location
 *          return true
 * return true
 * Parameters: row (int), col (int)
 * return false
 * Parameters: none
 * Return: boolean (bool)
 */
bool Map::isDoorLocation(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    for (int i = 0; i < 6; i++)
    {
        if (row == door_positions_[i][0] && col == door_positions_[i][1])
        {
            return true;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column is an explored space
 * if (row, col) is not on the map:
 *     return false
 * if map_data_[row][col] is ' ':
 *     return true
 * if (row, col) is npc location and has been found:
 *     return true
 * else:
 *     return false
 */
bool Map::isExplored(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (map_data_[row][col] == EXPLORED)
    {
        return true;
    }
    for (int i = 0; i < 6; i++)
    {
        if (char_positions_[i][0] == row && char_positions_[i][1] == col)
        {
            if (char_positions_[i][2] == true)
            {
                return true;
            }
            break;
        }
    }
    return false;
}

/*
 * Algorithm: Checks if the given row and column is a discovery point
 * if (row, col) is not on the map:
 *     return false
 * if map_data_[row][col] is 'o':
 *     return true
 * if (row, col) is npc location and has been found:
 *     return true
 * else:
 *     return false
 */
bool Map::isDiscPoint(int row, int col)
{
    if (blank_map[row][col] == DISCOVERYPOINT)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

/*
 * Algorithm: Checks if the given row and column on map is a free space
 * if row and column is not within the map boundaries
 *      return false
 * if row and column is a npc location
 *      return false
 * if row and column is a room location
 *      return false
 * if row and column is the dungeon exit
 *      return false
 * return true
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
bool Map::isFreeSpace(int row, int col)
{
    if (!isOnMap(row, col))
    {
        return false;
    }
    if (isCharLocation(row, col))
    {
        return false;
    }
    if (isDoorLocation(row, col))
    {
        return false;
    }
    if (isDiscPoint(row,col)) 
    {
        return false;
    }
    return true;
}

/*
 * Algorithm: Removes a discovery point from the map
 1. Passes the given row and column an explored discovery point is located at as parameters
 2. Changes the character on the map at that point to an EXPLORED (blank) character
 */
void Map::removePoint(int row, int col)
{
    blank_map[row][col] = EXPLORED;
}


/*
 * Algorithm: Mark (row, col) as explored, either revealing NPC or empty space
 * if (row, col) is NPC location
 *      mark npc at player_position_ as found
 * else if (row, col) is a free space
 *      mark space as explored in map data
 *
 * Parameters: row (int), col (int)
 * Return: boolean (bool)
 */
void Map::exploreSpace(int row, int col)
{
    for (int i = 0; i < 6; i++)
    {
        if (row == char_positions_[i][0] && col == char_positions_[i][1])
        {
            // mark NPC as found
            char_positions_[i][2] = 1;
            return;
        }
    }
    if (isFreeSpace(row, col))
    {
        map_data_[player_position_[0]][player_position_[1]] = EXPLORED;
    }
}

/*
 * Algorithm: Make the player move based on the given command
 * if user inputs w and if its not the top row of the map
 *      Move the player up by one row
 * if user inputs s and if its not the bottom row of the map
 *      Move the player down by one row
 * if user inputs a and if its not the leftmost column
 *      Move the player left by one column
 * if user inputs d and if its not the rightmost column
 *      Move the player right by one column
 * if player moved
 *      if new location is an NPC location
 *          mark new location as explored
 *      return true
 * else
 *      return false
 *
 * Parameters: direction (char)
 * Return: boolean (bool)
 */
bool Map::move(char direction)
{
    // check input char and move accordingly
    switch (tolower(direction))
    {
    case 'w': // if user inputs w, move up if it is an allowed move
        if (player_position_[0] > 0 && (blank_map[player_position_[0] - 1][player_position_[1]]) != WALLS && (blank_map[player_position_[0] - 1][player_position_[1]] != WALLS2))
        {
            player_position_[0] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 's': // if user inputs s, move down if it is an allowed move
        if (player_position_[0] < num_rows_ - 1 && (blank_map[player_position_[0] + 1][player_position_[1]]) != WALLS && (blank_map[player_position_[0] + 1][player_position_[1]] != WALLS2))
        {
            player_position_[0] += 1;
        }
        else
        {
            return false;
        }
        break;
    case 'a': // if user inputs a, move left if it is an allowed move
        if (player_position_[1] > 0 && (blank_map[player_position_[0]][player_position_[1] - 1]) != WALLS && (blank_map[player_position_[0]][player_position_[1] - 1] != WALLS2))
        {
            player_position_[1] -= 1;
        }
        else
        {
            return false;
        }
        break;
    case 'd': // if user inputs d, move right if it is an allowed move
        if (player_position_[1] < num_cols_ - 1 && (blank_map[player_position_[0]][player_position_[1] + 1]) != WALLS && (blank_map[player_position_[0]][player_position_[1] + 1] != WALLS2))
        {
            player_position_[1] += 1;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
    }
    // if new location is an NPC location, mark as explored
    if (isCharLocation(player_position_[0], player_position_[1]))
    {
        exploreSpace(player_position_[0], player_position_[1]);
    }
    return true;

    // if location is a discovery point
}

/*
 * Algorithm: This function prints a 2D map in the terminal.
 * Loop i from 0 to number of rows
 *      Loop j from 0 to number of columns
 *          if player position is at (i,j)
 *              print 'X'
 *          else
 *              print the value of (i,j) in map_data_
 *
 * Parameters: none
 * Return: nothing (void)
 */
void Map::displayMap()
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if (player_position_[0] == i && player_position_[1] == j)
            {
                cout << PLAYER;
            }
            else
            {
                cout << blank_map[i][j];
            }
        }

        cout << endl;
    }
}