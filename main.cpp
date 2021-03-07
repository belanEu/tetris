#include <iostream>
#include <bitset>
#include "LTetraminoFigure.h"
#include "JTetraminoFigure.h"
#include "ITetraminoFigure.h"
#include "TTetraminoFigure.h"
#include "ZTetraminoFigure.h"
#include "STetraminoFigure.h"
#include "OTetraminoFigure.h"
#include "Glass.h"
#include "Rotator.h"
#include "Display.h"
#include "Coordinator.h"
#include "Stacker.h"
#include "MovementAnalyzer.h"
#include "MovementMaker.h"
using namespace std;
using namespace tetramino_figure;
using namespace glass;
using namespace controller;

int main()
{
    Glass glassInstance(12, 22);
    MovementMaker movementMaker;
    LTetraminoFigure LFigure(3);
    JTetraminoFigure JFigure(3);
    ITetraminoFigure IFigure(3);
    TTetraminoFigure TFigure(3);
    ZTetraminoFigure ZFigure(3);
    STetraminoFigure SFigure(3);
    OTetraminoFigure OFigure(2);

    Coordinator coordinator(glassInstance.getWidth(), glassInstance.getHeight());

    // step 1: O Figure stays on x=5, y=4
    coordinator.setTetraminoFigureSize(OFigure.getSize());
    coordinator.setXTetraminoFigure(int(glassInstance.getWidth() / 2) - int(OFigure.getSize() / 2) - (OFigure.getSize() & 1));
    coordinator.setYTetraminoFigure(4);

    Stacker::toStack(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepDown(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepDown(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepLeft(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepLeft(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepLeft(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepLeft(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);


    movementMaker.stepLeft(glassInstance, OFigure, coordinator);

    Display::displayGameIteration(glassInstance, coordinator);



    cout << endl << "left rotated L Figure:" << endl << endl;
    Rotator::leftRotate(&LFigure);
    Display::displayFigure(LFigure);
    cout << endl << endl;

    cout << "right rotated J Figure:" << endl << endl;
    Rotator::rightRotate(&JFigure);
    Display::displayFigure(JFigure);
    cout << endl << endl;

    cout << "I Figure:" << endl << endl;
    Display::displayFigure(IFigure);
    cout << endl << endl;

    cout << "T Figure:" << endl << endl;
    Rotator::leftRotate(&TFigure);
    Display::displayFigure(TFigure);
    cout << endl << endl;

    cout << "Z Figure:" << endl << endl;
    Display::displayFigure(ZFigure);
    cout << endl << endl;

    cout << "S Figure:" << endl << endl;
    Display::displayFigure(SFigure);
    cout << endl << endl;

    cout << "O Figure:" << endl << endl;
    Display::displayFigure(OFigure);

    cout << endl << endl;

	return 0;
}
