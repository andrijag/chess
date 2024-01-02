#ifndef VISITABLE_H
#define VISITABLE_H

namespace chess
{
    class Visitor;

    class Visitable
    {
    public:
        virtual ~Visitable() = default;
        virtual void accept(Visitor &) const = 0;
    };
}

#endif