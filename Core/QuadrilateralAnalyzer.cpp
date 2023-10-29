#include "Core/GeomUtils.h"
#include "QuadrilateralAnalyzer.h"

QuadrilateralAnalyzer::QuadrilateralAnalyzer()
{

}

GeomTypes QuadrilateralAnalyzer::Analyze(const QPolygonF &polygon)
{
    if(IsSquare(polygon))
    {
        return GeomTypes::Square;
    }
    else if(IsRectangle(polygon))
    {
        return GeomTypes::Rectangle;
    }
    else if(IsRhombus(polygon))
    {
        return GeomTypes::Rhombus;
    }
    else if(IsParallelogram(polygon))
    {
        return GeomTypes::Parallelogram;
    }
    else if(IsTrapezoid(polygon))
    {
        return GeomTypes::Trapezoid;
    }
    else if(IsQuadrilateral(polygon))
    {
        return GeomTypes::ArbitraryQuadrilateral;
    }
    else if(IsLine(polygon))
    {
        return GeomTypes::Line;
    }
    else if(IsPoint(polygon))
    {
        return GeomTypes::Point;
    }
    return GeomTypes::Unknown;
}
