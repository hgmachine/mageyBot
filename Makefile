olalcd: Ola_LCD.c
	g++ Ola_LCD.c -o olalcd.out -lwiringPi

Faces:
	g++ face_ident.cpp -o face_ident `pkg-config --cflags --libs opencv4`

clean:
	rm face_ident
	rm olalcd.out
