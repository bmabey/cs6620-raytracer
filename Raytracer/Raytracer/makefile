APP_NAME   = raytracer
CPP_FLAGS  = -c

$(APP_NAME): main.o Raytracer.o Vector.o Point.o Image.o Sphere.o Group.o HitRecord.o LambertianMaterial.o PinholeCamera.o Plane.o PointLight.o RenderContext.o Scene.o Color.o Disk.o Ring.o Triangle.o Box.o Heightfield.o PhongMaterial.o MetalMaterial.o DielectricMaterial.o BoundingBox.o BVH.o CheckerMaterial.o PhongImageMaterial.o SpherePolar.o PerlinNoise.o PhongMarbleMaterial.o SingleSample.o JitteredSample.o BoxFilter.o TentFilter.o CubicSplineFilter.o Timer.o
	g++ -O2 main.o Raytracer.o Vector.o Point.o Image.o Sphere.o Group.o HitRecord.o LambertianMaterial.o PinholeCamera.o Plane.o PointLight.o RenderContext.o Scene.o Color.o Disk.o Ring.o Triangle.o Box.o Heightfield.o PhongMaterial.o MetalMaterial.o DielectricMaterial.o BoundingBox.o BVH.o CheckerMaterial.o PhongImageMaterial.o SpherePolar.o PerlinNoise.o PhongMarbleMaterial.o SingleSample.o JitteredSample.o BoxFilter.o TentFilter.o CubicSplineFilter.o Timer.o -o $(APP_NAME)

main.o: main.cpp
	g++ $(CPP_FLAGS) main.cpp

Raytracer.o: Raytracer.cpp
	g++ $(CPP_FLAGS) Raytracer.cpp
	
Timer.o: Timer.cpp
	g++ $(CPP_FLAGS) Timer.cpp		
	
Vector.o: Vector.cpp
	g++ $(CPP_FLAGS) Vector.cpp
	
Point.o: Point.cpp
	g++ $(CPP_FLAGS) Point.cpp



Image.o: Image.cpp
	g++ $(CPP_FLAGS) Image.cpp

Sphere.o: Sphere.cpp
	g++ $(CPP_FLAGS) Sphere.cpp
	
Group.o: Group.cpp
	g++ $(CPP_FLAGS) Group.cpp
	
HitRecord.o: HitRecord.cpp
	g++ $(CPP_FLAGS) HitRecord.cpp
	
LambertianMaterial.o: LambertianMaterial.cpp
	g++ $(CPP_FLAGS) LambertianMaterial.cpp
	
PinholeCamera.o: PinholeCamera.cpp
	g++ $(CPP_FLAGS) PinholeCamera.cpp
	
Plane.o: Plane.cpp
	g++ $(CPP_FLAGS) Plane.cpp
	
PointLight.o: PointLight.cpp
	g++ $(CPP_FLAGS) PointLight.cpp
	
RenderContext.o: RenderContext.cpp
	g++ $(CPP_FLAGS) RenderContext.cpp
	
Scene.o: Scene.cpp
	g++ $(CPP_FLAGS) Scene.cpp
	
Color.o: Color.cpp
	g++ $(CPP_FLAGS) Color.cpp
	
Disk.o: Disk.cpp
	g++ $(CPP_FLAGS) Disk.cpp

Ring.o: Ring.cpp
	g++ $(CPP_FLAGS) Ring.cpp

Triangle.o: Triangle.cpp
	g++ $(CPP_FLAGS) Triangle.cpp

Box.o: Box.cpp
	g++ $(CPP_FLAGS) Box.cpp

Heightfield.o: Heightfield.cpp
	g++ $(CPP_FLAGS) Heightfield.cpp

PhongMaterial.o: PhongMaterial.cpp
	g++ $(CPP_FLAGS) PhongMaterial.cpp

MetalMaterial.o: MetalMaterial.cpp
	g++ $(CPP_FLAGS) MetalMaterial.cpp

DielectricMaterial.o: DielectricMaterial.cpp
	g++ $(CPP_FLAGS) DielectricMaterial.cpp

BoundingBox.o: BoundingBox.cpp
	g++ $(CPP_FLAGS) BoundingBox.cpp

BVH.o: BVH.cpp
	g++ $(CPP_FLAGS) BVH.cpp

CheckerMaterial.o: CheckerMaterial.cpp
	g++ $(CPP_FLAGS) CheckerMaterial.cpp

PhongImageMaterial.o: PhongImageMaterial.cpp
	g++ $(CPP_FLAGS) PhongImageMaterial.cpp

SpherePolar.o: SpherePolar.cpp
	g++ $(CPP_FLAGS) SpherePolar.cpp

PerlinNoise.o: PerlinNoise.cpp
	g++ $(CPP_FLAGS) PerlinNoise.cpp

PhongMarbleMaterial.o: PhongMarbleMaterial.cpp
	g++ $(CPP_FLAGS) PhongMarbleMaterial.cpp


JitteredSample.o: JitteredSample.cpp
	g++ $(CPP_FLAGS) JitteredSample.cpp

SingleSample.o: SingleSample.cpp
	g++ $(CPP_FLAGS) SingleSample.cpp

BoxFilter.o: BoxFilter.cpp
	g++ $(CPP_FLAGS) BoxFilter.cpp

TentFilter.o: TentFilter.cpp
	g++ $(CPP_FLAGS) TentFilter.cpp
	
CubicSplineFilter.o: CubicSplineFilter.cpp
	g++ $(CPP_FLAGS) CubicSplineFilter.cpp

explain:
	@echo "APP_NAME   == $(APP_NAME)"
	@echo "CPP_FLAGS  == $(CPP_FLAGS)"

clean:
	rm -f $(APP_NAME)
	rm -f *.o
