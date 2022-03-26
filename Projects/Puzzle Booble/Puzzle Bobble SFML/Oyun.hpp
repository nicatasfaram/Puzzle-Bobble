#pragma once
#include "Pencere.hpp"

class Oyun
{
public:
	Oyun();
	~Oyun();
	void setFps(int fps);
	void oyunuBaslat(unsigned int genislik = 640, unsigned int yukseklik = 480);

private:

	void saatiYenidenBaslat();
	void oyunuAyarla();
	void olaylariBagla();
	void cizimFonksiyonu();

	sf::Time	m_gecenSure;
	sf::Time	m_cerceveSuresi;
	sf::Clock	m_saat;


	Pencere		m_pencere;

	int			m_fps;
	unsigned int m_genislik;
	unsigned int m_yukseklik;


};