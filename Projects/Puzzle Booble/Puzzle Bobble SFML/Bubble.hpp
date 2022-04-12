#pragma once
#include "Cizilebilir.hpp"


class Bubble: public Cizilebilir
{
public:
	Bubble();

	void ayarla(float yaricap,sf::Color renk);
	virtual void ciz(Pencere& pencere) override;

	sf::Vector2f m_konum;
	sf::CircleShape m_sekil;
	float m_yaricap;
	sf::Color m_renk;

	bool isDestroyed();

	void destroy();
	void unDestroy();



private:

	bool m_destroyed;
};
