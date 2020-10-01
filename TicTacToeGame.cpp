#include <iostream.h>
#include <vector.h>
using std::vector;

class Player
{
  public:
    Player(bool isCross)  { m_isCross = isCross ;} 
    bool isCross() { return m_isCross ;} 

private:
    bool m_isCross;
};

class Location
{
public:
    Location(int row, int col)
    {
        if (row >= 0) {
            m_row = row;
        }
        if (col >= 0) {
            m_col = col;
        }
    }

    int row() { return m_row; }
    int col() { return m_col; }
private:
    int m_row = -1;
    int m_col = -1;
};

enum Result {
   Invalid = 0,
   OK,
   Win,
   GameOver
 };

// Square NxN board, win with N consecutive.
class TicTacToe {
public:

  TicTacToe(int N)
  {
    if (N > 0 ) {
      m_N = N;
      m_board.resize(m_N);
      for(int row = 0; row < m_N; row++) {
          m_board[row].resize(m_N);
          for (int col = 0; col < m_N; col++) {
              m_board[row][col] = nullptr;
          }
      }


    }
  }

  ~TicTacToe()
  {
      for (int row = 0; row < m_board.size(); row++) {
          for (int col = 0; col < m_board[row].size(); col++) {
              if (m_board[row][col]) {
                  delete m_board[row][col];
              }
          }
      }
  }

  ///
  /// \brief MakeMove Interface for the game playing system to add a new move to
  /// the game.
  /// \param player   Player making this move.
  /// \param location The selected location on the board.
  /// \return Result of the move, including the new game status such as Win, Invalid, etc.
  ///
  Result MakeMove(Player* player, Location location)
  {
      if (m_gameOver) {
          return Result::GameOver;
      }

      Result result = Result::Invalid;
      if (!isValidLocation(location)) {
          return result;
      }

      m_board[location.row()][location.col()] = player;
      result = Result::OK;

      char output[256];
      sprintf(output, "Player %s placed at row=%d col=%d", (player->isCross() ? "X" : "O"), location.row(), location.col());
      std::cout << output << std::endl;

      if (checkWin(player, location)) {
          result = Result::Win;
          m_gameOver = true;

          char output[256];
          sprintf(output, "Player %s Won the game", (player->isCross() ? "X" : "O"));
          std::cout << output << std::endl;
      }
      return result;
  }

  bool checkWin(Player* player, Location location)
  {
      if (checkHorizontalWin(player, location)) {
          return true;
      }
      if (checkVerticalWin(player, location)) {
          return true;
      }
      if (checkDiagonalWin(player, location)) {
          return true;
      }
      return false;
  }


  bool checkHorizontalWin(Player* player, Location location)
  {
      int row = location.row();
      for (int col = 0; col < m_N; col++) {
          Player* match = m_board[row][col];
          if (match && player->isCross() == match->isCross()) {
          } else {
              return false;
          }
      }
      return true;
  }

  bool checkVerticalWin(Player* player, Location location)
  {
      int col = location.col();
      for (int row = 0; row < m_N; row++) {
          Player* match = m_board[row][col];
          if (match && player->isCross() == match->isCross()) {
          } else {
              return false;
          }
      }
      return true;
  }

  bool checkDiagonalWin(Player* player, Location location)
  {
      int col = 0;
      bool diagonalWin = true;
      for (int row = 0; diagonalWin && row < m_N; row++, col++) {
          Player* match = m_board[row][col];
          if (match && player->isCross() == match->isCross()) {
          } else {
              diagonalWin = false;
          }
      }

      if (diagonalWin) {
          return true;
      }

      col = m_N - 1;
      for (int row = 0; row < m_N; row++, col--) {
          Player* match = m_board[row][col];
          if (match && player->isCross() == match->isCross()) {
          } else {
              return false;
          }
      }
      return true;
  }

  bool isValidLocation(Location location)
  {
      int row = location.row();
      int col = location.col();
      if (row >= 0 && row < m_board.size() &&
          col >= 0 && col < m_board[row].size()) {
      } else {
          return false;
      }

      Player* player = m_board[row][col];
      if (player) {
          return false; // player already placed on this location
      }
      return true;
  }

private:
  /// Create a representation of the game state and any internal structures to help
  /// determine win conditions. The implementation should easily extend to different
  /// board sizes and run time should scale linearly (or better) with N.

  int m_N;
  vector<vector<Player*>> m_board;
  bool m_gameOver = false;
};


int main_game() {
  std::cout << "Starting test!" << std::endl;

  TicTacToe game(3);

 // Add some useful test cases.
  /////////////// ///////////////////////
  Location loc(1, 2);
  Result result = game.MakeMove(new Player(true), loc);

  Location loc1(0, 0);
  result = game.MakeMove(new Player(false), loc1);
  //////////////////////////////////////////////

  Location loc2(1, 0);
  result = game.MakeMove(new Player(true), loc2);

  Location loc3(1, 1);
  result = game.MakeMove(new Player(false), loc3);
  /////////////////////////////////////////////////

  Location loc4(2, 2);
  result = game.MakeMove(new Player(true), loc4);

  Location loc5(0, 2);
  result = game.MakeMove(new Player(false), loc5);

  ////////////////////////////////////////////////////
  Location loc6(0, 1);
  result = game.MakeMove(new Player(true), loc6);

  Location loc7(2, 0);
  result = game.MakeMove(new Player(false), loc7);
   /////////////////////////////////////////////
  Location loc8(2, 1);
  result = game.MakeMove(new Player(true), loc8);
  //////////////////////////////////////////

  // Check result is correct.
 return 0;
}
