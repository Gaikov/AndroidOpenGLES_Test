//
// Created by Roman on 3/19/2024.
//

#include "AndroidImagesDecoder.h"

AndroidImagesDecoder::AndroidImagesDecoder(android_app *app) : _app(app) {
}

bool AndroidImagesDecoder::Init() {
    return true;
}

void AndroidImagesDecoder::Release() {

}

BitmapData *AndroidImagesDecoder::LoadFromFile(const char *fileName) const {
    return nullptr;
}
