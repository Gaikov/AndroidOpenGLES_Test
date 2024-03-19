//
// Created by Roman on 3/19/2024.
//

#include "AndroidGameApp.h"

AndroidGameApp::AndroidGameApp(android_app *app) {
    _imagesDecoder = new AndroidImagesDecoder(app);
}

AndroidGameApp::~AndroidGameApp() {
    delete _imagesDecoder;
}

ImagesDecoder *AndroidGameApp::GetImageDecoder() {
    return _imagesDecoder;
}



