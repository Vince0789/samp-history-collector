
/*
 * Connection parameters
 */

#if !defined REDIS_HOST
    #define REDIS_HOST "127.0.0.1"
#endif

#if !defined REDIS_PORT
    #define REDIS_PORT 6379
#endif

#if !defined REDIS_AUTH
    #define REDIS_AUTH ""
#endif

/*
 * Channel configuration. 
 * 
 * Ideally all the channel names should start with the same prefix (e.g. "samp-") so the 
 * redis PSUBSCRIBE command can be used to subscribe to all channels simultaneously. See 
 * the logstash/logstash-sample-config.conf file for an example.
 */

#define HISTORY_DC_CHANNEL_GENERAL  "samp-general"
#define HISTORY_DC_CHANNEL_PLAYER   "samp-player"
#define HISTORY_DC_CHANNEL_VEHICLE  "samp-vehicle"
