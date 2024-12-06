#include "./brightener.h"
#include <tuple>

ImageBrightener::ImageBrightener(std::shared_ptr<Image> inputImage): m_inputImage(inputImage) {
}

std::tuple<uint8_t, bool> brightenPixel(uint8_t pixelValue, uint8_t valueToAdd) {
    if (pixelValue > (255 - valueToAdd)) {
        return std::make_tuple(255, true);
    } else {
        return std::make_tuple(pixelValue + valueToAdd, false);
    }
}

int ImageBrightener::BrightenWholeImage() {
    // For brightening, we add a certain grayscale (25) to every pixel.
    // While brightening, some pixels may cross the max brightness. They are
    // called 'attenuated' pixels
    int attenuatedCount = 0;
    m_inputImage->processPixels([&attenuatedCount](uint8_t pixelValue, int, int) {
        auto [brightenedValue, isAttenuated] = brightenPixel(pixelValue, 25);
        attenuatedCount += isAttenuated;
        return brightenedValue;
    });
    return attenuatedCount;
}

std::tuple<bool, int> ImageBrightener::AddBrighteningImage(std::shared_ptr<Image> imageToAdd) {
    if (imageToAdd->m_rows != m_inputImage->m_rows || imageToAdd->m_columns != m_inputImage->m_columns) {
        return std::tuple(false, 0);
    }
    int attenuatedCount = 0;
    m_inputImage->processPixels([&imageToAdd, &attenuatedCount](uint8_t pixelValue, int x, int y) {
        auto [brightenedValue, isAttenuated] = brightenPixel(pixelValue, imageToAdd->getPixelValue(x, y));
        attenuatedCount += isAttenuated;
        return brightenedValue;
    });
    return std::make_tuple(true, attenuatedCount);
}
