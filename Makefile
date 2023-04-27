default:
	clang++ application.cpp laser.cpp enemy.cpp player.cpp main.cpp -o galaga -lSDL2 && ./galaga