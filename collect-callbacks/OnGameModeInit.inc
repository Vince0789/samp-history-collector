#include <requests>
#include <YSI-Coding\y_hooks>

hook OnGameModeInit()
{
    History_CollectGeneralEvent("OnGameModeInit", JsonObject());
    return 1;
}
