#include "subject.h"
#include "observer.h"
#include "subscriptions.h"
using namespace std;

void Subject::attach(Observer *o) {
    observers.push_back(o);
}

void Subject::notifyObservers(SubscriptionType t) {
    for (auto &ob:observers) {
        if (ob->subType() == t) {
            ob->notify(*this);
        }
    }

}

