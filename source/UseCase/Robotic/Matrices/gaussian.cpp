#include <math.h>       /* sqrt, exp */
#include "gaussian.h"

// methods definition
Gaussian::Gaussian() {
	mu = 0;
	sigma2 = 1;
}

Gaussian::Gaussian(float average, float sigma) {
	mu = average;
	sigma2 = sigma;
}

void Gaussian::setMu(float average) {
	mu = average;
}

void Gaussian::setSigma2(float sigma) {
	sigma2 = sigma;
}


float Gaussian::getMu() {
	return mu;
}

float Gaussian::getSigma2() {
	return sigma2;
}

float Gaussian::evaluate(float x) {
	float coefficient;
	float exponential;

	coefficient = 1.0 / sqrt(2.0 * M_PI * sigma2);
	exponential = exp(pow(-0.5 * (x - mu), 2) / sigma2);
	return coefficient * exponential;
}

Gaussian Gaussian::mul(Gaussian other) {
	float denominator;
	float numerator;
	float new_mu;
	float new_var;

	denominator = sigma2 + other.getSigma2();
	numerator = mu * other.getSigma2() + other.getMu() * sigma2;
	new_mu = numerator / denominator;

	new_var = 1.0 / ((1.0 / sigma2) + (1.0 / other.sigma2));

	return Gaussian(new_mu, new_var);
}

Gaussian Gaussian::add(Gaussian other) {

	float new_mu;
	float new_sigma2;

	new_mu = mu + other.getMu();
	new_sigma2 = sigma2 + other.getSigma2();

	return Gaussian(new_mu, new_sigma2);
}