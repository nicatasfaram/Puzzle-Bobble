#pragma once

#include "Bubble.hpp"
#include <string>
 
class ColorBubbles : Bubble
{
public:
	
	ColorBubbles();

	void ciz(Pencere& pencere);

	bool collideShotBubble(Bubble &shotBubble);


	bool tasmaVarmi();

	bool clusterDestroy(int i, int j);


	//void addBubbles(sf::Color renk, sf::Vector2f konum);

	//void ayarla(float yaricap, int pencereGenisligi, int pencereYuksekligi);



private:

	void		clusterDestroy(int i, int j, sf::Color color);

	int			m_randColor;
	
	int			m_satirSayisi;

	int			m_clusterSize;

	std::vector<std::vector<Bubble>> array;

	sf::Color Colors[5] = {	sf::Color::Yellow,
							sf::Color::Red, 
							sf::Color::Blue,
							sf::Color::Green, 
							sf::Color::White };

};


