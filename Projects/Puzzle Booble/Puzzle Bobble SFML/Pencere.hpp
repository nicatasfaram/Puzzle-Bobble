#pragma once
#include<SFML/Graphics.hpp>
#include"TemelTurler.hpp"

class Pencere
{
public:
	Pencere();
	void olustur(unsigned int genislik,
		unsigned int yukseklik,
		sf::String baslik);
	void cizimeBasla();
	void cizimiBitir();
	bool acikmi();
	void olayKontrol();

	void tusBasilmaFonksiyonuEkle(KlavyeFonksiyonu yeniFonk);

	void ciz(sf::Drawable& sekil);
private:

	sf::RenderWindow m_pencere;
	KlavyeFonksiyonListesi	m_tusBasmaFonkListesi;
};
