
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

unsigned char crc8_maxim(const unsigned char *ptr,unsigned char len)
{
    unsigned char i;
    unsigned char crc = 0;
    while(len--!=0)
    {
        for(i = 1; i != 0; i *= 2){
            if((crc & 1) != 0){
                crc /= 2;
                crc ^= 0x8C;
            }else{
                crc /= 2;
            }
            if((*ptr & i) != 0){
                crc ^= 0x8C;
            }
        }
        ptr++;
    }
    return (crc);
}

int CRC8MAXIM(lua_State *L)
{
    int i = 0;
    const unsigned char *str = luaL_checkstring(L,1);
    int len = luaL_checknumber(L,2);
    unsigned char ret = crc8_maxim(str,len);
    lua_pushinteger(L,ret);
    return 1;
}

static luaL_Reg crclibs[] = {
    {"CRC8MAXIM",CRC8MAXIM},
    {NULL,NULL}
};

int luaopen_libcrc(lua_State* L)
{
    lua_newtable(L);
    luaL_setfuncs(L,crclibs,0);
    return 1;
}
