#include "StudentPreProcessing.h"
#include "PixelType.h"
#include "ImageFactory.h"
#include <algorithm>

//Value methode code for converting a colored image to a gray image
IntensityImage* StudentPreProcessing::stepToIntensityImage(const RGBImage& image) const {

	IntensityImage* newIntensityImage = ImageFactory::newIntensityImage(image.getWidth(), image.getHeight());

	int loopCount = image.getWidth() * image.getHeight();

	enum class methode { INTENSITY, VALUE, LUMINANCE };
	methode currentMethode = methode::LUMINANCE;

	switch (currentMethode) {

		case methode::INTENSITY:

			for (int i = 0; i < loopCount; i++){
				auto oldRGB = image.getPixel(i);
				Intensity newIntensityPixel = (oldRGB.r + oldRGB.g + oldRGB.b) / 3;
				newIntensityImage->setPixel(i, newIntensityPixel);
			}

			break;

		case methode::VALUE:

			for (int i = 0; i < loopCount; i++){
				auto oldRGB = image.getPixel(i);
				std::initializer_list<unsigned char> tempVec = { oldRGB.r,oldRGB.g,oldRGB.b };
				Intensity newIntensityPixel = (std::max(tempVec));
				newIntensityImage->setPixel(i, newIntensityPixel);
			}

			break;

		case methode::LUMINANCE:
			
			for (int i = 0; i < loopCount; i++){
				auto oldRGB = image.getPixel(i);
				Intensity newIntensityPixel = ((0.3f *oldRGB.r) + (0.59f*oldRGB.g) + (0.11f*oldRGB.b));
				newIntensityImage->setPixel(i, newIntensityPixel);
			}

			break;

		default:
			break;

	}



	return newIntensityImage;

}


IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}