#include "card.hpp"
#include "player.hpp"
/**
 * external libraries
 */
#include <exception>
#include <stack>
#include <string>
#include <iostream>

using namespace std;
namespace ariel
{
    Player::Player(const string &str) : _name(str), _stack(std::stack<Card>())
    {
        if (str == "")
        {
            throw "there no one to play with";
        }
        this->_size = _stack.size();
        this->cards_taken = 0;
    };
    Card Player::get_from_stack()
    {

        
        Card current = this->_stack.top();
        _stack.pop();
        _size--;
        return current;
    };
    void Player::push_to_stack(const Card &card)
    {
        _stack.push(card);
        _size++;
    };
    int Player::stacksize() const { return _size; };
    string Player::get_name()
    {
        return _name;
    };
    int Player::cardesTaken() { return this->cards_taken; };
    void Player::increasCards(int score)
    {
        this->cards_taken += score;
    }
    bool Player::empty_stack()
    {
        return _stack.empty();
    }
};
