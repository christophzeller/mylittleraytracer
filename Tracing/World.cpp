#include "World.h"

#include <iostream>
#include <fstream>

//void World::build()
//{
//	vp.setGamma(1.0);
//	vp.setPixelSize(1.0);
//	vp.setHRes(200);
//	vp.setVRes(200);
//
//	backgroundColor = RGBColor(0.0, 0.0, 0.0);
//
//	sphere.setRadius(85.0);
//	sphere.setCenter(Point3D(0.0, 0.0, 0.0));
//
//	tracer = new SingleSphereTracer(this);
//}

const double World::kHugeValue = 9999999.9;

void World::build()
{
	vp.setGamma(1.0);
	vp.setPixelSize(0.5);
	vp.setHRes(400);
	vp.setVRes(400);

	backgroundColor = RGBColor(0.0, 0.0, 0.0);

	sphere.setRadius(85.0);
	sphere.setCenter(Point3D(0.0, 0.0, 0.0));

	tracer = new MultiObjectsTracer(this);

	RGBColor yellow(1, 1, 0);										// yellow
	RGBColor brown(0.71, 0.40, 0.16);								// brown
	RGBColor dark_green(0.0, 0.41, 0.41);							// dark_green
	RGBColor orange(1.0, 0.75, 0.0);								// orange
	RGBColor green(0.0, 0.6, 0.3);									// green
	RGBColor light_green(0.65, 1.0, 0.30);							// light green
	RGBColor dark_yellow(0.61, 0.61, 0.0);							// dark yellow
	RGBColor light_purple(0.65, 0.3, 1.0);							// light purple
	RGBColor dark_purple(0.5, 0.0, 1.0);							// dark purple

	Sphere*	sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
	sphere_ptr1->setColor(yellow);	   								// yellow
	objects.push_back(sphere_ptr1);

	Sphere*	sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
	sphere_ptr2->setColor(brown);									// brown
	objects.push_back(sphere_ptr2);

	Sphere*	sphere_ptr3 = new Sphere(Point3D(40, 43, -100), 17);
	sphere_ptr3->setColor(dark_green);								// dark green
	objects.push_back(sphere_ptr3);

	Sphere*	sphere_ptr4 = new Sphere(Point3D(-20, 28, -15), 20);
	sphere_ptr4->setColor(orange);									// orange
	objects.push_back(sphere_ptr4);

	Sphere*	sphere_ptr5 = new Sphere(Point3D(-25, -7, -35), 27);
	sphere_ptr5->setColor(green);									// green
	objects.push_back(sphere_ptr5);

	Sphere*	sphere_ptr6 = new Sphere(Point3D(20, -27, -35), 25);
	sphere_ptr6->setColor(light_green);							// light green
	objects.push_back(sphere_ptr6);

	Sphere*	sphere_ptr7 = new Sphere(Point3D(35, 18, -35), 22);
	sphere_ptr7->setColor(green);   								// green
	objects.push_back(sphere_ptr7);

	Sphere*	sphere_ptr8 = new Sphere(Point3D(-57, -17, -50), 15);
	sphere_ptr8->setColor(brown);									// brown
	objects.push_back(sphere_ptr8);

	Sphere*	sphere_ptr9 = new Sphere(Point3D(-47, 16, -80), 23);
	sphere_ptr9->setColor(light_green);							// light green
	objects.push_back(sphere_ptr9);

	Sphere*	sphere_ptr10 = new Sphere(Point3D(-15, -32, -60), 22);
	sphere_ptr10->setColor(dark_green);     						// dark green
	objects.push_back(sphere_ptr10);

	Sphere*	sphere_ptr11 = new Sphere(Point3D(-35, -37, -80), 22);
	sphere_ptr11->setColor(dark_yellow);							// dark yellow
	objects.push_back(sphere_ptr11);

	Sphere*	sphere_ptr12 = new Sphere(Point3D(10, 43, -80), 22);
	sphere_ptr12->setColor(dark_yellow);							// dark yellow
	objects.push_back(sphere_ptr12);

	Sphere*	sphere_ptr13 = new Sphere(Point3D(30, -7, -80), 10);
	sphere_ptr13->setColor(dark_yellow);
	objects.push_back(sphere_ptr13);										// dark yellow (hidden)

	Sphere*	sphere_ptr14 = new Sphere(Point3D(-40, 48, -110), 18);
	sphere_ptr14->setColor(dark_green); 							// dark green
	objects.push_back(sphere_ptr14);

	Sphere*	sphere_ptr15 = new Sphere(Point3D(-10, 53, -120), 18);
	sphere_ptr15->setColor(brown); 								// brown
	objects.push_back(sphere_ptr15);

	Sphere*	sphere_ptr16 = new Sphere(Point3D(-55, -52, -100), 10);
	sphere_ptr16->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr16);

	Sphere*	sphere_ptr17 = new Sphere(Point3D(5, -52, -100), 15);
	sphere_ptr17->setColor(brown);									// browm
	objects.push_back(sphere_ptr17);

	Sphere*	sphere_ptr18 = new Sphere(Point3D(-20, -57, -120), 15);
	sphere_ptr18->setColor(dark_purple);							// dark purple
	objects.push_back(sphere_ptr18);

	Sphere*	sphere_ptr19 = new Sphere(Point3D(55, -27, -100), 17);
	sphere_ptr19->setColor(dark_green);							// dark green
	objects.push_back(sphere_ptr19);

	Sphere*	sphere_ptr20 = new Sphere(Point3D(50, -47, -120), 15);
	sphere_ptr20->setColor(brown);									// browm
	objects.push_back(sphere_ptr20);

	Sphere*	sphere_ptr21 = new Sphere(Point3D(70, -42, -150), 10);
	sphere_ptr21->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr21);

	Sphere*	sphere_ptr22 = new Sphere(Point3D(5, 73, -130), 12);
	sphere_ptr22->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr22);

	Sphere*	sphere_ptr23 = new Sphere(Point3D(66, 21, -130), 13);
	sphere_ptr23->setColor(dark_purple);							// dark purple
	objects.push_back(sphere_ptr23);

	Sphere*	sphere_ptr24 = new Sphere(Point3D(72, -12, -140), 12);
	sphere_ptr24->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr24);

	Sphere*	sphere_ptr25 = new Sphere(Point3D(64, 5, -160), 11);
	sphere_ptr25->setColor(green);					 				// green
	objects.push_back(sphere_ptr25);

	Sphere*	sphere_ptr26 = new Sphere(Point3D(55, 38, -160), 12);
	sphere_ptr26->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr26);

	Sphere*	sphere_ptr27 = new Sphere(Point3D(-73, -2, -160), 12);
	sphere_ptr27->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr27);

	Sphere*	sphere_ptr28 = new Sphere(Point3D(30, -62, -140), 15);
	sphere_ptr28->setColor(dark_purple); 							// dark purple
	objects.push_back(sphere_ptr28);

	Sphere*	sphere_ptr29 = new Sphere(Point3D(25, 63, -140), 15);
	sphere_ptr29->setColor(dark_purple);							// dark purple
	objects.push_back(sphere_ptr29);

	Sphere*	sphere_ptr30 = new Sphere(Point3D(-60, 46, -140), 15);
	sphere_ptr30->setColor(dark_purple); 							// dark purple
	objects.push_back(sphere_ptr30);

	Sphere*	sphere_ptr31 = new Sphere(Point3D(-30, 68, -130), 12);
	sphere_ptr31->setColor(light_purple); 							// light purple
	objects.push_back(sphere_ptr31);

	Sphere*	sphere_ptr32 = new Sphere(Point3D(58, 56, -180), 11);
	sphere_ptr32->setColor(green);									//  green
	objects.push_back(sphere_ptr32);

	Sphere*	sphere_ptr33 = new Sphere(Point3D(-63, -39, -180), 11);
	sphere_ptr33->setColor(green);									// green
	objects.push_back(sphere_ptr33);

	Sphere*	sphere_ptr34 = new Sphere(Point3D(46, 68, -200), 10);
	sphere_ptr34->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr34);

	Sphere*	sphere_ptr35 = new Sphere(Point3D(-3, -72, -130), 12);
	sphere_ptr35->setColor(light_purple);							// light purple
	objects.push_back(sphere_ptr35);

	camera = new OrthographicCamera();

	ambientLight = new AmbientLight();

}

void World::render() //const
{
  camera->renderScene(*this);
}
// kapitel 3
//ShadeRec World::hitObjects(const Ray& ray) //const
//{
//	//ShadeRec sr(*this);
//	ShadeRec sr = ShadeRec(*this);
//
//	double t;
//	double tMin = kHugeValue;
//	int objectCount = objects.size();
//
//	for (int i = 0; i < objectCount; i++)
//	{
//		// object is hit and nearer than the currently held nearest object
//		if (objects[i]->hit(ray, t, sr) && (t < tMin))
//		{
//			sr.isObjectHit = true;
//			tMin = t;
//			sr.color = objects[i]->getColor();
//			//std::cout << "hit " << sr.color << std::endl;
//		}
//	}
//
//	return sr;
//}


ShadeRec World::hitObjects(const Ray& ray) //const
{
  ShadeRec sr = ShadeRec(*this);

  double t;
  double tMin = kHugeValue;
  Normal normal;

  Point3D localHitPoint;

  int objectCount = objects.size();

  for (int i = 0; i < objectCount; i++)
  {
	// object is hit and nearer than the currently held nearest object
	if (objects[i]->hit(ray, t, sr) && (t < tMin))
	{
		sr.isObjectHit = true;
		tMin = t;
		sr.color = objects[i]->getColor();
		//sr.material = objects[i]->material;
		sr.hitPoint = ray.origin + t * ray.direction;
		normal = sr.normal;
		localHitPoint = sr.localHitPoint;
		//std::cout << "hit " << sr.color << std::endl;
	}

	if (sr.isObjectHit)
	{
	  sr.t = tMin;
	  sr.normal = normal;
	  sr.localHitPoint = localHitPoint;
	}
  }

  return sr;
}

void World::paintPixel(const int row, const int column, const RGBColor& color) const
{

}

World::World(void)
{
}


World::~World(void)
{
    if (tracer)
    {
	std::cout << "deleting tracer " << std::endl;
	delete tracer;
    }

    if (camera)
    {
	std::cout << "deleting camera " << std::endl;
	delete camera;
    }

    if (ambientLight)
    {
	std::cout << "deleting ambient light " << std::endl;
	delete ambientLight;
    }

    for (unsigned int i = 0; i < objects.size(); i++)
    {
      std::cout << "deleting " << i << "..." << std::endl;
      delete objects[i];
    }

    objects.clear();
}
