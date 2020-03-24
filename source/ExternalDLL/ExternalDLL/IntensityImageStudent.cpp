#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	return;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	imgWidth = other.getWidth();
	imgHeight = other.getHeight();
	pixelStorage = other.pixelStorage;
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	imgWidth = width;
	imgHeight = height;

	//fill the pixelstorage
	pixelStorage.reserve( width * height );
	auto newIntensity = Intensity();
	for (int i = 0; i < width * height; i++) {
		pixelStorage.push_back(newIntensity);
	}
}

void IntensityImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storagenewIntensity)
	IntensityImage::set(width, height);
	imgWidth = width;
	imgHeight = height;

	//create a new vector
	pixelStorage.clear();
	pixelStorage.reserve(width * height);
	auto newIntensity = Intensity();

	//fill the vector with empty intensity objects
	for (int i = 0; i < width * height; i++) {
		pixelStorage.push_back(newIntensity);
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	IntensityImage::set(other.getWidth(), other.getHeight());
	imgWidth = other.getWidth();
	imgHeight = other.getHeight();
	pixelStorage = other.pixelStorage;
	
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	auto newPos = y * imgWidth + x;
	pixelStorage[newPos] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelStorage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	auto newPos = y * imgWidth + x;
	return pixelStorage[newPos];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixelStorage[i];
}