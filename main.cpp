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
using namespace std;
using namespace tetramino_figure;
using namespace glass;
using namespace controller;

int main()
{
    Glass glass(10, 20);
    LTetraminoFigure LFigure(3);
    JTetraminoFigure JFigure(3);
    ITetraminoFigure IFigure(3);
    TTetraminoFigure TFigure(3);
    ZTetraminoFigure ZFigure(3);
    STetraminoFigure SFigure(3);
    OTetraminoFigure OFigure(2);

    Coordinator coordinator(glass.getWidth(), glass.getHeight());
    coordinator.setTetraminoFigureSize(LFigure.getSize());

    coordinator.setXTetraminoFigure(int(glass.getWidth() / 2) - 1);


    //glass.printOut();

    /*
     TODO: store somewhere a state, which is an array on unsigned short numbers.
     each number represents the corresponding line of the glass.
     then multiply by bitwise operation current and next numbers:
     if ((currentNum & nextNum) == 0)
     {
        -> current number goes lower to the next line
     }
     else
     {
        -> current number stays at the current line
     }
     */
    cout << "The bit set of 5: " << bitset<10>(5).to_string() << endl;
    cout << "The bit set to number: " << (unsigned short)bitset<10>("1111111111").to_ulong() << endl;

    cout << endl << "left rotated L Figure:" << endl << endl;
    Rotator::leftRotate(&LFigure);
    Display::displayFigure(&LFigure);
    cout << endl << endl;

    cout << "right rotated J Figure:" << endl << endl;
    Rotator::rightRotate(&JFigure);
    Display::displayFigure(&JFigure);
    cout << endl << endl;

    cout << "I Figure:" << endl << endl;
    Display::displayFigure(&IFigure);
    cout << endl << endl;

    cout << "T Figure:" << endl << endl;
    Rotator::leftRotate(&TFigure);
    Display::displayFigure(&TFigure);
    cout << endl << endl;

    cout << "Z Figure:" << endl << endl;
    Display::displayFigure(&ZFigure);
    cout << endl << endl;

    cout << "S Figure:" << endl << endl;
    Display::displayFigure(&SFigure);
    cout << endl << endl;

    cout << "O Figure:" << endl << endl;
    Display::displayFigure(&OFigure);
    cout << endl << endl;

	return 0;
}
