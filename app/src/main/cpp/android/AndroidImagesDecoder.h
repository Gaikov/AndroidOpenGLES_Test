//
// Created by Roman on 3/19/2024.
//

#ifndef ANDCPPTEST_ANDROIDIMAGESDECODER_H
#define ANDCPPTEST_ANDROIDIMAGESDECODER_H

#include <game-activity/native_app_glue/android_native_app_glue.h>
#include "images/ImagesDecoder.h"

class AndroidImagesDecoder : public ImagesDecoder {
public:
    explicit AndroidImagesDecoder(android_app *app);

    android_app *_app;

private:
    bool Init() override;

    void Release() override;

    BitmapData *LoadFromFile(const char *fileName) const override;
};

#endif //ANDCPPTEST_ANDROIDIMAGESDECODER_H
