#ifndef GRID_H
#define GRID_H
#include <iostream>
#include <vector>
#include "cell.h"
#include "piece.h"
#include "subject.h"
#include "enums.h"
#include "graphicsdisplay.h"

class InvalidMove {};
class TextDisplay;
class GraphicsDisplay;

class Grid : public Subject, public Observer {
    std::vector<std::vector<Cell>> grid;
    std::vector<Piece *> black;
    std::vector<Piece *> white;

    TextDisplay *td;  // The text display.
    GraphicsDisplay *gd = nullptr; // Another observer (intent:  graphics)
    void setObserver(Observer *ob);

   public:
    Grid();
    ~Grid();
    void init();
    bool move(Colour colour, int fromR, int fromC, int toR, int toC, Type promotion = Type::NoType);  // move pieceName to toR, toC
    void setPiece(Colour colour, int r, int c, Type type);
    void setPiece(int r, int c, Piece* newPiece);
    Piece* findPiece(Type type, Colour colour);
    bool check(Colour colour, bool check = false);      // check whether side colour is checked
    bool check(Piece* piece, Pos pos);
    bool validateSetup();
    vector<Piece *>& getPieces(Colour colour);
    void removePiece(Piece* piece);
    void removePiece(int r, int c);
    Result checkmate();     // check whether the game is over
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
    void notify(Subject &whoFrom) override;
    // piece: rnbqkpRNBQKP
    Piece* getPiece(int r, int c);  // returns nullptr is there is no piece on it
    Cell& getCell(int r, int c);
};

#endif
