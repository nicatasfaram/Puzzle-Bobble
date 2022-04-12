#pragma once
#include "ColorBubbles.hpp"
#include "Bubble.hpp"
#include "Pencere.hpp"
//#include "TemelTurler.hpp"


class Oyun
{
public:
	Oyun();
	~Oyun();
	void setFps(int fps);
	void oyunuBaslat(unsigned int genislik = 520, unsigned int yukseklik = 720);
	void klavyeBasildi(sf::Keyboard::Key tus);
	void oyunuAyarla();
	void olaylariBagla();
	void cizimFonksiyonu();


private:



	void saatiYenidenBaslat();
	void aimAyarla();
	void createShootBubble();

	sf::Time			m_gecenSure;
	sf::Time			m_cerceveSuresi;
	sf::Clock			m_saat;


	Pencere				m_pencere;
	Bubble				m_shootBubble;
	ColorBubbles		m_colorBubbles;
	bool				m_bubbleShooted;
	float				m_bubbleYaricap;
	


	sf::Vector2f		m_shootBubblePossition;
	sf::Vector2f		m_shootBubbleSpeed;


	sf::RectangleShape	m_aim;
	float				m_rotation;


	int					m_fps;
	unsigned int		m_genislik;
	unsigned int		m_yukseklik;

	int					m_randColor;


	sf::Color Colors[5] = { sf::Color::Yellow,
						sf::Color::Red,
						sf::Color::Blue,
						sf::Color::Green,
						sf::Color::White };


};