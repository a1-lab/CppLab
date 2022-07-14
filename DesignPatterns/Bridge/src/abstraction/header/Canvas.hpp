#pragma once

#include <CanvasInterface.h>
#include "CanvasImplemetationInterface.h"

class Canvas: public CanvasInterface {
protected:
    CanvasImplemetationInterface *canvas;
public:
    Canvas(CanvasImplemetationInterface *canvasImplementation);
};
