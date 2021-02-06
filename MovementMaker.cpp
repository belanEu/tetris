#include "MovementMaker.h"
using namespace controller;
using namespace glass;

void MovementMaker::makeStep(
                             Glass &glassInstance,
                             TetraminoFigure figure,
                             Coordinator &current,
                             Coordinator next
                             )
{
    Stacker::toDelete(glassInstance, figure, current);
    this->movementAnalyzer->analyzeStep(glassInstance, figure, next);
    cout << endl << "Movement Analyzer result: " << this->movementAnalyzer->getResult() << endl;

    if (this->movementAnalyzer->getResult())
    {
        cout << "\n\nhey\n\n";

        current.setTetraminoFigureSize(next.getTetraminoFigureSize());
        current.setXTetraminoFigure(next.getXTetraminoFigure());
        current.setYTetraminoFigure(next.getYTetraminoFigure());
    }

    Stacker::toStack(glassInstance, figure, current);
    this->movementAnalyzer->resetResult();
}

void MovementMaker::stepDown(
                             Glass &glassInstance,
                             TetraminoFigure figure,
                             Coordinator &coordinator
                             )
{
    Coordinator testCoordinator(glassInstance.getWidth(), glassInstance.getHeight());
    testCoordinator.setTetraminoFigureSize(coordinator.getTetraminoFigureSize());
    testCoordinator.setXTetraminoFigure(coordinator.getXTetraminoFigure());
    testCoordinator.setYTetraminoFigure(coordinator.getYTetraminoFigure() + 1);

    this->makeStep(glassInstance, figure, coordinator, testCoordinator);
}

void MovementMaker::stepLeft(
                             Glass &glassInstance,
                             TetraminoFigure figure,
                             Coordinator &coordinator
                             )
{
    Coordinator testCoordinator(glassInstance.getWidth(), glassInstance.getHeight());
    testCoordinator.setTetraminoFigureSize(coordinator.getTetraminoFigureSize());
    testCoordinator.setXTetraminoFigure(coordinator.getXTetraminoFigure() - 1);
    testCoordinator.setYTetraminoFigure(coordinator.getYTetraminoFigure());

    this->makeStep(glassInstance, figure, coordinator, testCoordinator);
}

void MovementMaker::stepRight(
                             Glass &glassInstance,
                             TetraminoFigure figure,
                             Coordinator &coordinator
                             )
{
    Coordinator testCoordinator(glassInstance.getWidth(), glassInstance.getHeight());
    testCoordinator.setTetraminoFigureSize(coordinator.getTetraminoFigureSize());
    testCoordinator.setXTetraminoFigure(coordinator.getXTetraminoFigure() + 1);
    testCoordinator.setYTetraminoFigure(coordinator.getYTetraminoFigure());

    this->makeStep(glassInstance, figure, coordinator, testCoordinator);
}

// TODO: implement rotateLeft and rotateRight methods!
