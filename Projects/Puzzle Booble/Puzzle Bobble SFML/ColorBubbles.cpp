#include "ColorBubbles.hpp"
#include <stdlib.h>
#include <time.h>  
#include <math.h>
#include <iostream>

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
				newBubble.m_konum = sf::Vector2f(j * 80.0f + 40.0f, i * (sqrt(3) / 2 * 80.0f) + 40.0f);

			if (i >= 4)
				newBubble.destroy();

			newVector.push_back(newBubble);
		}

		array.push_back(newVector);
	}



}

void ColorBubbles::ciz(Pencere& pencere)
{
	for (int i = 0; i < m_satirSayisi; i++) {
		for (int j = 0; j < 6; j++) {
			if (!array[i][j].isDestroyed()) array[i][j].ciz(pencere);
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

					if (shotBubble.m_konum.x < array[i][j].m_konum.x)
					{
						if ((i + 1) % 2 == 0)
						{
							array[i + 1][j].m_sekil.setFillColor(shotBubble.m_renk);
							array[i + 1][j].unDestroy();
							if(!tasmaVarmi())
								clusterDestroy(i + 1, j);
						}

						else {
							array[i + 1][j - 1].m_sekil.setFillColor(shotBubble.m_renk);
							array[i + 1][j - 1].unDestroy();
							if(!tasmaVarmi())
								clusterDestroy(i + 1, j - 1);
						}
					}

					if (shotBubble.m_konum.x >= array[i][j].m_konum.x && j<5)
					{
						if ((i + 1) % 2 == 0)
						{
							array[i + 1][j + 1].m_sekil.setFillColor(shotBubble.m_renk);
							array[i + 1][j + 1].unDestroy();
							if(!tasmaVarmi())
								clusterDestroy(i + 1, j + 1);
						}

						else {
							array[i + 1][j].m_sekil.setFillColor(shotBubble.m_renk);
							array[i + 1][j].unDestroy();
							if (!tasmaVarmi())
								clusterDestroy(i + 1, j);
						}
					}

					if (shotBubble.m_konum.x >= array[i][j].m_konum.x && j == 5 ) {
						
							array[i + 1][j].m_sekil.setFillColor(shotBubble.m_renk);
							array[i + 1][j].unDestroy();
							if (!tasmaVarmi())
								clusterDestroy(i + 1, j);
					}

					return true;
				}
			}
		}

	}
	return false;
}

bool ColorBubbles::tasmaVarmi()
{
	for (int j = 0; j < 6; j++) {

		if (!array[9][j].isDestroyed())
			return true;
	}
	return false;
}

void ColorBubbles::clusterDestroy(int i, int j, sf::Color targetColor)
{
	if (i < 0) return;
	if (i >= m_satirSayisi) return;
	if (j < 0) return;
	if (j >= 6) return;
	if (array[i][j].isDestroyed()) return;
	if (array[i][j].m_sekil.getFillColor() != targetColor) return;

	// if function is still going after these if statements then current ball is part of the cluster
	
	this->array[i][j].destroy();

	this->clusterDestroy(i, j - 1, targetColor);
	this->clusterDestroy(i, j + 1, targetColor);
	this->clusterDestroy(i + 1, j, targetColor);
	this->clusterDestroy(i + 1, j-1, targetColor);
	this->clusterDestroy(i + 1, j+1, targetColor);

	this->clusterDestroy(i - 1, j, targetColor);
	this->clusterDestroy(i - 1, j-1, targetColor);
	this->clusterDestroy(i - 1, j+1, targetColor);



}

bool ColorBubbles::clusterDestroy(int i, int j) {

	sf::Color targetColor = this->array[i][j].m_sekil.getFillColor();

	// if cluster contains at least 2 balls of the same color, ammo will make it 3 so destroy that cluster
	if ((i > 0 && !array[i - 1][j].isDestroyed() && array[i - 1][j].m_sekil.getFillColor() == targetColor)
		|| (i < m_satirSayisi && !array[i + 1][j].isDestroyed() && array[i + 1][j].m_sekil.getFillColor() == targetColor)
		|| (j > 0 && !array[i][j - 1].isDestroyed() && array[i][j - 1].m_sekil.getFillColor() == targetColor)
		|| (j < 5 && !array[i][j + 1].isDestroyed() && array[i][j + 1].m_sekil.getFillColor() == targetColor)
		|| (i > 0 && j > 0 && !array[i - 1][j - 1 ].isDestroyed() && array[i - 1][j - 1].m_sekil.getFillColor() == targetColor)
		|| (i > 0 && j < 5 && !array[i - 1][j + 1 ].isDestroyed() && array[i - 1][j + 1].m_sekil.getFillColor() == targetColor)) {

		m_clusterSize = 1;
		clusterDestroy(i, j, targetColor);

		return true;
	}
	return false;
}
