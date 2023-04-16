#ifndef CARDWAR_A_CARD_HPP
#define CARDWAR_A_CARD_HPP

/**
 * external libraries
 */
#include <string>
#include <iostream>

using namespace std;
namespace ariel
{
    class Card
    {
    private:
        string _name;
        int _value;

    public:
        Card(const string &name, int value);
        const string Card_name();
        int value();
        std::string to_string();
    };
};
#endif // CARDWAR_A_CARD_HPP
