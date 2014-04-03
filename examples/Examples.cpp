#include "../ImageLib.h"
using namespace ImageLib;

void setPixel() {
	std::unique_ptr<ImageRGB> img = loadImg("example.jpg");

	// various ways to set pixel in fifth column, second row, red channel to 255:

	img->at(5, 2, Channel::Red) = 255;
	// or
	img->at(5, 2).red = 255;

	// with pointers:

	*(img->data(5, 2).red) = 255;
	// or
	*img->data(5, 2, Channel::Red) = 255;
}


// Convert image to grayscale
std::unique_ptr<ImageGray> grayScale(const ImageRGB & rgb_img)
{
	// create a new empty image with the size of the old image
	auto gray_img = std::make_unique<ImageGray>(rgb_img.width(), rgb_img.height());

	// get pointers to each channel of rgb image
	auto rgb_ptrs = rgb_img.data();

	// iterate through new image
	for (auto i : *gray_img) {
		i = (*rgb_ptrs.red * 0.21) + (*rgb_ptrs.blue * 0.71) + (*rgb_ptrs.green * 0.07);

		rgb_ptrs.red++;
		rgb_ptrs.green++;
		rgb_ptrs.blue++;
	}

	return gray_img;
}