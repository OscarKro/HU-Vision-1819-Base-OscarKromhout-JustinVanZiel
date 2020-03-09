#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include "PixelType.h"

IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	IntensityImageStudent* newIntensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());

	int loopCount = image.getWidth() * image.getHeight();

	for (int i = 0; i < loopCount; i++)
	{
		auto oldRGB = image.getPixel(i);
		Intensity newIntensityPixel = (oldRGB.r + oldRGB.g + oldRGB.b) / 3;
		newIntensityImage->setPixel(i, newIntensityPixel);
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