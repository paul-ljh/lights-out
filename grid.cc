#include <iostream>
#include "grid.h"
using namespace std;

Grid::Grid(): gridSize{0}, td{nullptr}, gd{nullptr} {}

Grid::~Grid() {
    delete td;
}

void Grid::clearGrid() {
    delete td;
    td = nullptr;
    gridSize = 0;
    theGrid.clear();
}

bool Grid::isWon() const {
    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            if (theGrid[i][j].getState() == true) {
                return false;
            }
        }
    }
    return true;
}

void Grid::init(int n, Xwindow &wd) {
    clearGrid();

    // size
    gridSize = n;

    // The text display
    td = new TextDisplay(n);

    // the graphdisplay
    gd = new GraphicsDisplay(wd, n);

    // The actual grid
    for (int i = 0; i < n; ++i) {
        vector<Cell> row;
        theGrid.push_back(row);
        for (int j = 0; j < n; ++j) {
            Cell c;
            c.setCoords(i, j);
            theGrid[i].push_back(c);
        }
    }

    // attach neighbour observers, textdisplay and graphdisplay to each cell
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != 0) {
                theGrid[i][j].attach(&theGrid[i-1][j]);
            }
            if (i != n-1) {
                theGrid[i][j].attach(&theGrid[i+1][j]);
            }
            if (j != 0) {
                theGrid[i][j].attach(&theGrid[i][j-1]);
            }
            if (j != n-1) {
                theGrid[i][j].attach(&theGrid[i][j+1]);
            }
            theGrid[i][j].attach(td);
            theGrid[i][j].attach(gd);
        }
    }
}

void Grid::turnOn(int r, int c) {
  theGrid[r][c].setOn();
}

void Grid::toggle(int r, int c) {
  theGrid[r][c].toggle();
}

void Grid::init(int r, int c) {
    theGrid[r][c].setOn();
}

ostream &operator<<(ostream &out, const Grid &g) {
    out << *(g.td);
    return out;
}


