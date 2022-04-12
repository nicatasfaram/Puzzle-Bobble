#include "ColorBubbles.hpp"
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <iostream>

//ColorBubbles::ColorBubbles()
//{
//	srand(time(NULL));
//	
//	sf::Color bubbleColor;
//
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			m_randColor = rand() % 5;
//			if (m_randColor == 0)
//				bubbleColor = sf::Color::Red;
//			else if (m_randColor == 1)
//				bubbleColor = sf::Color::Green;
//			else if (m_randColor == 2)
//				bubbleColor = sf::Color::Blue;
//			else if (m_randColor == 3)
//				bubbleColor = sf::Color::Yellow;
//			else
//				bubbleColor = sf::Color::White;
//
//			m_colorBubbles[i][j] = new Bubble();
//			m_colorBubbles[i][j]->ayarla(40.0f, bubbleColor);
//
//
//			if((j + 1) % 2 == 0)
//				m_colorBubbles[i][j]->m_konum = sf::Vector2f((i*80.0f) + 40.0f, j*(sqrt(3) / 2 * 80.0f));
//			else
//			m_colorBubbles[i][j]->m_konum = sf::Vector2f(i * 80.0f, j * (sqrt(3) / 2 * 80.0f));
//		}
//	}
//}
//
//void ColorBubbles::ciz(Pencere& pencere)
//{
//	for (int i = 0; i < 6; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			m_colorBubbles[i][j]->ciz(pencere);
//		}
//	}
//}
//
//void ColorBubbles::addBubbles(sf::Color renk, sf::Vector2f konum)
//{
//
//	
//
//
//}

ColorBubbles::ColorBubbles()
{
	srand(time(NULL));

	m_satirSayisi = 10;


	for (int i = 0; i < m_satirSayisi; i++)
	{
		std::vector<Bubble> newVector;

		for (int j = 0; j < 6; j++)
		{
			m_randColor = rand() % 5;
			
			Bubble newBubble; 
			newBubble.ayarla(40.0f, Colors[m_randColor]);

			if ((i + 1) % 2 == 0)
				newBubble.m_konum = sf::Vector2f((j * 80.0f) + 80.0f, i * (sqrt(3) / 2 * 80.0f) + 40.0f);
			else
				newBubble.m_konum= sf::Vector2f(j * 80.0f + 40.0f, i * (sqrt(3) / 2 * 80.0f) + 40.0f);

			if (i >= 6)
				newBubble.destroy();

			newVector.push_back(newBubble);
		}
		//m_satirSayisi++;

		array.push_back(newVector);
	}



}

void ColorBubbles::ciz(Pencere& pencere)
{
	for (int i = 0; i < m_satirSayisi; i++) {
		for (int j = 0; j < 6; j++) {
			if(!array[i][j].isDestroyed()) array[i][j].ciz(pencere);
		}
	}
}

bool ColorBubbles::collideShotBubble(Bubble& shotBubble)
{
	for (int i = 0; i < m_satirSayisi; i++) {

		for (int j = 0; j < 6; j++) {

			if (!array[i][j].isDestroyed()) {

				float distance = sqrtf(powf((shotBubble.m_konum.x - array[i][j].m_konum.x), 2) +
					powf((shotBubble.m_konum.y - array[i][j].m_konum.y), 2));

				if (distance <= shotBubble.m_yaricap + array[i][j].m_yaricap) {

					/*Bubble newBubble = shotBubble;

					newBubble.m_konum.x = j * 80.0;
					*/
					array[i + 1][j] = shotBubble;
					
					return true;
				}
			}
		}
		
	}
	return false;
}

//void ColorBubbles::addBubbles(sf::Color renk, sf::Vector2f konum)
//{
//	int sutun = konum.x / (2 * m_yaricap);
//	int satir = konum.y / (2 * m_yaricap);
//
//	Bubble bubble;
//	bubble.ayarla(m_yaricap, renk);
//	bubble.m_konum = sf::Vector2f(sutun * 2 * m_yaricap + m_yaricap,
//								satir * 2 * m_yaricap + m_yaricap);
//
//}

//void ColorBubbles::ayarla(float yaricap, int pencereGenisligi, int pencereYuksekligi)
//{
//	m_sutunSayisi = pencereGenisligi / (2 * (int)yaricap);
//	m_satirSayisi = pencereYuksekligi / (2 * (int)yaricap);
//	m_yaricap = yaricap;
//}
