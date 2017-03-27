#include <iostream>
#include <SFML\Graphics.hpp>
#include <time.h>
#include <random>
#include <math.h>

using namespace std;


double unirandi(float start, float end) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(start, end);


	return dist(mt);
}



sf::Color setColor(int hue, float sat, float val) {

	hue %= 360;
	while (hue < 0) hue += 360;

	if (sat < 0.f) sat = 0.f;
	if (sat > 1.f) sat = 1.f;

	if (val < 0.f) val = 0.f;
	if (val > 1.f) val = 1.f;

	int h = hue / 60;
	float f = float(hue) / 60 - h;
	float p = val*(1.f - sat);
	float q = val*(1.f - sat*f);
	float t = val*(1.f - sat*(1 - f));

	switch (h)
	{
	default:
	case 0:
	case 6: return sf::Color(val * 255, t * 255, p * 255);
	case 1: return sf::Color(q * 255, val * 255, p * 255);
	case 2: return sf::Color(p * 255, val * 255, t * 255);
	case 3: return sf::Color(p * 255, q * 255, val * 255);
	case 4: return sf::Color(t * 255, p * 255, val * 255);
	case 5: return sf::Color(val * 255, p * 255, q * 255);
	}
}



float Umap(float value, float istart, float istop, float ostart, float ostop) {

	return ostart + (ostop - ostart)*((value - istart) / (istop - istart));

}

float Unoise(float x, float y, float z) {
	return x;
}

int main() {
	srand(time(NULL));
	float check = 0;
	for (int i = 0; i < 50; i++) {

		float variable = rand() % 100 + 0;
		variable = variable / 100;
		check = Umap(variable, 0, 1, 5, 25);
		
	}
	cin.ignore();

	return 0;
}

