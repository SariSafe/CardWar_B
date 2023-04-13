/**
 * header file for the Game Object
 * @author Sari Saif
 * @since 2023-03-27
 */

#ifndef CARDWAR_A_GAME_HPP
#define CARDWAR_A_GAME_HPP

#include "player.hpp"

/**
 * external libraries
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <random>


using namespace std;
namespace ariel
{
    class Game
    {
    private:
        Player &_player0;
        Player &_player1;
        bool draw;
        vector<string> details_ofGame;
        vector<Card> game_stack;
        string strResult();
        int seconed_win_rat;
        int first_win_rat;
        bool game_over;
        int num_darw;

    public:
        int identifyWinner();
        void dividepoints(int define);
        void game_getEnd();
        Game(Player &player, Player &challenger);
        void playTurn();
        //  the last element in vector of details_ofGame
        void printLastTurn();
        void playAll();
        void printWiner();
        // print all of strings in vector from the begging to last
        void printLog();
        void printStats();
    };
};
#endif // CARDWAR_A_GAME_HPP
