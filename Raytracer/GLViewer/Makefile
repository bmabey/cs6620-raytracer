APP_NAME   = sampleGUI
CPP_FLAGS  = -c
FRAMEWORKS = -framework OpenGL -framework GLUT -framework Foundation -l GLEW -l GLUI 
#FRAMEWORKS = -framework GLUT
$(APP_NAME): sampleGUI.o 
	g++ -O2 sampleGUI.o  -o $(APP_NAME) $(FRAMEWORKS)

sampleGUI.o: sampleGUI.cpp
	g++ $(CPP_FLAGS) sampleGUI.cpp

explain:
	@echo "APP_NAME   == $(APP_NAME)"
	@echo "CPP_FLAGS  == $(CPP_FLAGS)"
	@echo "FRAMEWORKS == $(FRAMEWORKS)"

clean:
	rm -f $(APP_NAME)
	rm -f *.o