#include <QTest>
#include <QPolygonF>
#include <QPointF>
#include <QVector>
#include "TestModule.h"
#include "Core/GeomUtils.h"

using PointVector = QVector<QPointF>;

TestModule::TestModule(QObject *parent) : QObject(parent)
{

}

void TestModule::IsPointTest_data()
{
    QTest::addColumn<QVector<QPointF>>("polygon");
    QTest::addColumn<bool>("result");

    QTest::newRow("test1") << (PointVector{QPointF(1., 1.)}) << true;
    QTest::newRow("test2") << (QPolygonF() << QPointF(1., 1.) << QPointF(1., 1.) << QPointF(1., 1.) << QPointF(1., 1.)) << true;
    QTest::newRow("test3") << PointVector() << false;
    QTest::newRow("test4") << (QPolygonF() << QPointF(1., 1.) << QPointF(1., 2.)) << false;
}

void TestModule::IsPointTest()
{
    QFETCH(QVector<QPointF>, polygon);
    QFETCH(bool, result);
    QVERIFY(IsPoint(polygon) == result);
}

void TestModule::IsLineTest_data()
{
    QTest::addColumn<QVector<QPointF>>("polygon");
    QTest::addColumn<bool>("result");

    QTest::newRow("test1") << PointVector() << false;
    QTest::newRow("test2") << (PointVector{QPointF(1., 1.)}) << false;
    QTest::newRow("test3") << (QPolygonF() << QPointF(1., 1.) << QPointF(1., 1.) << QPointF(1., 1.) << QPointF(1., 1.)) << false;
    QTest::newRow("test4") << (QPolygonF() << QPointF(1., 1.) << QPointF(1., 2.)) << true;
    QTest::newRow("test5") << (QPolygonF() << QPointF(1., 1.) << QPointF(1., 2.) << QPointF(1., 3.)) << true;
}

void TestModule::IsLineTest()
{
    QFETCH(QVector<QPointF>, polygon);
    QFETCH(bool, result);
    QVERIFY(IsLine(polygon) == result);
}

void TestModule::IsTriangleTest_data()
{
    QTest::addColumn<QVector<QPointF>>("polygon");
    QTest::addColumn<bool>("result");

    QTest::newRow("test1") << PointVector() << false;
    QTest::newRow("test2") << PointVector{QPointF(1., 1.)} << false;
    QTest::newRow("test3") << PointVector{QPointF(1., 1.), QPointF(1., 1.), QPointF(1., 1.), QPointF(1., 1.)} << false;
    QTest::newRow("test4") << PointVector{QPointF(1., 1.), QPointF(1., 2.), QPointF(1., 1.)} << false;
    QTest::newRow("test5") << PointVector{QPointF(1., 1.), QPointF(1., 2.), QPointF(1., 3.)} << false;
    QTest::newRow("test6") << PointVector{QPointF(1., 1.), QPointF(1., 2.), QPointF(2., 3.)} << true;
}

void TestModule::IsTriangleTest()
{
    QFETCH(QVector<QPointF>, polygon);
    QFETCH(bool, result);
    QVERIFY(IsTriangle(polygon) == result);
}

void TestModule::IsSquareTest_data()
{

}

void TestModule::IsSquareTest()
{

}


