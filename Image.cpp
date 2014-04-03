#include "Image.h"

namespace ImageLib
{
	Image::Image(unsigned int width, unsigned int height, int numChannels)
		: width_(width), height_(height), data_(width * height * numChannels)
	{

	}

	Image::Image(unsigned int width, unsigned int height, int numChannels, const std::vector<unsigned char> & data)
		: width_(width), height_(height), data_(data)
	{
		if (data_.size() < width_ * height_ * numChannels) {
			throw new std::runtime_error("Not enough data for image");
		}
	}

	Image::Image(unsigned int width, unsigned int height, int numChannels, const unsigned char * data)
		: width_(width), height_(height), data_(data, data + width * height * numChannels)
	{
		if (data_.size() < width_ * height_ * numChannels) {
			throw new std::runtime_error("Not enouth data for image");
		}
	}
}