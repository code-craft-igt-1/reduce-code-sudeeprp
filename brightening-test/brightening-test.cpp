#include <gtest/gtest.h>
#include <memory>
#include "../brightener.h"

namespace brighteningtest {

class BrighteningTest : public ::testing::Test {
 protected:
    std::shared_ptr<Image> image;
    void SetUp() override {
    }
    void TearDown() override {
    }
};

std::shared_ptr<Image> initImage4x4(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4) {
    auto image = std::make_shared<Image>(2, 2);
    image->pixels[0] = p1; image->pixels[1] = p2;
    image->pixels[2] = p3; image->pixels[3] = p4;
    return image;
}

TEST_F(BrighteningTest, BrightensWholeImage) {
    image = initImage4x4(45, 55, 65, 254);

    ImageBrightener brightener(image);
    int attenuatedCount = brightener.BrightenWholeImage();

    EXPECT_EQ(attenuatedCount, 1);         // Verify the number of attenuated pixels
    EXPECT_EQ(image->pixels[2], 90);      // Verify the expected brightened pixel value
}

TEST_F(BrighteningTest, BrightensWithAnotherImage) {
    image = initImage4x4(45, 255, 65, 25);

    ImageBrightener brightener(image);

    auto brighteningImage = std::make_shared<Image>(2, 2);
    brighteningImage->pixels[0] = 0; brighteningImage->pixels[1] = 25;
    brighteningImage->pixels[2] = 0; brighteningImage->pixels[3] = 25;

    auto [succeeded, attenuatedCount] = brightener.AddBrighteningImage(brighteningImage);

    EXPECT_TRUE(succeeded);               // Check if the operation succeeded
    EXPECT_EQ(image->pixels[0], 45);      // Verify the left-side pixel is unchanged
    EXPECT_EQ(image->pixels[1], 255);      // Verify the right-side pixel is brightened
    EXPECT_EQ(attenuatedCount, 1);        // Verify no pixels were attenuated
}

}  // namespace brighteningtest
