#pragma once

#include "Bubble.hpp"
#include <string>
 
class ColorBubbles : Bubble
{
public:
	
	ColorBubbles();

	void ciz(Pencere& pencere);

	bool collideShotBubble(Bubble &shotBubble);



	//void addBubbles(sf::Color renk, sf::Vector2f konum);

	//void ayarla(float yaricap, int pencereGenisligi, int pencereYuksekligi);



private:

	//float		m_yaricap;
	int			m_randColor;
	
	int			m_satirSayisi;
	//int			m_sutunSayisi;

	std::vector<std::vector<Bubble>> array;

	sf::Color Colors[5] = {	sf::Color::Yellow,
							sf::Color::Red, 
							sf::Color::Blue,
							sf::Color::Green, 
							sf::Color::White };

};


