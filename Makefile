OBJS	= Point2D.o GameObject.o Vector2D.o Building.o PokemonCenter.o PokemonGym.o Pokemon.o Model.o View.o GameCommand.o Rival.o BattleArena.o main.o
SOURCE	= Point2D.cpp GameObject.cpp Vector2D.cpp Building.cpp PokemonCenter.cpp PokemonGym.cpp Pokemon.cpp Model.cpp View.cpp, GameCommand.cpp Rival.cpp BattleArena.cpp main.cpp
HEADER	= Point2D.h GameObject.h Vector2D.h Building.h PokemonCenter.h PokemonGym.h Pokemon.h Model.h View.h GameCommand.h Rival.h BattleArena.h
OUT	= PA4
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Point2D.o: Point2D.cpp
	$(CC) $(FLAGS) Point2D.cpp 

GameObject.o: GameObject.cpp
	$(CC) $(FLAGS) GameObject.cpp 

Vector2D.o: Vector2D.cpp
	$(CC) $(FLAGS) Vector2D.cpp 

Building.o: Building.cpp
	$(CC) $(FLAGS) Building.cpp 

PokemonCenter.o: PokemonCenter.cpp
	$(CC) $(FLAGS) PokemonCenter.cpp 

PokemonGym.o: PokemonGym.cpp
	$(CC) $(FLAGS) PokemonGym.cpp 

Pokemon.o: Pokemon.cpp
	$(CC) $(FLAGS) Pokemon.cpp 

Model.o: Model.cpp
	$(CC) $(FLAGS) Model.cpp 

View.o: View.cpp
	$(CC) $(FLAGS) View.cpp

GameCommand.o: GameCommand.cpp
	$(CC) $(FLAGS) GameCommand.cpp 

Rival.o: Rival.cpp
	$(CC) $(FLAGS) Rival.cpp 

BattleArena.o: BattleArena.cpp
	$(CC) $(FLAGS) BattleArena.cpp 

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 
	
clean:
	rm -f $(OBJS) $(OUT)