#include <iostream>
#include <utility>
#include <vector>
#include "textdisplay.h"
#include "cell.h"
#include "info.h"
using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
    for (int i = 0; i < n; ++i) {
        vector<char> row;
        for (int j = 0; j < n; ++j) {
            row.push_back('_');
        }
        theDisplay.push_back(row);
    }
}

void TextDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();
    if (i.state) {
        theDisplay[i.row][i.col] = 'X';
    }
    else {
        theDisplay[i.row][i.col] = '_';
    }
}

TextDisplay::~TextDisplay() {}

SubscriptionType TextDisplay::subType() const {
  return SubscriptionType::All;
}

ostream &operator<<(ostream &out, const TextDisplay &td) {
    for (int i = 0; i < td.gridSize; ++i) {
        for (int j = 0; j < td.gridSize; ++j) {
            out << td.theDisplay[i][j];
        }
        out << endl;
    }
  return out;
}
