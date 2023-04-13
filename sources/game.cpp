#include "player.hpp"
#include "card.hpp"
#include "game.hpp"

/**
 * external libraries
 */
#include <string>
#include <iostream>
#include <algorithm>
#include <random>

using std::vector;
using namespace std;

namespace ariel
{

  Game::Game(Player &player, Player &challenger) : _player0(player), _player1(challenger)
  {
    if (player.stacksize() > 0 || challenger.stacksize() > 0)
    {
      throw std::out_of_range("The Player maximum size start equal to  26 ");
    }
    //---------- Initialization parameters section -----------------------------------
    this->game_over = false;
    this->first_win_rat = 0;
    this->seconed_win_rat = 0;
    this->draw = false;
    this->num_darw = 0;

    // create cards
    for (int i = 1; i <= 13; i++)
    {
      game_stack.push_back(Card("Heart", i));
      game_stack.push_back(Card("Diamond", i));
      game_stack.push_back(Card("Club", i));
      game_stack.push_back(Card("Spade", i));
    }
    //------------- shuffle section ---------------------------------
    // temp vector - helper to shuffle
    vector<Card> cardVec;
    while (!game_stack.empty())
    {
      Card c = game_stack.back();
      cardVec.push_back(c);
      game_stack.pop_back();
    }
    // random
    std::random_device rd;
    // random magic number
    std::mt19937 g(rd());
    // main shuffle
    std::shuffle(cardVec.begin(), cardVec.end(), g);
    //----------------------- end ------------------------------
    /*
      dealing card for each player in the game
    */
    for (const auto &card : cardVec)
    {
      game_stack.push_back(card);
    };
    int i = 0;
    while (!(game_stack.empty()) && i < 26)
    {
      Card c = game_stack.back();
      _player0.push_to_stack(game_stack.back());
      game_stack.pop_back();
      i++;
    }
    while (!(game_stack.empty()))
    {
      Card c = game_stack.back();
      _player1.push_to_stack(game_stack.back());
      game_stack.pop_back();
    }
  };

  // turn rules and logic.
  void Game::playTurn()
  {
    if (_player0.get_name() == _player1.get_name())
    {
      cout << "im not here " << endl;
      throw "player cant play against himself ";
    }

    if (_player0.stacksize() == 0 || _player1.stacksize() == 0)
    {
      throw " there no cards in game ";
    }
    int vwin = 0;
    do
    {
      Card card_player0 = _player0.get_from_stack();

      Card card_player1 = _player1.get_from_stack();

      game_stack.push_back(card_player0);

      game_stack.push_back(card_player1);

      vwin = identifyWinner();

      if (identifyWinner() == 0)
      {
        num_darw++;

        // count the draws
        if (_player0.stacksize() != 0 && _player1.stacksize() != 0)
        {
          game_stack.push_back(_player0.get_from_stack());
          game_stack.push_back(_player1.get_from_stack());
        }
      }
      string loG_details = _player0.get_name() + "  played " + game_stack.at(game_stack.size() - 1).to_string() + "  " + _player1.get_name() + " played " + game_stack.at(game_stack.size() - 2).to_string() + " ," + strResultlastTurn();
      details_ofGame.push_back(loG_details);
      if (_player0.stacksize() == 0 || _player1.stacksize() == 0)
      {
        game_over = true;
      }

    } while (identifyWinner() == 0);
    dividepoints(vwin);
    game_stack.clear();
  };
  // its done
  void Game::printLastTurn()
  {
    // that mean nothing happen and the game not started yet
    if (details_ofGame.empty())
    {
      cout << "there throw exception" << endl;
      throw "The game has not started yet.";
    }
    cout << strResultlastTurn() << endl;
  };
  void Game::playAll()
  {
    // there need validation deponed on tests
    if (&_player0 == &_player1)
    {
      cout << " they cant plays against himself" << endl;
      throw "player can't play against himself ";
    }
    game_getEnd();
    if (game_over)
    {
      throw "game is over";
    }
    while (!game_over)
    {
      playTurn();
    }
  };
  void Game::printWiner()
  {
    if (_player0.cardesTaken() == _player1.cardesTaken())
      cout << "there no winner , its draw " << endl;
    else
    {
      string name = _player0.cardesTaken() > _player1.cardesTaken() ? _player0.get_name() : _player1.get_name();
      cout << name << endl;
    }
  };

  void Game::printLog()
  {
    // print the history of game wining
    if (details_ofGame.empty())
    {
      throw " the game not started yet ";
    }
    for (size_t i = 0; i < details_ofGame.size(); i++)
    {
      cout << details_ofGame[i] << endl;
    }
  };
  string Game::strResultlastTurn()
  {
    if (identifyWinner() == 1)
    {
      return _player0.get_name() + " is the winner";
    }
    else if (identifyWinner() == -1)
    {
      return _player1.get_name() + " is the winner";
    }

    else
    {
      return " there no winner it's Draw !!";
    }
  };
  void Game::game_getEnd()
  {

    if (_player0.empty_stack() || _player1.empty_stack())
    {

      game_over = true;
    }
    game_over = false;
  };
  void Game::printStats()
  {
    string n = "";
    if (_player0.cardesTaken() == _player1.cardesTaken())
    {
      n = "there no winner , its draw ";
    }
    n = _player0.cardesTaken() > _player1.cardesTaken() ? _player0.get_name() : _player1.get_name();
    cout << " the winner is :" << n << " number of draw's in the game  : " << num_darw << endl;
    cout << " first palyer " << _player0.get_name() << " win rate :" << first_win_rat / 100 << endl;
    cout << " seconed palyer " << _player1.get_name() << " win rate :" << seconed_win_rat / 100 << endl;
  };
  int Game::identifyWinner()
  {
    if (game_stack.back().value() < (*(game_stack.end() - 2)).value())
    {
      return -1; // player1
    }
    else if ((game_stack.back()).value() > (*(game_stack.end() - 2)).value())
    {
      return 1; // player0
    }
    else
    {
      return 0;
    }
  };
  void Game::dividepoints(int define)
  {
    if (define == 1)
    {
      _player0.increasCards(game_stack.size() / 2);
      first_win_rat++;
    }

    if (define == -1)
    {
      _player1.increasCards(game_stack.size() / 2);
      seconed_win_rat++;
    }
    if (define == 0)
    {
      _player0.increasCards(game_stack.size());
      _player1.increasCards(game_stack.size());
    }
  };
};