#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X)
    turn = O;
  
  else if (turn == O)
    turn = X;
  
  else
    return Invalid; //should never reach here.
    
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  // Out of bounds
  if( row >= BOARDSIZE || row < 0 || column >= BOARDSIZE || column < 0)
    return Invalid;
    
  if(board[row][column] != Blank)
    return board[row][column];
    
  board[row][column] = turn;
  toggleTurn();
  
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  // Out of bounds
  if( row >= BOARDSIZE || row < 0 || column >= BOARDSIZE || column < 0)
    return Invalid;
  
  return board[row][column];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  int counter = 0;
  Piece cur;
  // Check Rows
  for(int i=0; i<BOARDSIZE || counter != 3; i++){
    for(int j=0; j<BOARDSIZE; j++){
      if (getPiece(i,j) == Blank)
        return Invalid;
      
      if (j>0 && getPiece(i,j) != getPiece(i,j-1))
        counter = 0;
        
      counter++;
      cur = getPiece(i,j);
    }
  }
      
  // Check Columns
  for(int j=0; j<BOARDSIZE  || counter != 3; j++){
    for(int i=0; i<BOARDSIZE; i++){
      if (getPiece(i,j) == Blank)
        return Invalid;
      
      if (i>0 && getPiece(i,j) != getPiece(i-1,j))
        counter = 0;
        
      counter++;
      cur = getPiece(i,j);
    }
  }
  
  // Check Diagonal 1
  for(int i=0; i<BOARDSIZE  || counter != 3; i++){
    if (getPiece(i,i) == Blank)
      return Invalid;
    
    if (i>0 && getPiece(i,i) != getPiece(i-1,i-1))
      counter = 0;
      
    counter++;
    cur = getPiece(i,i);
  }
  
  // Check Diagonal 2
  for(int i=BOARDSIZE-1; i>=0  || counter != 3; i--){
    if (getPiece(i,i) == Blank)
      return Invalid;
    
    if (i>0 && getPiece(i,i) != getPiece(i+1,i+1))
      counter = 0;
      
    counter++;
    cur = getPiece(i,i);
  }
  
  if (counter == 0)
    return Blank;
  else
    return cur;
  
}
