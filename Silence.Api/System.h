
#pragma once

#include "InteractionLayerExport.h"
#include "SceneManager.h"
#include "AssetManager.h"
#include "GPU.h"

class SILENCE_EXPORT_API OperatingSystem
{
    SceneManager sceneManager;
    AssetManager assetManager;
    Window windowManager;
public:
    OperatingSystem();
    virtual ~OperatingSystem();

    SceneManager * acquireSceneManager();
    AssetManager * acquireAssetManager();
    Gamepad * acquireGamepad();
    Window& acquireWindow();

    bool setupLibraries();

    void enableDoubleBuffering();
    void enableSingleBuffering();
    void releaseLibraries();
    void executeProgram();
private:
    bool swapBuffers;
};

SILENCE_EXPORT_API int bootstrap(std::function<void(OperatingSystem *)> onApplicationStart);