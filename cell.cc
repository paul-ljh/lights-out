#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"
using namespace std;

Cell::Cell(): r{0}, c{0} {}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const {
    Info i;
    i.row = r;
    i.col = c;
    i.state = isOn;
    return i;
}

// only used in init
void Cell::setOn() {
    isOn = true;
    notifyObservers(SubscriptionType::All);
}

// used for switch
void Cell::toggle() {
    if (isOn == false) {
        isOn = true;
    }
    else {
        isOn = false;
    }
    notifyObservers(SubscriptionType::All);
    notifyObservers(SubscriptionType::SwitchOnly);
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &whoNotified) {
    if (isOn == false) {
        isOn = true;
    }
    else {
        isOn = false;
    }
    notifyObservers(SubscriptionType::All);
}

SubscriptionType Cell::subType() const {
  return SubscriptionType::SwitchOnly;
}
