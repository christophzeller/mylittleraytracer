#include <iostream>
#include "Tracing/World.h"
#include "Utility/Vector3D.h"


int main(int argc, char** argv)
{
  World w;
  w.build();
  //w.render();
  w.camera->renderScene(w);

  return 0;
}
