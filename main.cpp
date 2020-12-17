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
using namespace std;
using namespace tetramino_figure;
using namespace glass;
using namespace controller;

int main()
{
    Glass glassInstance(10, 20);
    LTetraminoFigure LFigure(3);
    JTetraminoFigure JFigure(3);
    ITetraminoFigure IFigure(3);
    TTetraminoFigure TFigure(3);
    ZTetraminoFigure ZFigure(3);
    STetraminoFigure SFigure(3);
    OTetraminoFigure OFigure(2);

    Coordinator coordinator(glassInstance.getWidth(), glassInstance.getHeight());

    // step 1: O Figure stays on x=4, y=3
    coordinator.setTetraminoFigureSize(OFigure.getSize());
    coordinator.setXTetraminoFigure(int(glassInstance.getWidth() / 2) - int(OFigure.getSize() / 2) - (OFigure.getSize() & 1));
    coordinator.setYTetraminoFigure(3);

    Stacker::toStack(glassInstance, OFigure, coordinator);

    cout << "x: " << coordinator.getXTetraminoFigure() << ", y: " << coordinator.getYTetraminoFigure() << endl << endl;
    glassInstance.printOut();

    cout << endl << endl << endl;

    // step 2: L Figure stays on x=3, y=0
    coordinator.setTetraminoFigureSize(LFigure.getSize());
    coordinator.setXTetraminoFigure(int(glassInstance.getWidth() / 2) - int(LFigure.getSize() / 2) - (LFigure.getSize() & 1));
    coordinator.setYTetraminoFigure(0);

    Stacker::toStack(glassInstance, LFigure, coordinator);

    cout << "x: " << coordinator.getXTetraminoFigure() << ", y: " << coordinator.getYTetraminoFigure() << endl << endl;
    glassInstance.printOut();

    cout << endl << endl << endl;

    // step 3: L Figure goes to x=3, y=1 using testCoordinator and moves back
    Coordinator testCoordinator(glassInstance.getWidth(), glassInstance.getHeight());
    testCoordinator.setTetraminoFigureSize(coordinator.getTetraminoFigureSize());
    testCoordinator.setXTetraminoFigure(coordinator.getXTetraminoFigure() - 2);
    testCoordinator.setYTetraminoFigure(coordinator.getYTetraminoFigure() + 1);

    MovementAnalyzer movementAnalyzer;

    movementAnalyzer.analyzeStep(glassInstance, LFigure, testCoordinator);


    if (movementAnalyzer.getResult())
    {
        Stacker::toDelete(glassInstance, LFigure, coordinator);

        cout << endl << "Wow!" << endl;
        coordinator.setTetraminoFigureSize(testCoordinator.getTetraminoFigureSize());
        coordinator.setXTetraminoFigure(testCoordinator.getXTetraminoFigure());
        coordinator.setYTetraminoFigure(testCoordinator.getYTetraminoFigure());
        Stacker::toStack(glassInstance, LFigure, coordinator);

        cout << "x: " << coordinator.getXTetraminoFigure() << ", y: " << coordinator.getYTetraminoFigure() << endl << endl;
        glassInstance.printOut();

        cout << endl << endl << endl;
    }

    movementAnalyzer.resetResult();

    /*
       TODO: test MovementAnalyzer!
    */
    /*MovementAnalyzer movementAnalyzer;

    movementAnalyzer.analyzeStep(glassInstance, LFigure, coordinator);
    bool iCanGoThere = movementAnalyzer.getResult();

    if (iCanGoThere)
    {
        // TODO: toStack the figure into the glass
    }

    movementAnalyzer.resetResult();*/


    cout << "The bit set of 5: " << bitset<10>(5).to_string() << endl;
    cout << "The bit set to number: " << (unsigned short)bitset<10>("1111111111").to_ulong() << endl;

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
