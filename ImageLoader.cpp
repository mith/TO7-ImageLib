#include "ImageLoader.h"
#define cimg_use_png
#define cimg_use_jpeg
#include "CImg.h"
#include <exception>

using namespace ImageLib;
using namespace cimg_library;

namespace ImageLib
{
	std::unique_ptr<ImageRGB> loadImg(std::string filename)
	{
		CImg<unsigned char> cimg(filename.c_str());

		if (cimg.spectrum() < 3) {
			throw new std::runtime_error("Image is not rgb");
		}

		return std::make_unique<ImageRGB>(cimg.width(), cimg.height(), cimg.begin());
	}

	void saveImg(const ImageGray & img, const std::string filename)
	{
		CImg<unsigned char> cimg(img.data(), img.width(), img.height(), 1, 1);

		cimg.save(filename.c_str());
	}

	void saveImg(const ImageRGB & img, const std::string filename)
	{
		CImg<unsigned char> cimg(img.data(0, 0, Channel::Red), img.width(), img.height(), 1, 3);

		cimg.save(filename.c_str());
	}
}