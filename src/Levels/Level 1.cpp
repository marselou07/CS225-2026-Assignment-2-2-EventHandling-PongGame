#include <AEEngine.h>
#include <imgui/imgui.h>
#include "Level 1.h"
#include "../Framework/Ball.hh"
#include "../Framework/Player.hh"
#include "../Components/CollisionManager.hh"
#include "../Components/InputManager.hh"
/******************************************************************************
filename    Level 1.cc
author      Markel Susial de la fuente
DP email    markel.susial@digipen.edu
course      cs225
assignment  2.2
due date    27/10/2026

Brief Description: This program will create the logic for the level
******************************************************************************/
int mode = 0;

bool ShowFrameworkMenu();
Ball* ball;
Player* player;
CPU* cpu;
CollisionEventManager* collmanager;
InputEventManager* inputmanager;
/**
 * Level_1_Load
 * @param context: load all the resources for the scene
 * @return nothing
 */
void Level_1_Load()
{
    ball = new Ball(0, 0);
    player = new Player(-1 * ((int)AEGetSysWindowHeight() / 2) + 50, 0);
    cpu = new CPU(((int)AEGetSysWindowHeight() / 2) - 50, 0, ball);
    collmanager = new CollisionEventManager(ball, player, cpu);
    inputmanager = new InputEventManager(player);

}
/**
 * Level_1_Init
 * @param context: initialize by drawing and setting the managers
 * on the scene
 * @return nothing
 */
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
/**
 * Level_1_Update
 * @param context: update the position and the managers
 * on the screen
 * @return nothing
 */
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
/**
 * Level_1_Render
 * @param context: draw the object each frame
 * @return nothing
 */
void Level_1_Render()
{
    ball->Draw();
    player->Draw();
    cpu->Draw();
    // clear frame buffer, do not delete this code

    AEGfxSetClearColor(AEGfxColor(0, 0, 0));
    AEGfxClearBuffer();
}
/**
 * Level_1_Free
 * @param context: unload and initialize
 * everything again
 * @return nothing
 */
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
/**
 * Level_1_Unload
 * @param context: just unload everything
 * @return nothing
 */
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

