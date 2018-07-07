
#include "21_Clock.h"

Clock::Clock()
{
	std::chrono::steady_clock::time_point previousTime = currentTime;
	std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
	std::chrono::steady_clock::duration deltaTime = currentTime - previousTime;

	text.setCharacterSize(40);
	text.setFillColor(sf::Color(200,200,10));
	text.setOutlineThickness(2);
	text.setOutlineColor(sf::Color::Black);

	count = 0;
	fps = 0;
	fpsCounter = 0;
	averageFps = 0;
	timeCount = 0;
}

Clock::~Clock()
{
	/*chrono::steady_clock::time_point previousTime = currentTime;
	chrono::steady_clock::time_point currentTime = chrono::steady_clock::now();
	chrono::steady_clock::duration deltaTime = currentTime - previousTime;*/
}

void Clock::Update(sf::Font &font)
{
	previousTime = currentTime;
	currentTime = std::chrono::steady_clock::now();
	deltaTime = currentTime - previousTime;

	std::chrono::microseconds mic = std::chrono::duration_cast<std::chrono::microseconds>(deltaTime);

	time = mic.count();
	time = time / 1000000; //this makes it into seconds

	if (time > .2) //5fps
	{
		time = .2;
	}

	fps = 1 / time;

	timeCount = timeCount + time;

	fpsCounter = fpsCounter + fps;

	++count;

	if (timeCount >= 1)
	{
		averageFps = fpsCounter / count;
		count = 0;
		timeCount = 0;
		fpsCounter = 0;
		fpsInt = (int)averageFps;
		text.setFont(font);
		text.setString("Fps: " + std::to_string((int)averageFps));
	}
}

void Clock::Draw(sf::Font &font, sf::RenderWindow &window)
{
	window.draw(text);
}