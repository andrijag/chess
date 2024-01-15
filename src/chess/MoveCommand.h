#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H

namespace chess
{
    class MoveCommand
    {
    public:
        virtual ~MoveCommand() = default;
        virtual void execute() const = 0;
    };
}

#endif