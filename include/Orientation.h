#ifndef _INCL_ORIENTATION_H_
#define _INCL_ORIENTATION_H_

struct Coordinate;

struct Orientation
{
    Orientation turnLeft() const;
    Coordinate moveOn(int x, int y, int z) const;
    bool operator==(const Orientation&) const;

    static const Orientation north;
    static const Orientation east;
    static const Orientation south;
    static const Orientation west;

private:
        Orientation(int order, int xFactor, int yFactor);
private:
    int order;
    int xFactor;
    int yFactor;
};

#define N Orientation::north
#define E Orientation::east
#define S Orientation::south
#define W Orientation::west

#endif