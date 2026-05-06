#define _CRT_SECURE_NO_WARNINGS
#include "Image_Merger.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"


void Image_Merger::mergeImages(const std::vector<std::string>& filePaths, const std::string& outputPath) {
    if (filePaths.empty()) return;

    std::vector<unsigned char*> images;
    int maxWidth = 0, maxHeight = 0;

    //Load images and find the largest dimensions
    for (const std::string& file : filePaths) {
        int w, h, c;
        unsigned char* img = stbi_load(file.c_str(), &w, &h, &c, 4); // Force 4 channels (RGBA)
        if (img) {
            images.push_back(img);
            maxWidth = std::max(maxWidth, w);
            maxHeight = std::max(maxHeight, h);
        }
    }

    // Create Canvas Buffer
    std::vector<unsigned char> canvas(maxWidth * maxHeight * 4, 0);

    // overlap images into same canvas
    for (unsigned char* img : images) {

        for (int y = 0; y < maxHeight; ++y) {
            for (int x = 0; x < maxWidth; ++x) {
                int idx = (y * maxWidth + x) * 4;

                if (img[idx + 3] > 0) { 
                    canvas[idx + 0] = img[idx + 0]; // R
                    canvas[idx + 1] = img[idx + 1]; // G
                    canvas[idx + 2] = img[idx + 2]; // B
                    canvas[idx + 3] = img[idx + 3]; // A
                }
            }
        }
    }

    // 4. Save result
    stbi_write_png(outputPath.c_str(), maxWidth, maxHeight, 4, canvas.data(), maxWidth * 4);

    for (auto p : images) stbi_image_free(p);
}