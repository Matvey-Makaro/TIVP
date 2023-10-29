#pragma once

#include <QObject>

class TestModule : public QObject
{
    Q_OBJECT
public:
    explicit TestModule(QObject *parent = nullptr);

private slots:
    void IsPointTest_data();
    void IsPointTest();

    void IsLineTest_data();
    void IsLineTest();

    void IsTriangleTest_data();
    void IsTriangleTest();

    void IsSquareTest_data();
    void IsSquareTest();
};

