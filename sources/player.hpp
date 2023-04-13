#ifndef CARDWAR_A_PLAYER_HPP
#define CARDWAR_A_PLAYER_HPP

#include "card.hpp"
/**
 * external libraries
 */
#include <stack>
#include <string>
#include <iostream>

using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string _name;
        /*
         number of card's will gain while the game, by default zero.
         */
        int cards_taken = 0;
        /*
         datastructure to contain the cards in game.
        */
        stack<ariel::Card> _stack;
        /*
         size of stack,by default zero .
        */
        int _size = 0;
        /*
         size of stack,by default zero .
        */

    public:
        Player(const string &str);
        /*
            increas Cardstaken
        */
        void increasCards(int score);
        /*
         return size of stack
        */
        int stacksize() const;
        /*
         return number of taken card's
        */
        int cardesTaken();
        /*
        push card's to  stack
        */
        void push_to_stack(const Card &card);
        /*
            return by reference : pop method
        */
        Card get_from_stack();
        /*
          datastructure to contain the cards  that won while the game.
        */
        string get_name();

        bool empty_stack();
    };
};
#endif // CARDWAR_A_PLAYER_HPP
