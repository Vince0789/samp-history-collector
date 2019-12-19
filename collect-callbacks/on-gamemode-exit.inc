#include <requests>
#include <YSI-Coding\y_hooks>

hook OnGameModeExit()
{
    History_CollectGeneralEvent("on.gamemode.exit", JsonObject());
    return 1;
}
