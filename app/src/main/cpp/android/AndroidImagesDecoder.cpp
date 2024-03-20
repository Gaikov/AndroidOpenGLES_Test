//
// Created by Roman on 3/19/2024.
//

#include <android/imagedecoder.h>
#include "AndroidImagesDecoder.h"
#include "headers.h"

AndroidImagesDecoder::AndroidImagesDecoder(android_app *app) : _app(app) {
}

bool AndroidImagesDecoder::Init() {
    return true;
}

void AndroidImagesDecoder::Release() {

}

BitmapData *AndroidImagesDecoder::LoadFromFile(const char *fileName) const {
    auto pAndroidRobotPng = AAssetManager_open(
            _app->activity->assetManager, fileName, AASSET_MODE_BUFFER);

    // Make a decoder to turn it into a texture
    AImageDecoder *pAndroidDecoder = nullptr;
    auto result = AImageDecoder_createFromAAsset(pAndroidRobotPng, &pAndroidDecoder);
    assert(result == ANDROID_IMAGE_DECODER_SUCCESS);

    // make sure we get 8 bits per channel out. RGBA order.
    AImageDecoder_setAndroidBitmapFormat(pAndroidDecoder, ANDROID_BITMAP_FORMAT_RGBA_8888);

    // Get the image header, to help set everything up
    const AImageDecoderHeaderInfo *pAndroidHeader = nullptr;
    pAndroidHeader = AImageDecoder_getHeaderInfo(pAndroidDecoder);

    // important metrics for sending to GL
    auto width = AImageDecoderHeaderInfo_getWidth(pAndroidHeader);
    auto height = AImageDecoderHeaderInfo_getHeight(pAndroidHeader);
    auto stride = AImageDecoder_getMinimumStride(pAndroidDecoder);

    auto data = new BitmapData(width, height);

    // Get the bitmap data of the image
    auto size = stride * height;
    auto decodeResult = AImageDecoder_decodeImage(
            pAndroidDecoder,
            data->GetData(),
            stride,
            size);
    assert(decodeResult == ANDROID_IMAGE_DECODER_SUCCESS);

    // cleanup helpers
    AImageDecoder_delete(pAndroidDecoder);
    AAsset_close(pAndroidRobotPng);

    // Create a shared pointer so it can be cleaned up easily/automatically
    return data;
}
