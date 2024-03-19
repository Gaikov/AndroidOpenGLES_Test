//
// Created by Roman on 3/19/2024.
//

#ifndef ANDCPPTEST_ANDROIDGAMEAPP_H
#define ANDCPPTEST_ANDROIDGAMEAPP_H

#include <game-activity/native_app_glue/android_native_app_glue.h>
#include "engine/GameApp.h"
#include "TextureAsset.h"
#include "AndroidImagesDecoder.h"

class AndroidGameApp : public GameApp {
public:
    AndroidGameApp(android_app *app);
    virtual ~AndroidGameApp();

    ImagesDecoder *GetImageDecoder() override;

private:
    AndroidImagesDecoder *_imagesDecoder;
};


#endif //ANDCPPTEST_ANDROIDGAMEAPP_H
