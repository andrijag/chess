#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

#include "Observer.h"

namespace chess
{
    class Observable
    {
    private:
        std::vector<Observer *> observers;

    public:
        virtual ~Observable() = default;

        virtual void addObserver(Observer *);
        virtual void removeObserver(Observer *);
        virtual void updateObservers();
    };
}

#endif