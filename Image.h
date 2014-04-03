#pragma once
#include <vector>
#include <array>

namespace ImageLib 
{
	class Image
	{
	private:
		const unsigned int width_;
		const unsigned int height_;
	protected:
		std::vector<unsigned char> data_;
		Image(unsigned int width, unsigned int height, int numChannels);
		Image(unsigned int width, unsigned int height, const std::vector<unsigned char> & data);
		Image(unsigned int width, unsigned int height, int numChannels, const unsigned char * data);

	public:
		virtual ~Image() {};

		typedef std::vector<unsigned char>::iterator iterator;
		typedef std::vector<unsigned char>::const_iterator const_iterator;

		/**
		The width of the image
		*/
		inline unsigned int width() const { return width_; }
		/**
		The height of the image
		*/
		inline unsigned int height() const { return height_; }
		/**
		The size in bytes of the imagedata
		*/
		inline size_t size() const { return data_.size(); }

		/**
		The amount of channels an image has
		*/
		virtual int channels() const = 0;

		iterator begin() { return data_.begin(); }
		const_iterator cbegin() const { return data_.cbegin(); }

		iterator end() { return data_.end(); }
		const_iterator cend() const { return data_.cend(); }
	};
}