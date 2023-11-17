#include "Observable.h"

#include <algorithm>

namespace chess
{
    void Observable::addObserver(Observer *observer)
    {
        observers.push_back(observer);
    }

    void Observable::removeObserver(Observer *observer)
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void Observable::updateObservers()
    {
        for (auto observer : observers)
            observer->update();
    }
}