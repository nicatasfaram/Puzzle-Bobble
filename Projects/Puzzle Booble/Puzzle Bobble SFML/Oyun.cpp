#include "Oyun.hpp"
#include <math.h>
#include <iostream>

#define PI 3.14159265

Bubble bubble_red1;
Bubble bubble_red2;

Bubble bubble_green1;
Bubble bubble_green2;

Bubble bubble_blue1;
Bubble bubble_blue2;




Oyun::Oyun()
{

}

Oyun::~Oyun()
{
}

void Oyun::setFps(int fps)
{
	m_cerceveSuresi = sf::seconds(1.0f / m_fps);
}

void Oyun::oyunuBaslat(unsigned int genislik, unsigned int yukseklik)
{
	m_genislik = genislik;
	m_yukseklik = yukseklik;
	m_pencere.olustur(genislik, yukseklik, "Puzzle Bubble");




	oyunuAyarla();
	saatiYenidenBaslat();

	
	while (m_pencere.acikmi())
	{
		m_pencere.olayKontrol();
		m_aim.setRotation(m_rotation);

		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			if (m_bubbleShooted)
				m_shootBubble.m_konum += m_shootBubbleSpeed;

			if (m_shootBubble.m_konum.x <= 0 || m_shootBubble.m_konum.x >= genislik - m_shootBubble.m_yaricap * 2)
				m_shootBubbleSpeed.x *= -1.0f;

			cizimFonksiyonu();
			m_saat.restart();
		}

		else
		{
			sf::sleep(m_cerceveSuresi - m_saat.getElapsedTime());
		}

	}
}

void Oyun::oyunuAyarla()
{

	m_fps = 60;
	setFps(m_fps);

	olaylariBagla();

	m_bubbleYaricap = 20.0f;
	m_bubbleShooted = false;

	m_shootBubblePossition = sf::Vector2f(m_genislik / 2 - m_bubbleYaricap, m_yukseklik - (m_bubbleYaricap * 2));

	createShootBubble();

	m_aim.setSize(sf::Vector2f(1.0f, 100.0f));
	m_aim.setPosition(sf::Vector2f(m_genislik / 2, m_yukseklik - m_shootBubble.m_yaricap));
	m_aim.setFillColor(sf::Color::White);

	m_rotation = 180.0f;

	/*bubble_red1.ayarla(40.0f, sf::Color::Red);
	bubble_red1.m_konum = sf::Vector2f(0.0f, 0.0f);
	bubble_red2.ayarla(40.0f, sf::Color::Red);
	bubble_red2.m_konum = sf::Vector2f(80.0f, 0.0f);

	bubble_green1.ayarla(40.0f, sf::Color::Green);
	bubble_green1.m_konum = sf::Vector2f(40.0f, sqrt(3) / 2 * 80.0f);
	bubble_green2.ayarla(40.0f, sf::Color::Green);
	bubble_green2.m_konum = sf::Vector2f(120.0f, sqrt(3) / 2 * 80.0f);

	bubble_blue1.ayarla(40.0f, sf::Color::Blue);
	bubble_blue1.m_konum = sf::Vector2f(0.0f, 2 * (sqrt(3) / 2 * 80.0f));
	bubble_blue2.ayarla(40.0f, sf::Color::Blue);
	bubble_blue2.m_konum = sf::Vector2f(80.0f, 2 * (sqrt(3) / 2 * 80.0f));*/
		
}

void Oyun::olaylariBagla()
{
	m_pencere.tusBasilmaFonksiyonuEkle(
		std::bind(&Oyun::klavyeBasildi, this, std::placeholders::_1));
}

void Oyun::klavyeBasildi(sf::Keyboard::Key tus)
{
	if (tus == sf::Keyboard::Space || tus == sf::Keyboard::Up)
	{
		std::cout << "Shoot" << std::endl;

		m_bubbleShooted = true;
		m_shootBubbleSpeed.y = -10.0f;

		// -1.0 carpma islemi, hizin x ekseninde dogru yone olmasi icin
		m_shootBubbleSpeed.x = tan((m_rotation - 180) * PI / 180) * m_shootBubbleSpeed.y * -1.0; 
	}
	if (tus == sf::Keyboard::Left)
	{
		std::cout << "Left Key pressed" << std::endl;
		m_rotation -= 1.0f;
	}
	if (tus == sf::Keyboard::Right)
	{
		std::cout << "Right Key pressed" << std::endl;
		m_rotation += 1.0f;
	}

	
	
}




 void Oyun::saatiYenidenBaslat()
{
	m_saat.restart();
}

void Oyun::createShootBubble()
{
	m_shootBubble.ayarla(m_bubbleYaricap, sf::Color::Red);
	m_shootBubble.m_konum = m_shootBubblePossition;
}

void Oyun::cizimFonksiyonu()
{
	m_pencere.cizimeBasla();

	/*bubble_red1.ciz(m_pencere);
	bubble_red2.ciz(m_pencere);
	
	bubble_green1.ciz(m_pencere);
	bubble_green2.ciz(m_pencere);

	bubble_blue1.ciz(m_pencere);
	bubble_blue2.ciz(m_pencere);*/

	m_shootBubble.ciz(m_pencere);
	
	m_pencere.ciz(m_aim);

	m_pencere.cizimiBitir();
}
