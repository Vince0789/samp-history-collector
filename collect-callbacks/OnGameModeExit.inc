#include <requests>
#include <YSI-Coding\y_hooks>

hook OnGameModeInit()
{
    History_CollectGeneralEvent("OnGameModeExit", JsonObject());
    return 1;
}
