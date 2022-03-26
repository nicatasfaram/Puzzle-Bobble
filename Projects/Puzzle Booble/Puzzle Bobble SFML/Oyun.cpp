#include "Oyun.hpp"
#include "Izgara.hpp"


Izgara izgara;
Oyun::Oyun()
{
	m_fps = 60;
	setFps(m_fps);
	
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
	m_pencere.olustur(genislik, yukseklik, "SFML");

	oyunuAyarla();
	saatiYenidenBaslat();

	sf::CircleShape daire(150);

	
	while (m_pencere.acikmi())
	{
		m_pencere.olayKontrol();

		if (m_saat.getElapsedTime() >= m_cerceveSuresi)
		{
			m_pencere.cizimeBasla();
			izgara.ciz(m_pencere);
			m_pencere.cizimiBitir();
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
	olaylariBagla();
	izgara.ayarla(m_genislik, 20.0f);
}

void Oyun::olaylariBagla()
{

}


void Oyun::saatiYenidenBaslat()
{
	m_saat.restart();
}

void Oyun::cizimFonksiyonu()
{
	m_pencere.cizimeBasla();


	izgara.ciz(m_pencere);


	m_pencere.cizimiBitir();
}
