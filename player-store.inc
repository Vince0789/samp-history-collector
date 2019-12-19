#include <a_samp>
#include <redis>
#include <requests>

#if !defined gpci
    native gpci(playerid, serial[], len);
#endif

#if !defined MAX_PLAYER_IP
    #define MAX_PLAYER_IP (15 + 1)
#endif

#if !defined MAX_PLAYER_GPCI
    #define MAX_PLAYER_GPCI (40 + 1)
#endif

#if !defined REDIS_PLAYER_STORE_KEY_SIZE
    #define REDIS_PLAYER_STORE_KEY_SIZE (20)
#endif

#if !defined REDIS_PLAYER_STORE_VALUE_SIZE
    #define REDIS_PLAYER_STORE_VALUE_SIZE (85 + MAX_PLAYER_NAME + MAX_PLAYER_IP + MAX_PLAYER_GPCI)
#endif

stock Redis_StorePlayerInfo(Redis:client, playerid)
{
    if(!IsPlayerConnected(playerid))
    {
        return 0;
    }

    new
        name[MAX_PLAYER_NAME + 1],
        ipport[15 + 5 + 2],
        pci[40 + 1];

    GetPlayerName(playerid, name, sizeof name);
    NetStats_GetIpPort(playerid, ipport, sizeof ipport);
    gpci(playerid, pci, sizeof pci);

    new Node:valueNode = JsonObject(
        "id", JsonInt(playerid),
        "name", JsonString(name),
        "ip_port", JsonString(ipport),
        "pci", JsonString(pci),
        "is_npc", JsonBool(!!IsPlayerNPC(playerid))
    );

    new 
        key[REDIS_PLAYER_STORE_KEY_SIZE],
        value[REDIS_PLAYER_STORE_VALUE_SIZE];

    format(key, sizeof key, "player:%d", playerid);
    JsonStringify(valueNode, value);
    return Redis_SetString(client, key, value);
}

stock Redis_GetPlayerInfo(Redis:client, playerid, &Node:result)
{
    new key[REDIS_PLAYER_STORE_KEY_SIZE];
    new value[REDIS_PLAYER_STORE_VALUE_SIZE];
    format(key, sizeof key, "player:%d", playerid);

    if(Redis_Exists(client, key)) 
    {
        Redis_GetString(client, key, value);
        JsonParse(value, result);
        return 1;
    }

    return 0;
}

stock Redis_DeletePlayerInfo(Redis:client, playerid)
{
    new command[4 + REDIS_PLAYER_STORE_KEY_SIZE];
    format(command, sizeof command, "DEL player:%d", playerid);
    return Redis_Command(client, command);
}
