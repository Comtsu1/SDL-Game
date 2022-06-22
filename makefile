client: build/main.o build/game.o build/texturemanager.o build/map.o build/vector2d.o build/collision.o build/ecs.o
	g++ -o client build/main.o build/game.o build/texturemanager.o build/map.o build/vector2d.o build/collision.o build/ecs.o -lSDL2main -lSDL2 -lSDL2_image
build/main.o: main.cpp
	g++ -o build/main.o -lSDL2main -lSDL2 -lSDL2_image -c main.cpp
build/game.o: Game.h Game.cpp
	g++ -o build/game.o -lSDL2main -lSDL2 -lSDL2_image -c Game.cpp
build/texturemanager.o: TextureManager.h TextureManager.cpp
	g++ -o build/texturemanager.o -lSDL2main -lSDL2 -lSDL2_image -c TextureManager.cpp
build/map.o: Map.h Map.cpp
	g++ -o build/map.o -lSDL2main -lSDL2 -lSDL2_image -c Map.cpp 
 
build/vector2d.o: Vector2D.cpp Vector2D.h
	g++ -o build/vector2d.o -lSDL2main -lSDL2 -lSDL2_image -c Vector2D.cpp

build/collision.o: Collision.cpp Collision.h
	g++ -o build/collision.o -lSDL2main -lSDL2 -lSDL2_image -c Collision.cpp
build/ecs.o: ECS/ECS.h ECS/ECS.cpp
	g++ -o build/ecs.o -lSDL2main -lSDL2 -lSDL2_image -c ECS/ECS.cpp

clean: 
	rm build/*.o
	rm client

r: clean client
