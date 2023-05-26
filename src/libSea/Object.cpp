#include "Object.h"


namespace Sea {

    Object::Object(Coordinates const & newCoordinates, unsigned int newSize, Sea::Orientation newOrientation)
    : Coordinates(newCoordinates), size(newSize), orientation(newOrientation)
    {
    }

    bool Object::atCoordinates(Coordinates const & coordinates) const
    {
        if (orientation == Sea::Orientation::X) {
            return (getY() == coordinates.getY() && getX() <= coordinates.getX() && (getX() + size) > coordinates.getX());
        }
        else if (orientation == Sea::Orientation::Y) {
            return (getX() == coordinates.getX() && getY() <= coordinates.getY() && (getY() + size) > coordinates.getY());
        }
        return false;
    }

    bool Object::intersectsWith(Object const & otherObject) const
    {
        // TODO Aufgabe 2:
        //  Nutzt die Funktion `atCoordinates(..)`, um zu bestimmen, ob sich dieses und das übergebene Objekt (`otherObject`) überschneiden.
        return false;
        /*
         ???
         */
    }

}
