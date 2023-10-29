#pragma once

#include <QPolygonF>
#include "GeomTypes.h"

class QuadrilateralAnalyzer
{
public:
    QuadrilateralAnalyzer();

    GeomTypes Analyze(const QPolygonF& polygon);
};

