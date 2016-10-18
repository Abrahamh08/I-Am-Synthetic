.PHONY: windows osx linux

windows: ../build/I-Am-Synthetic.exe

linux: ../build/I-Am-Synthetic

osx: ../build/I-Am-Synthetic-osx

../build/I-Am-Synthetic.exe: main.c
	x86_64-w64-mingw32-gcc main.c -I/usr/x86_64-w64-mingw32/include/ -L/usr/x86_64-w64-mingw32/lib -o ../build/I-Am-Synthetic.exe -lglfw3 -lgdi32 -lglew32s -lopengl32

../build/I-Am-Synthetic: main.c
	gcc main.c -o ../build/I-Am-Synthetic -lGLEW -lGL -lglfw3

../build/I-Am-Synthetic-osx: main.c
	gcc main.c  -o ../build/I-Am-Synthetic-osx -framework OpenGL -lGLEW -lglfw3 -g
