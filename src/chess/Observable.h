#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>

#include "Observer.h"

namespace chess
{
    class Observable
    {
    public:
        virtual ~Observable() = default;

        virtual void addObserver(Observer *);
        virtual void removeObserver(Observer *);
        virtual void updateObservers();

    private:
        std::vector<Observer *> observers;
    };
}

#endif