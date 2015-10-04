#include "Instruction.h"
#include "Coordinate.h"
#include "Orientation.h"

namespace
{
    struct UpInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate& coor, Orientation&) const
        {
            coor = coor.up();
        } 
    };
}

Instruction& Instructions::up()
{
    static UpInstruction up;
    return up;
}

namespace
{
    struct DownInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate& coor, Orientation&) const
        {
            coor = coor.down();
        } 
    };
}

Instruction& Instructions::down()
{
    static DownInstruction down;
    return down;
}

namespace
{
    struct ForwardInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate& coor, Orientation& ori) const
        {
            coor = coor.forward(ori);
        } 
    };
}

Instruction& Instructions::forward()
{
    static ForwardInstruction forward;
    return forward;
}

namespace
{
    struct LeftInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate&, Orientation& ori) const
        {
            ori = ori.turnLeft();
        } 
    };
}

Instruction& Instructions::left()
{
    static LeftInstruction left;
    return left;
}

namespace
{
    struct RightInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate&, Orientation& ori) const
        {
            ori = ori.turnRight();
        } 
    };

}

Instruction& Instructions::right()
{
    static RightInstruction right;
    return right;
}

namespace
{
    struct RoundInstruction : Instruction
    {
    private:
        virtual void exec(Coordinate&, Orientation& ori) const
        {
            ori = ori.turnRound();
        } 
    };

}

Instruction& Instructions::round()
{
    static RoundInstruction round;
    return round;
}

namespace
{
    struct RepeatInstruction : Instruction
    {
        RepeatInstruction() : ins(0), num(0)
        {
        }

        void update(const Instruction& _ins, int n)
        {
            ins = &_ins;
            num = n;
        }

    private:
        virtual void exec(Coordinate& coor, Orientation& ori) const
        {
            if(isOutOfBound()) return;

            for(int i = 0; i < num; ++i)
            {
                ins->exec(coor, ori);
            }
        }

        bool isOutOfBound() const
        {
            return num<0 || num>10;
        }

    private:
        const Instruction* ins;
        int num;        
    };
}

Instruction& Instructions::repeat(const Instruction& ins, int n)
{
    static RepeatInstruction repeat;
    repeat.update(ins,n);
    return repeat;
}