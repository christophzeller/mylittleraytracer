#include "GeometricObject.h"


GeometricObject::GeometricObject(void)
{
}


GeometricObject::~GeometricObject(void)
{
	if (material)
		delete material;
}
