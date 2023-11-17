#ifndef OBSERVER_H
#define OBSERVER_H

namespace chess
{
    class Observer
    {
    public:
        virtual ~Observer() = default;
        virtual void update() = 0;
    };
}

#endif