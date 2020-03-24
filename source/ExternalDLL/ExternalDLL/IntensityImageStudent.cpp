#include "IntensityImageStudent.h"
// FHU: weet je zeker dat dit netjes afgehandeld is?
// JUS: DONE, alleen een return toegevoegd.
IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	//int throwError = 0, e = 1 / throwError; //Throws error without the need to include a header
	//TODO: Nothing
	return;
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
    // FHU: copy constructor heeft geen self-check nodig. Dat is alleen voor assignment operator.
	// JUS: DONE, ook hier de 'this' check weggehaald. Aangezien dit alleen voor een assignment operator geld.
	imgWidth = other.getWidth();
	imgHeight = other.getHeight();
	pixelStorage = other.pixelStorage;
}

// FHU: je main loop is waarschijnlijk erg traag als je push_back gebruikt. Zoek anders even op hoe je een vector kan pre-alloceren.
// JUS: DONE, pre-alloceren toegevoegd.
IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	imgWidth = width;
	imgHeight = height;
	//fill the pixelstorage
	pixelStorage.reserve( width * height );
	auto newIntensity = Intensity();
	for (int i = 0; i < width * height; i++) {
	    // FHU: Waarom maak je hier elke iteratie van de loop een nieuwe intensity aan?
		// JUS: DONE, Het aanmaken van een nieuwe image eruit gehaald. Dezelfde Intensity kan gebruikt worden,
		// JUS: aangezien we er geen nieuwe waardes instoppen.
		pixelStorage.push_back(newIntensity);
	}
}

// FHU: Kun je deze dan niet beter laten defaulten door de compiler?
// JUS: DONE, deconstructor weggehaald zodat de compiler dit doet.
// IntensityImageStudent::~IntensityImageStudent() {}

void IntensityImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storagenewIntensity)
    // FHU: ik vind dit een erg enge call. De IntensityImage::set method is namelijk pure virtual
    // zou je niet gewoon `set(width, height)` aanroepen zodat het daadwerkelijk op deze class instance gebeurt?
    // de class:: specifier wordt eigenlijk alleen gebruikt voor static methods, dus dit is erg verwarrend.
    // Ik snap eigenlijk niet waarom dit werkt.
	// JUS: DONE, class specifier niet weggehaald. De set functie is NIET virtual. Als je gewoon `set` aanroept krijg je een stack overflow.
	// JUS: Vector wordt wel ge-cleared, en ruimte wordt re-alloceert.
	IntensityImage::set(width, height);
	imgWidth = width;
	imgHeight = height;

	//create a new vector
	pixelStorage.clear();
	pixelStorage.reserve(width * height);
	auto newIntensity = Intensity();

	//fill the vector with empty intensity objects
	// FHU: Zie comments op de loop van de constructor met width, height.
	// JUS: DONE, ook hier de feedback toegepast zoals in de constructor.
	for (int i = 0; i < width * height; i++) {
		pixelStorage.push_back(newIntensity);
	}
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	// FHU: je schrijft hier al wel members over voordat je check wordt uitgevoerd?
	// JUS: DONE, check weggehaald. Dus niet meer van toepassing (?)
	IntensityImage::set(other.getWidth(), other.getHeight());
    // FHU: copy constructor heeft geen self-check nodig. Dat is alleen voor assignment operator.
	// JUS: DONE, check weggehaald.
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

// FHU: ale er geen comment needed is, waarom staat er dan een comment?
// JUS: DONE, comment weggehaald. Comment was eigenlijk onstaan vanuit de docent.
Intensity IntensityImageStudent::getPixel(int x, int y) const {
	auto newPos = y * imgWidth + x;
	return pixelStorage[newPos];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	//TODO: see setPixel(int i, RGB pixel)
	return pixelStorage[i];
}