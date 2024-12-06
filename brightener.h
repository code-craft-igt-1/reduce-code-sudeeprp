#pragma once

#include <cstdint>
#include <memory>
#include <tuple>
#include "./image.h"

class ImageBrightener {
 private:
    std::shared_ptr<Image> m_inputImage;
 public:
    explicit ImageBrightener(std::shared_ptr<Image> inputImage);
    int BrightenWholeImage();
    std::tuple<bool, int> AddBrighteningImage(std::shared_ptr<Image> imageToAdd);
};
