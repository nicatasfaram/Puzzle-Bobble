#include "Oyun.hpp"
#include <math.h>
#include <iostream>

#define PI 3.14159265


Oyun::Oyun()
{
	m_fps = 60;
	setFps(m_fps);

	m_bubbleYaricap = 40.0f;
	m_bubbleShooted = false;
	

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

		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{

			if (m_shootBubble.m_konum.x - m_shootBubble.m_yaricap <= 0 ||
				m_shootBubble.m_konum.x + m_shootBubble.m_yaricap >= genislik)
				m_shootBubbleSpeed.x *= -1.0f;

			if (m_bubbleShooted) {
				if (m_colorBubbles.collideShotBubble(m_shootBubble)) {
					std::cout << "Collision detect" << std::endl;
					m_shootBubbleSpeed = sf::Vector2f(0.0f, 0.0f);
					m_bubbleShooted = false;

					createShootBubble();
				}
				
				m_shootBubble.m_konum += m_shootBubbleSpeed;
			}

			if (m_colorBubbles.tasmaVarmi())
				oyunuKapat();


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

	m_shootBubblePossition = sf::Vector2f(m_genislik / 2, m_yukseklik - m_bubbleYaricap);

	createShootBubble();

	aimAyarla();

	m_rotation = 180.0f;
	m_aim.setRotation(m_rotation);

	olaylariBagla();

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
		m_aim.setRotation(m_rotation);
	}
	if (tus == sf::Keyboard::Right)
	{
		std::cout << "Right Key pressed" << std::endl;
		m_rotation += 1.0f;
		m_aim.setRotation(m_rotation);
	}

	

}


 void Oyun::saatiYenidenBaslat()
{
	m_saat.restart();
}

 void Oyun::aimAyarla()
 {
	 m_aim.setSize(sf::Vector2f(1.0f, 100.0f));
	 m_aim.setPosition(sf::Vector2f(m_genislik / 2, m_yukseklik - m_shootBubble.m_yaricap));
	 m_aim.setFillColor(sf::Color::White);
 }

void Oyun::createShootBubble()
{
	m_randColor = rand() % 5;

	m_shootBubble.ayarla(m_bubbleYaricap, Colors[m_randColor]);
	m_shootBubble.m_konum = m_shootBubblePossition;
}

void Oyun::cizimFonksiyonu()
{
	m_pencere.cizimeBasla();

	m_colorBubbles.ciz(m_pencere);

	m_shootBubble.ciz(m_pencere);
	
	m_pencere.ciz(m_aim);

	m_pencere.cizimiBitir();
}


void Oyun::oyunuKapat()
{
	m_pencere.kapat();
}
