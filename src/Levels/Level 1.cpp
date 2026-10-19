#include <AEEngine.h>
#include <imgui/imgui.h>
#include "Level 1.h"
#include "../Framework/Ball.hh"
#include "../Framework/Player.hh"
#include "../Components/CollisionManager.hh"
int mode = 0;

bool ShowFrameworkMenu();
Ball* ball;
Player* player;
CollisionEventManager* collmanager;
void Level_1_Load()
{
    ball = new Ball(0, 0);
    player = new Player(-1 * ((int)AEGetSysWindowHeight() / 2) + 50, 0);
    collmanager = new CollisionEventManager(ball, player);
    collmanager->registerEventHandler(ball->getHandler());
    collmanager->registerEventHandler(player->getHandler());

}

void Level_1_Init()
{
    ball->Draw();
    player->Draw();
}

void Level_1_Update()
{
    // core keyboard shortcuts and GUI, do not delete this code!
    KeyboardInput();
    bool guiActive = ShowFrameworkMenu();
    ball->Update();
    collmanager->update();
}

void Level_1_Render()
{
    // clear frame buffer, do not delete this code
    ball->Draw();
    player->Draw();
    AEGfxSetClearColor(AEGfxColor(0, 0, 0));
    AEGfxClearBuffer();
}

void Level_1_Free()
{

}

void Level_1_Unload()
{
}

void KeyboardInput()
{
    if (AEInputKeyTriggered('R'))
        AESetGameStateNext(AE_GS_RESTART);
    if (AEInputKeyTriggered('Q') && AEInputKeyPressed(AE_KEY_CTRL))
        AESetGameStateNext(AE_GS_QUIT);
}

bool ShowFrameworkMenu()
{
    bool isGuiActive = false;
    mode = 0;

    // show File options 
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Mode")) {

            if (ImGui::MenuItem("Restart", "1"))
                mode = 1;

            ImGui::EndMenu();
        }

        auto mSize = ImGui::GetWindowHeight();
        AEVec2 mouseVP = AEGetMouseData().position + AEVec2((float)AEGetSysWindowWidth() / 2.0f, (float)AEGetSysWindowHeight() / 2.0f);
        auto inMenu = mouseVP.y >= (AEGetSysWindowHeight() - mSize);
        isGuiActive = ImGui::IsAnyItemActive() || ImGui::IsAnyItemHovered() || inMenu;

        ImGui::EndMainMenuBar();
    }

    if (mode == 1) {
        AESetGameStateNext(AE_GS_RESTART);
    }

    return isGuiActive;
}

