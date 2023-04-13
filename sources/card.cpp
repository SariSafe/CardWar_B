#include "card.hpp"
/**
 * external libraries
 */
#include <string>
#include <iostream>


using namespace std;
namespace ariel
{
    Card::Card(const string &member, int v)
    {
        this->_name = member;
        this->_value = v;
    };
    /*
        about print the properties of Card
    */
    std::string Card::to_string()
    {
        if (_value == 1)
        {

            return "Ace of " + this->_name;
        }
        else if (_value == 11)
        {

            return "Jack of " + this->_name;
        }
        else if (_value == 12)
        {

            return "Queen of " + this->_name;
        }
        else if (_value == 13)
        {

            return "King of " + this->_name;
        }
        else
        {

            return std::to_string(_value) + " of " + this->_name;
        }
    };
    /*
        getters
    */
    const std::string Card::Card_name()
    {
        return this->_name;
    };
    int Card::value()
    {
        return _value;
    };
};