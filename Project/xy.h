#ifndef XY_H
#define XY_H

//pomocnicza struktura
struct XY
{
    XY(){}
    XY(double x, double y)
    {
        this->x = x;
        this->y = y;
    }

    //przeladowanie operatorow
    XY operator+ (XY const& operand)
    {
        XY solution(x + operand.x, y + operand.y);
        return solution;
    }

    XY operator- (XY const& operand)
    {
        XY solution(x - operand.x, y - operand.y);
        return solution;
    }

    XY operator* (XY const& operand)
    {
        XY solution(x * operand.x, y * operand.y);
        return solution;
    }

    void operator+= (XY const& operand)
    {
        XY solution(x + operand.x, y + operand.y);
        x = solution.x;
        y = solution.y;
    }

    void operator-= (XY const& operand)
    {
        XY solution(x - operand.x, y - operand.y);
        x = solution.x;
        y = solution.y;
    }

    void operator*= (XY const& operand)
    {
        XY solution(x * operand.x, y * operand.y);
        x = solution.x;
        y = solution.y;
    }

    bool operator== (XY const& operand)
    {
        if ( x == operand.x && y == operand.y )
            return true;
        return false;
    }

    double x;
    double y;
};

#endif // XY_H
