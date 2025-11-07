#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

#include "Observer.h"

namespace chess
{
    class Observable
    {
    public:
        void addObserver(Observer *);
        void removeObserver(Observer *);
        void updateObservers();

    private:
        std::vector<Observer *> observers;
    };
}

#endif