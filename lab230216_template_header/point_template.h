#ifndef POINT_TEMPLATE_H
#define POINT_TEMPLATE_H

template <typename T>
class Point
{
public:
    Point(T x = 0, T y = 0);
    void ShowPosition() const;
private:
    T xpos, ypos;
};

#endif
