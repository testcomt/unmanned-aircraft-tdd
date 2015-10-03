#ifndef _INCL_INSTRUCTION_H_
#define _INCL_INSTRUCTION_H_

struct Position;

struct Instruction
{
    virtual void exec(Position&) const = 0; 
    virtual ~Instruction() {}
};

struct Instructions
{
    static Instruction& up();
    static Instruction& down();
    static Instruction& forward();
};

#define UP Instructions::up()
#define DOWN Instructions::down()
#define FORWARD Instructions::forward()

#endif