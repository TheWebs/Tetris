#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::VertexArray quadrado(sf::Triangles, 3);

	// define the position of the triangle's points
	quadrado[0].position = sf::Vector2f(10, 10);
	quadrado[1].position = sf::Vector2f(100, 10);
	quadrado[2].position = sf::Vector2f(100, 100);
	
	sf::Clock clock;
	int teste = 0;
	bool jack = false;
	sf::RenderWindow window(sf::VideoMode(500, 700), "Tetris"/*, sf::Style::None*/); //descomentar para o jogo perder a janela
	std::cout << "O jogo foi iniciado!" << std::endl;
	window.setFramerateLimit(60);
	sf::RectangleShape retangulo((sf::Vector2f(120, 50)));
	retangulo.setFillColor(sf::Color::Blue);
	int x = window.getSize().x;
	int y = window.getSize().y;
	retangulo.setPosition(((x/2)-retangulo.getSize().x/2), ((x/2)-retangulo.getSize().y/2)); //Calculos para ficar ao centro de acordo com tamanho da janela e do rectangulo
	retangulo.setOrigin(retangulo.getSize().x/2, retangulo.getSize().y/2);
	int rotacao = 0;

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Time passado = clock.getElapsedTime();
		if ((int)passado.asSeconds() == teste){}
		else
		{ 
			std::cout << "[" << (int)passado.asSeconds() << "s]" << std::endl;
			std::cout << "Posicao retangulo: (" << retangulo.getPosition().x << "," << retangulo.getPosition().y << ")" << std::endl;
			teste++;
			if (retangulo.getPosition().y != 675) { retangulo.setPosition(retangulo.getPosition().x, retangulo.getPosition().y + 25);}
			if (retangulo.getPosition().y == 675) { retangulo.setFillColor(sf::Color::White);}
			
		}
		window.clear();
		rotacao += 1;
		retangulo.setRotation(rotacao);
		//window.draw(retangulo);
		window.draw(quadrado);
		window.display();
	}

	return 0;
}