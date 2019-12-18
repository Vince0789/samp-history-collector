
// ---------------------------------------------------------------------------------------
// Connection parameters
// ---------------------------------------------------------------------------------------

#if !defined REDIS_HOST
    #define REDIS_HOST "127.0.0.1"
#endif

#if !defined REDIS_PORT
    #define REDIS_PORT 6379
#endif

#if !defined REDIS_AUTH
    #define REDIS_AUTH ""
#endif

// ---------------------------------------------------------------------------------------
// Channel configuration
// ---------------------------------------------------------------------------------------

#define HISTORY_DC_CHANNEL_GENERAL  "samp-general"
#define HISTORY_DC_CHANNEL_PLAYER   "samp-player"
#define HISTORY_DC_CHANNEL_VEHICLE  "samp-vehicle"
