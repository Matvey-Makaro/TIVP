#pragma once

#include <QVector>
#include <QPolygonF>
#include <QPointF>
#include <QLineF>


bool IsPoint(const QPolygonF& polygon);
bool IsLine(const QPolygonF& polygon);
bool IsTriangle(const QPolygonF& polygon);
bool IsSquare(const QPolygonF& polygon);
bool IsRectangle(const QPolygonF& polygon);
bool IsRhombus(const QPolygonF& polygon);
bool IsParallelogram(const QPolygonF& polygon);
bool IsTrapezoid(const QPolygonF& polygon);
bool IsQuadrilateral(const QPolygonF& polygon);

double CalculateAngle(const QLineF& l1, const QLineF& l2);
double CalculateDistance(const QPointF& p1, const QPointF& p2);
double CalculateAngleCount(const QPolygonF& polygon);
QVector<double> CalculateAngles(const QPolygonF& polygon);
QVector<double> CalculateDistances(const QPolygonF& polygon);
QPolygonF NormalizeGeometry(const QPolygonF& polygon);
