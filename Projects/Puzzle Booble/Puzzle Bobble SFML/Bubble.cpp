#include "Bubble.hpp"
#include "Pencere.hpp"

Bubble::Bubble()
{

}

void Bubble::ayarla(float yaricap, sf::Color renk)
{
	this->m_yaricap = yaricap;
	this->m_renk = renk;
	m_sekil.setRadius(m_yaricap);
	m_sekil.setFillColor(m_renk);
	//m_sekil.setOutlineThickness(10.0f);
}

void Bubble::ciz(Pencere& pencere)
{
	m_sekil.setPosition(m_konum);
	pencere.ciz(m_sekil);
}