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
        string strResultlastTurn();
        bool game_over;
        int num_darw;
        int number_turns;

    public:
        int first_num_win;
        int sec_num_win;
        int identifyWinner();
        void dividepoints(int define);
        void game_getEnd();
        Game(Player &player, Player &challenger);
        void playTurn();
        void printLastTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
    };
};
#endif // CARDWAR_A_GAME_HPP
