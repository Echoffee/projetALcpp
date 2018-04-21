#include <SFML/Graphics.hpp>
#include <Shapes/Rectangle.hpp>


#include <Application/App.hpp>
#include <Factories/SFMLApiFactory.hpp>
int main()
{
	/*
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
	*/

	//Rectangle* rect = new Rectangle(10, 10, 25, 30);

	//IShape* copyRect = rect->clone();

	//printf("hello debord\n");

	//while (true) {
	//	//printf("hello world \n");
	//	scanf(NULL);
	//}

	App* app = new App(new SFMLApiFactory());
	app->run();
	return 0;
}