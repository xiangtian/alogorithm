#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Point
{
public:
    Point(double x, double y)
        : x(x), y(y) {}
    Point() {}
    double x, y;
};

bool compareX(const Point &left, const Point &right)
{
    return left.x < right.x;
}

bool compareY(const Point &left, const Point &right)
{
    return left.y < right.y;
}

double distance(const Point &left, const Point &right)
{
    return sqrt(pow(left.x - right.x, 2) + pow(left.y - right.y, 2));
}

void printVector(const std::vector<Point> &points)
{
    for (std::vector<Point>::const_iterator it = points.begin(); it != points.end(); ++it)
    {
        std::cout << "Point X:" << it->x << " Y:" << it->y << std::endl;
    }
}

double merge(const Point &mid,
             std::vector<Point> &left,
             std::vector<Point> &right,
             double minDis)
{
    std::vector<Point> filterLeft, filterRight;
    for (std::vector<Point>::const_iterator it = left.begin(); it != left.end(); it++)
    {
        if ((mid.x - it->x) < minDis)
        {
            filterLeft.push_back(*it);
        }
    }
    for (std::vector<Point>::const_iterator it = right.begin(); it != right.end(); it++)
    {
        if ((it->x - mid.x) < minDis)
        {
            filterRight.push_back(*it);
        }
    }

    sort(filterRight.begin(), filterRight.end(), compareY);
    printVector(filterLeft);
    printVector(filterRight);
    for (int i = 0; i < filterLeft.size(); i++)
    {
        int idx = 0;
        while (idx < filterRight.size() && filterRight[idx].y < filterLeft[i].y)
        {
            ++idx;
        }
        for (int j = 0; j < 7 && (idx + j) < filterRight.size(); ++j)
        {
            if (distance(filterLeft[i], filterRight[j + idx]) < minDis)
                minDis = distance(filterLeft[i], filterRight[j + idx]);
        }
    }

    return minDis;
}

double closest(std::vector<Point> &points)
{
    if (points.size() == 2)
    {
        return distance(points[0], points[1]);
    }
    if (points.size() == 3)
    {
        return std::min(distance(points[0], points[1]),
                        std::min(distance(points[0], points[1]),
                                 distance(points[1], points[2])));
    }
    //split array into two arrays
    int mid = (points.size() >> 1) - 1;
    std::vector<Point> left(mid + 1), right(points.size() - mid - 1);
    std::copy(points.begin(), points.begin() + mid + 1, left.begin());
    std::copy(points.begin() + mid + 1, points.end(), right.begin());

    double d1 = closest(left);
    double d2 = closest(right);
    double d = std::min(d1, d2);
    return merge(points[mid], left, right, d);
}

int main()
{
    std::vector<Point> points;
    points.push_back(Point(1, 2));
    points.push_back(Point(0, 0));
    points.push_back(Point(2, 2));
    points.push_back(Point(3, 3));
    sort(points.begin(), points.end(), compareX);
    printVector(points);
    std::cout << distance(points[0], points[1]) << std::endl;
    std::cout << closest(points) << std::endl;
}