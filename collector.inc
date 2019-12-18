#include <a_samp>
#include <redis>
#include <requests>
#include <YSI-Coding\y_hooks>

#include "redis-config.inc"
#include "player-store.inc"

static
    Redis:gClient;

#define EVENT_MAX_DATA_LENGTH   (256)

/*
 * Hooks
 */

hook OnGameModeInit()
{
    Redis_Connect(REDIS_HOST, REDIS_PORT, REDIS_AUTH, gClient);
    return 1;
}

hook OnGameModeExit()
{
    Redis_Disconnect(gClient);
    return 1;
}

hook OnPlayerConnect(playerid)
{
    Redis_StorePlayerInfo(gClient, playerid);
    return 1;
}

/*
 * Helpers
 */

stock Redis_PublishJson(Redis:client, const channel[], Node:node)
{
    new jsonString[EVENT_MAX_DATA_LENGTH];
    JsonStringify(node, jsonString);
    return Redis_Publish(client, channel, jsonString);
}

stock History_GetRoodNode(const event[], &Node:node)
{
    node = JsonObject(
        "event", JsonString(event)
    );
}

/*
 * Collectors
 */

stock History_CollectGeneralEvent(const event[], Node:params)
{
    new
        Node:rootNode;

    History_GetRoodNode(event, rootNode);
    JsonSetObject(rootNode, "params", params);

    return Redis_PublishJson(gClient, HISTORY_DC_CHANNEL_GENERAL, rootNode);
}

stock History_CollectPlayerEvent(const event[], playerid, Node:params)
{
    new
        Node:rootNode,
        Node:playerNode;

    History_GetRoodNode(event, rootNode);
    Redis_GetPlayerInfo(gClient, playerid, playerNode);
    JsonSetObject(rootNode, "player", playerNode);
    JsonSetObject(rootNode, "params", params);

    return Redis_PublishJson(gClient, HISTORY_DC_CHANNEL_PLAYER, rootNode);
}
