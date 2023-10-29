#include <cmath>
#include "GeomUtils.h"

bool isEqual(double lhs, double rhs, double eps = 0.0001)
{
    return std::fabs(lhs - rhs) < eps;
}

bool IsPoint(const QPolygonF& polygon)
{
    if(polygon.size() == 0)
        return false;


    for(const auto& p : polygon)
    {
        if(p != polygon[0])
            return false;
    }
    return true;
}

bool IsLine(const QPolygonF& polygon)
{
    if(polygon.size() < 2)
        return false;

    if(IsPoint(polygon))
        return false;

    for(int i = 0; i < polygon.size() - 2; i++)
    {
        const auto& p1 = polygon[i];
        const auto& p2 = polygon[i + 1];
        const auto& p3 = polygon[i + 2];

        auto angle = CalculateAngle(QLineF(p1, p2), QLineF(p2, p3));
        if(!isEqual(angle, 0) && !isEqual(angle, 180))
            return false;
    }
    return true;
}

bool IsTriangle(const QPolygonF& polygon)
{
    auto angleCount = CalculateAngleCount(polygon);
    constexpr int AngleCountInTriangle = 3;
    return angleCount == AngleCountInTriangle;
}

bool IsSquare(const QPolygonF& polygon)
{
    if(!IsQuadrilateral(polygon))
        return false;

    auto angles = CalculateAngles(polygon);
    auto distances = CalculateDistances(polygon);

    constexpr double angleForSquare = 90.;
    for(const auto angle : angles)
    {
        if(!isEqual(angle, angleForSquare))
            return false;
    }
    for(const auto d : distances)
    {
        if(!isEqual(d, distances[0]))
            return false;
    }
    return true;
}

bool IsRectangle(const QPolygonF& polygon)
{
    if(!IsQuadrilateral(polygon))
        return false;

    auto distances = CalculateDistances(polygon);
    for(const auto d : distances)
    {
        if(!isEqual(d, distances[0]))
            return false;
    }
    return true;
}

bool IsRhombus(const QPolygonF& polygon)
{
    if(!IsQuadrilateral(polygon))
        return false;

    auto angles = CalculateAngles(polygon);
    auto distances = CalculateDistances(polygon);

    constexpr double angleForRectangle = 90.;
    for(const auto angle : angles)
    {
        if(!isEqual(angle, angleForRectangle))
            return false;
    }

    return distances[0] == distances[2] &&
            distances[1] == distances[3];
}

bool IsParallelogram(const QPolygonF &polygon)
{
    if(!IsQuadrilateral(polygon))
        return false;

    auto angles = CalculateAngles(polygon);
    return angles[0] == angles[2] && angles[1] == angles[3];
}

bool IsTrapezoid(const QPolygonF& polygon)
{
    if(!IsQuadrilateral(polygon))
        return false;

    auto angles = CalculateAngles(polygon);
    return (angles[0] + angles[1] == angles[2] + angles[3]) || (angles[1] + angles[2] == angles[0] + angles[3]);
}

bool IsQuadrilateral(const QPolygonF& polygon)
{
    if(polygon.size() != 5)
        return false;

    if(IsPoint(polygon) || IsLine(polygon))
        return false;

    return true;
}

double CalculateAngle(const QLineF& l1, const QLineF& l2)
{
    return l1.angleTo(l2);
}

double CalculateDistance(const QPointF& p1, const QPointF& p2)
{
    return QLineF(p1, p2).length();
}

double CalculateAngleCount(const QPolygonF& polygon)
{
    int angleCount = 0;
    int size = polygon.size();
    for(int i = 0; i < size; i++)
    {
        const auto& p1 = polygon[i % size];
        const auto& p2 = polygon[(i + 1) % size];
        const auto& p3 = polygon[(i + 2) % size];

        auto angle = CalculateAngle(QLineF(p1, p2), QLineF(p2, p3));
        if(!isEqual(angle, 0) && !isEqual(angle, 180))
            angleCount++;
    }
    return angleCount;
}

QVector<double> CalculateAngles(const QPolygonF& polygon)
{
    QVector<double> angles;
    auto size = polygon.size();
    for(int i = 0; i < size; i++)
    {
        const auto& p1 = polygon[i % size];
        const auto& p2 = polygon[(i + 1) % size];
        const auto& p3 = polygon[(i + 2) % size];

        auto angle = CalculateAngle(QLineF(p1, p2), QLineF(p2, p3));
        angles.push_back(angle);
    }
    return angles;
}

QVector<double> CalculateDistances(const QPolygonF &polygon)
{
    QVector<double> distances;
    for(int i = 0; i < polygon.size() - 1; i++)
    {
        distances.push_back(CalculateDistance(polygon[i], polygon[i + 1]));
    }
    return distances;
}

QPolygonF NormalizeGeometry(const QPolygonF &polygon)
{
    // TODO: Impl
}
