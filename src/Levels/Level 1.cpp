#include <AEEngine.h>
#include <imgui/imgui.h>
#include "Level 1.h"
#include "../Framework/Ball.hh"
#include "../Framework/Player.hh"
#include "../Components/CollisionManager.hh"
#include "../Components/InputManager.hh"

int mode = 0;

bool ShowFrameworkMenu();
Ball* ball;
Player* player;
CPU* cpu;
CollisionEventManager* collmanager;
InputEventManager* inputmanager;
void Level_1_Load()
{
    ball = new Ball(0, 0);
    player = new Player(-1 * ((int)AEGetSysWindowHeight() / 2) + 50, 0);
    cpu = new CPU(((int)AEGetSysWindowHeight() / 2) - 50, 0, ball);
    collmanager = new CollisionEventManager(ball, player, cpu);
    inputmanager = new InputEventManager(player);

}

void Level_1_Init()
{
    ball->Draw();
    player->Draw();
    cpu->Draw();
    collmanager->registerEventHandler(ball->getHandler());
    collmanager->registerEventHandler(player->getHandler_coll());
    collmanager->registerEventHandler(cpu->getHandler_coll());
    inputmanager->registerEventHandler(player->getHandler());

}

void Level_1_Update()
{
    // core keyboard shortcuts and GUI, do not delete this code!
    KeyboardInput();
    bool guiActive = ShowFrameworkMenu();
    ball->Update();
    player->Update();
    cpu->Update();
    collmanager->update();
    inputmanager->update();
}

void Level_1_Render()
{
    ball->Draw();
    player->Draw();
    cpu->Draw();
    // clear frame buffer, do not delete this code

    AEGfxSetClearColor(AEGfxColor(0, 0, 0));
    AEGfxClearBuffer();
}

void Level_1_Free()
{
    delete collmanager;
    collmanager = nullptr;
    delete inputmanager;
    inputmanager = nullptr;
    delete cpu;
    cpu = nullptr;
    delete player;
    player = nullptr;
    delete ball;
    ball = nullptr;
    ball = new Ball(0, 0);
    player = new Player(-1 * ((int)AEGetSysWindowHeight() / 2) + 50, 0);
    cpu = new CPU(((int)AEGetSysWindowHeight() / 2) - 50, 0, ball);
    collmanager = new CollisionEventManager(ball, player, cpu);
    inputmanager = new InputEventManager(player);

}

void Level_1_Unload()
{
    delete collmanager;
    collmanager = nullptr;
    delete inputmanager;
    inputmanager = nullptr;
    delete cpu;
    cpu = nullptr;
    delete player;
    player = nullptr;
    delete ball;
    ball = nullptr;

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

