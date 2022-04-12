#include "Bubble.hpp"
#include "Pencere.hpp"

Bubble::Bubble()
{
	m_destroyed = false;
}

void Bubble::ayarla(float yaricap, sf::Color renk)
{
	this->m_yaricap = yaricap;
	this->m_renk = renk;
	m_sekil.setRadius(m_yaricap);
	m_sekil.setFillColor(m_renk);
	m_sekil.setOrigin(sf::Vector2f(m_yaricap, m_yaricap));
}

void Bubble::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);
	pencere.ciz(m_sekil);
}

bool Bubble::isDestroyed()
{
	return m_destroyed;
}

void Bubble::destroy()
{
	m_destroyed = true;
}

void Bubble::unDestroy()
{
	m_destroyed = false;
}
