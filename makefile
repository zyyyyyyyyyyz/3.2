prog : main.o backg.o collision.o  
	gcc *.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer 
main.o :main.c 
	gcc -c *.c -g 




