#include <requests>
#include <YSI-Coding\y_hooks>

hook OnPlayerDisconnect(playerid, reason)
{
    History_CollectPlayerEvent("on.player.disconnect", playerid, JsonObject(
        "reason", JsonInt(reason)
    ));
    return 1;
}
