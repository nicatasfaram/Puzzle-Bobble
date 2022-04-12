#pragma once
#include <SFML/Graphics.hpp>
//#include <map>
#include <functional>

typedef std::function<void(sf::Keyboard::Key)>	KlavyeFonksiyonu;


typedef std::vector<KlavyeFonksiyonu>	KlavyeFonksiyonListesi;

enum class Renk
{
	Red,
	Blue,
	Green,
	Yellow,
	White
};

