#include <requests>
#include <YSI-Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    History_CollectPlayerEvent("OnPlayerConnect", playerid, JsonObject());
    return 1;
}
