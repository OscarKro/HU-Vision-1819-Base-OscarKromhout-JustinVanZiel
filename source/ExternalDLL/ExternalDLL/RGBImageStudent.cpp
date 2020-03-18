#include "RGBImageStudent.h"
#include <array>
RGBImageStudent::RGBImageStudent() : RGBImage() {
	//TODO: Nothing
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent& other) : RGBImage(other.getWidth(), other.getHeight()) {
	//TODO: Create a copy from the other object
	if (&other != this) {
		imgWidth = other.getWidth();
		imgHeight = other.getHeight();
		pixelStorage = other.pixelStorage;
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height), imgWidth(width),imgHeight(height) {
	//TODO: Initialize pixel storage 
	imgWidth = width;
	imgHeight = height;
	//fill the pixelstorage
	for (int i = 0; i < width * height; i++) {
		auto newRGB = RGB();
		pixelStorage.push_back(newRGB);
	}
}

RGBImageStudent::~RGBImageStudent() {
	//TODO: delete allocated objects
	//nothing to delete, we don't allocate anything ourselves.
	return;
}

void RGBImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
	RGBImage::set(width, height);
	imgWidth = width;
	imgHeight = height;
	//create a new vector
	std::vector<RGB> newVector; 
	pixelStorage = newVector;
	//fill the vector with empty intensity objects
	for (int i = 0; i < width * height; i++) {
		auto newRGB = RGB();
		pixelStorage.push_back(newRGB);
	}
}

void RGBImageStudent::set(const RGBImageStudent & other) {
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	RGBImage::set(other.getWidth(), other.getHeight());
	if (&other != this) {
		imgWidth = other.getWidth();
		imgHeight = other.getHeight();
		pixelStorage = other.pixelStorage;
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	//TODO: no comment needed :)
	auto newPos = y * imgWidth + x;
	pixelStorage[newPos] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	//TODO: no comment needed :)
	auto newPos = y * imgWidth + x;
	return pixelStorage[newPos];
}

RGB RGBImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixelStorage[i];
}