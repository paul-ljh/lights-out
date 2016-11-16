#include "graphicsdisplay.h"
#include <vector>
#include "cell.h"
#include "info.h"
#include <iostream>
#include <utility>
using namespace std;


GraphicsDisplay::GraphicsDisplay(Xwindow &new_x, int new_n): x{new_x}, n{new_n} {
    x.fillRectangle(0, 0, 500, 500, Xwindow::White);
}

GraphicsDisplay::~GraphicsDisplay() {}


void GraphicsDisplay::notify(Subject &whoNotified) {
    Info i = whoNotified.getInfo();

    int fill_row = (500/n)*(i.row);
    int fill_col = (500/n)*(i.col);

    // this is called when the subject cell is modified, then this will fill the corresponding rectangular
    if (i.state) {
        x.fillRectangle(fill_col, fill_row, 500/n, 500/n, Xwindow::Black);
    }
    else {
        x.fillRectangle(fill_col, fill_row, 500/n, 500/n, Xwindow::White);
    }
};


SubscriptionType GraphicsDisplay::subType() const {
    return SubscriptionType::All;
};

