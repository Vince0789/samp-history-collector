#include <requests>
#include <YSI-Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    History_CollectPlayerEvent("on.player.connect", playerid, JsonObject());
    return 1;
}
