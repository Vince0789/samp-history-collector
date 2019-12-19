#include <requests>
#include <YSI-Coding\y_hooks>

hook OnGameModeInit()
{
    History_CollectGeneralEvent("on.gamemode.init", JsonObject());
    return 1;
}
