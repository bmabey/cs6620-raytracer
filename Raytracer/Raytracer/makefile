cpp = g++
cpp = gcc
#linux makefile
CFLAGS = -L -g -lpthread -lglut -lGL
FLAGS = -lm -Wno-deprecated
POINTLIB = Point.o
VECTORLIB = Vector.o
RAYLIB = Ray.o
COLORLIB = Color.o
IMAGELIB = Image.o
SPHERELIB = Sphere.o
SPHEREPOLARLIB = SpherePolar.o
DISKLIB = Disk.o
BOXLIB = Box.o
BOUNDINGBOXLIB = BoundingBox.o
RINGLIB = Ring.o
TRIANGLELIB = Triangle.o
PLANELIB = Plane.o
HEIGHTFIELDLIB = Heightfield.o
HITRECORDLIB = HitRecord.o
LAMBERTIANMATERIALLIB = LambertianMaterial.o
PHONGMATERIALLIB = PhongMaterial.o
PHONGMARBLEMATERIALLIB = PhongMarbleMaterial.o
PHONGIMAGEMATERIALLIB = PhongImageMaterial.o
DIELECTRICMATERIALLIB = DielectricMaterial.o
METALMATERIALLIB = MetalMaterial.o
CHECKERMATERIALLIB = CheckerMaterial.o
GROUPLIB = Group.o
BOUNDINGVOLUMEHIERARCHYLIB = BVH.o
POINTLIGHTLIB = PointLight.o
SCENELIB = Scene.o
CONSTANTBACKGROUNDLIB = SolidBackground.o
PINHOLECAMERALIB = PinholeCamera.o
TIMELIB = Timer.o
PERLINNOISELIB = PerlinNoise.o
RAYTRACERLIB = Raytracer.o
BOXFILTERLIB = BoxFilter.o
TENTFILTERLIB = TentFilter.o
CUBICFILTERLIB = CubicSplineFilter.o
JITTEREDSAMPLELIB = JitteredSample.o
SINGLESAMPLELIB = SingleSample.o

OBJECT = $(RAYTRACERLIB) $(VECTORLIB) $(POINTLIB) $(RAYLIB) $(COLORLIB) $(IMAGELIB) $(SPHERELIB) $(SPHEREPOLARLIB) $(VIEWERLIB) $(HITRECORDLIB) $(LAMBERTIANMATERIALLIB)  $(PHONGMATERIALLIB) $(PHONGMARBLEMATERIALLIB) $(PHONGIMAGEMATERIALLIB) $(DIELECTRICMATERIALLIB) $(METALMATERIALLIB) $(CHECKERMATERIALLIB) $(GROUPLIB) $(BOUNDINGVOLUMEHIERARCHYLIB) $(POINTLIGHTLIB) $(SCENELIB) $(CONSTANTBACKGROUNDLIB) $(PINHOLECAMERALIB)  $(PLANELIB) $(HEIGHTFIELDLIB) $(DISKLIB) $(BOXLIB) $(BOUNDINGBOXLIB) $(RINGLIB) $(TRIANGLELIB) $(TIMELIB) $(PERLINNOISELIB) $(BOXFILTERLIB) $(TENTFILTERLIB) $(CUBICFILTERLIB) $(JITTEREDSAMPLELIB) $(SINGLESAMPLELIB) main.o
MFLAGS = -g
EXEC = raytracer

$(EXEC): $(OBJECT)
	$(cpp) $(OBJECT) $(CFLAGS) -o $(EXEC)

$(VECTORLIB): Vector.cpp Vector.h
	$(cpp)  -c Vector.cpp $(MFLAGS)

$(POINTLIB): Point.cpp Point.h
	$(cpp)  -c Point.cpp $(MFLAGS)

$(RAYLIB): Ray.cpp Ray.h
	$(cpp)  -c Ray.cpp $(MFLAGS)

$(COLORLIB): Color.cpp Color.h
	$(cpp)  -c Color.cpp $(MFLAGS)

$(IMAGELIB): Image.cpp Image.h
	$(cpp)  -c Image.cpp $(MFLAGS)

$(SPHERELIB): Sphere.cpp Sphere.h
	$(cpp)  -c Sphere.cpp $(MFLAGS)

$(SPHEREPOLARLIB): SpherePolar.cpp SpherePolar.h
	$(cpp)  -c SpherePolar.cpp $(MFLAGS)

$(DISKLIB): Disk.cpp Disk.h
	$(cpp)  -c Disk.cpp $(MFLAGS)

$(BOXLIB): Box.cpp Box.h
	$(cpp)  -c Box.cpp $(MFLAGS)

$(BOUNDINGBOXLIB): BoundingBox.cpp BoundingBox.h
	$(cpp)  -c BoundingBox.cpp $(MFLAGS)

$(RINGLIB): Ring.cpp Ring.h
	$(cpp)  -c Ring.cpp $(MFLAGS)

$(TRIANGLELIB): Triangle.cpp Triangle.h
	$(cpp)  -c Triangle.cpp $(MFLAGS)

$(PLANELIB): Plane.cpp Plane.h
	$(cpp)  -c Plane.cpp $(MFLAGS)

$(HEIGHTFIELDLIB): Heightfield.cpp Heightfield.h
	$(cpp)  -c Heightfield.cpp $(MFLAGS)

$(VIEWERLIB): Viewer.cpp Viewer.h
	$(cpp)  -c Viewer.cpp $(MFLAGS)

$(HITRECORDLIB): HitRecord.cpp HitRecord.h
	$(cpp)   -c HitRecord.cpp $(MFLAGS)

$(LAMBERTIANMATERIALLIB): LambertianMaterial.cpp LambertianMaterial.h
	$(cpp)   -c LambertianMaterial.cpp $(MFLAGS)

$(PHONGMATERIALLIB): PhongMaterial.cpp PhongMaterial.h
	$(cpp)   -c PhongMaterial.cpp $(MFLAGS)

$(PHONGMARBLEMATERIALLIB): PhongMarbleMaterial.cpp PhongMarbleMaterial.h
	$(cpp)   -c PhongMarbleMaterial.cpp $(MFLAGS)

$(PHONGIMAGEMATERIALLIB): PhongImageMaterial.cpp PhongImageMaterial.h
	$(cpp)   -c PhongImageMaterial.cpp $(MFLAGS)

$(DIELECTRICMATERIALLIB): DielectricMaterial.cpp DielectricMaterial.h
	$(cpp)   -c DielectricMaterial.cpp $(MFLAGS)

$(METALMATERIALLIB): MetalMaterial.cpp MetalMaterial.h
	$(cpp)   -c MetalMaterial.cpp $(MFLAGS)

$(CHECKERMATERIALLIB): CheckerMaterial.cpp CheckerMaterial.h
	$(cpp)   -c CheckerMaterial.cpp $(MFLAGS)

$(GROUPLIB): Group.cpp Group.h
	$(cpp)   -c Group.cpp $(MFLAGS)

$(GRIDDEDGROUPLIB): GriddedGroup.cpp GriddedGroup.h
	$(cpp)   -c GriddedGroup.cpp $(MFLAGS)

$(BOUNDINGVOLUMEHIERARCHYLIB): BVH.cpp BVH.h
	$(cpp)   -c BVH.cpp $(MFLAGS) 


$(POINTLIGHTLIB): PointLight.cpp PointLight.h
	$(cpp)   -c PointLight.cpp $(MFLAGS)

$(SCENELIB): Scene.cpp Scene.h
	$(cpp)   -c Scene.cpp $(MFLAGS) -lpthread

$(CONSTANTBACKGROUNDLIB): SolidBackground.cpp SolidBackground.h
	$(cpp)   -c SolidBackground.cpp $(MFLAGS)

$(PINHOLECAMERALIB): PinholeCamera.cpp PinholeCamera.h
	$(cpp)   -c PinholeCamera.cpp $(MFLAGS)

$(TIMELIB): Timer.cpp Timer.h
	$(cpp)   -c Timer.cpp $(MFLAGS)


$(PERLINNOISELIB): PerlinNoise.cpp PerlinNoise.h
	$(cpp)   -c PerlinNoise.cpp $(MFLAGS)

$(BOXFILTERLIB): BoxFilter.cpp BoxFilter.h
	$(cpp)   -c BoxFilter.cpp $(MFLAGS)
$(TENTFILTERLIB): TentFilter.cpp TentFilter.h
	$(cpp)   -c TentFilter.cpp $(MFLAGS)
$(CUBICFILTERLIB): CubicSplineFilter.cpp CubicSplineFilter.h
	$(cpp)   -c CubicSplineFilter.cpp $(MFLAGS)
$(JITTEREDSAMPLELIB): JitteredSample.cpp JitteredSample.h
	$(cpp)   -c JitteredSample.cpp $(MFLAGS)
$(SINGLESAMPLELIB): SingleSample.cpp SingleSample.h
	$(cpp)   -c SingleSample.cpp $(MFLAGS)	

main.o: main.cpp
	$(cpp) $(MFLAGS) main.cpp -c


clean:
	rm -f *.o *~

run:
	./raytrace

