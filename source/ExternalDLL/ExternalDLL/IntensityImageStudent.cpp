#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	//int throwError = 0, e = 1 / throwError;
	if (&other != this) {
		// Fill image buffer with placeholders
		imgWidth = other.getWidth();
		imgHeight = other.getHeight();
		pixelStorage = other.pixelStorage;
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	//int throwError = 0, e = 1 / throwError;
	imgWidth = width;
	imgHeight = height;
	//fill the pixelstorage
	for (int i = 0; i < width * height; i++) {
		auto newIntensity = Intensity();
		pixelStorage.push_back(newIntensity);
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	//int throwError = 0, e = 1 / throwError;
	//TODO: delete allocated objects
	return;
}

void IntensityImageStudent::set(const int width, const int height) {
	IntensityImage::set(width, height);
	imgWidth = width;
	imgHeight = height;
	std::vector<Intensity> newVector;
	pixelStorage = newVector;

	//TODO: resize or create a new pixel storage (Don't forget to delete the old storagenewIntensity
	for (int i = 0; i < width * height; i++) {
		auto newIntensity = Intensity();
		pixelStorage.push_back(newIntensity);
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	if (&other != this) {
		imgWidth = other.getWidth();
		imgHeight = other.getHeight();
		pixelStorage = other.pixelStorage;
	}
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	auto newPos = y * imgWidth + x;
	pixelStorage[newPos] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	//int throwError = 0, e = 1 / throwError;
	pixelStorage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: no comment needed :)
	auto newPos = y * imgWidth + x;
	return pixelStorage[newPos];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//int throwError = 0, e = 1 / throwError;
	//TODO: see setPixel(int i, RGB pixel)
	return pixelStorage[i];
}