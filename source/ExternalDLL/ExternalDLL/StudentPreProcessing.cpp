#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include "PixelType.h"
#include <algorithm>




//luminance methode code for converting a colored image to a gray image
//IntensityImage* StudentPreProcessing::stepToIntensityImage(const RGBImage& image) const {
//	IntensityImageStudent* newIntensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
//
//	int loopCount = image.getWidth() * image.getHeight();
//
//	for (int i = 0; i < loopCount; i++)
//	{
//		auto oldRGB = image.getPixel(i);
//		//this is the actual algorithm
//		Intensity newIntensityPixel = ((0.3f *oldRGB.r) + (0.59f*oldRGB.g) + (0.11f*oldRGB.b));
//		newIntensityImage->setPixel(i, newIntensityPixel);
//	}
//
//	return newIntensityImage;
//}

//intensity methode code for converting a colored image to a gray image
//IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
//	IntensityImageStudent* newIntensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());
//
//	int loopCount = image.getWidth() * image.getHeight();
//
//	for (int i = 0; i < loopCount; i++)
//	{
//		auto oldRGB = image.getPixel(i);
//		//this is the actual algorithm
//		Intensity newIntensityPixel = (oldRGB.r + oldRGB.g + oldRGB.b) / 3;
//		newIntensityImage->setPixel(i, newIntensityPixel);
//	}
//
//	return newIntensityImage;
//}

//Value methode code for converting a colored image to a gray image
IntensityImage* StudentPreProcessing::stepToIntensityImage(const RGBImage& image) const {
	IntensityImageStudent* newIntensityImage = new IntensityImageStudent(image.getWidth(), image.getHeight());

	int loopCount = image.getWidth() * image.getHeight();

	for (int i = 0; i < loopCount; i++)
	{
		auto oldRGB = image.getPixel(i);
		//create a list containing the old values
		std::initializer_list<unsigned char> tempVec = { oldRGB.r,oldRGB.g,oldRGB.b };
		//this is the actual algorithm (taking the max, that's it)
		Intensity newIntensityPixel = (std::max(tempVec));
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