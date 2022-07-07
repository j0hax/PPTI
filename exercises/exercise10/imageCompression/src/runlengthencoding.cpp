#include "runlengthencoding.h"
#include <algorithm>
#include <iterator>


namespace RunLengthEncoding
{
    void encode(const TGAImage& inputImage, std::ostream& os)
    {
        TGAImageHeader header = inputImage.getHeader();
        header.setCompressed();
        os << header;

        // TODO: Implement here
    }

    TGAImage decode(std::istream& is)
    {
        TGAImage image;
        is >> image.getHeader();
        image.getHeader().setUncompressed();

        // TODO: Implement here

        return image;
    }

    void encode(const std::string& inputFilename, const std::string& outputFilename)
    {
        std::ifstream is(inputFilename, std::ios::in | std::ios::binary);
        TGAImage inputImage;
        is >> inputImage;
        is.close();
        encode(inputImage, outputFilename);
    }

    void encode(const TGAImage& inputImage, const std::string& outputFilename)
    {
        std::ofstream os(outputFilename, std::ios::out | std::ios::binary);
        encode(inputImage, os);
        os.close();
    }

    void decode(const std::string& inputFilename, const std::string& outputFilename)
    {
        std::ofstream os(outputFilename, std::ios::out | std::ios::binary);
        TGAImage inputImage = decode(inputFilename);
        os << inputImage;
        os.close();
    }

    TGAImage decode(const std::string& inputFilename)
    {
        std::ifstream is(inputFilename, std::ios::in | std::ios::binary);
        TGAImage inputImage = decode(is);
        is.close();
        return inputImage;
    }
}

