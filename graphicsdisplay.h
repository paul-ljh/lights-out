#ifndef GGGG
#define GGGG

#include <iostream>
#include <string>
#include <vector>
#include "window.h"
#include "observer.h"
class Cell;

class GraphicsDisplay: public Observer {
    Xwindow &x;
    int n;

public:
    GraphicsDisplay(Xwindow &new_x, int new_n);

    void notify(Subject &whoNotified) override;
    SubscriptionType subType() const override;

    ~GraphicsDisplay();
};


#endif
