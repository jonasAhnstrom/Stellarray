#include "Game.h"


Game::Game()
{
	_gameCourse.createCourse(/*courseNumber*/ 1, &_gameScene);
	_gameView.setScene(&_gameScene);
	//_gameView.show();
}


Game::~Game()
{
}
