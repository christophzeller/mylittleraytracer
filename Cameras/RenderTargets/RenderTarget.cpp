/*
 * RenderTarget.cpp
 *
 *  Created on: 21.02.2015
 *      Author: Christoph
 */

#include "RenderTarget.h"
#include "../../Utility/RGBColor.h"
#include "../../Utility/ViewPlane.h"

RenderTarget::RenderTarget(const ViewPlane& vp)
  : rows(vp.vRes), columns(vp.hRes)
{
	// TODO Auto-generated constructor stub

}

RenderTarget::~RenderTarget() {
	// TODO Auto-generated destructor stub
}

