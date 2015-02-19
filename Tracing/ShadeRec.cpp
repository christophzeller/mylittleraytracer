#include "ShadeRec.h"

ShadeRec::ShadeRec(World& wr)
  : isObjectHit(false),
    hitPoint(),
    localHitPoint(),
    normal(),
    color(0.0, 0.0, 0.0),
    w(wr),
    r(),
    recursionDepth(0),
    direction()
{}


ShadeRec::~ShadeRec(void)
{
}
