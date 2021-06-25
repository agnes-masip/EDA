#include "Player.hh"


/**
 * Write the name of your player and save this file
 * with the same name and .cc extension.
 */
#define PLAYER_NAME loser


struct PLAYER_NAME : public Player {

  /**
   * Factory: returns a new instance of this class.
   * Do not modify this function.
   */
  static Player* factory () {
    return new PLAYER_NAME;
  }

  /**
   * Types and attributes for your player can be defined here.
   */
  typedef vector<int> VI;
  
  void move_dwarves() {
    VI D = dwarves(me());
    for (int i = 0; i < D.size(); ++i) {
     command(D[i],Top);
    }
  }
  
  void move_wizards() {
  }
  /**
   * Play method, invoked once per each round.
   */
  virtual void play () {
    move_dwarves();
    move_wizards();
  }

};


/**
 * Do not modify the following line.
 */
RegisterPlayer(PLAYER_NAME);
