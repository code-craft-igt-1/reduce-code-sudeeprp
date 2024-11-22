#pragma once

#include <cstdint>
#include <memory>
#include "./image.h"

class ImageBrightener {
 private:
    std::shared_ptr<Image> m_inputImage;
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage);
    int BrightenWholeImage();
    bool AddBrighteningImage(std::shared_ptr<Image> imageToAdd, int& attenuatedCount);
};
