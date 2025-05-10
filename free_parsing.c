#include "./execution/game.h"

void free_parsing(t_map *map)
{
    int i;
   // printf("0000000000000000000000000000000\n");
   char **data;

   i = 0;
   data = map->map;
   while(data[i])
    {
        //printf("11111111111111111\n");
        free(data[i]);
        i++;
    }
    free(data);
    
    if (map->directions)
    {
        if (map->directions->no)
        {
            free(map->directions->no);
            map->directions->no = NULL;
        }
        if (map->directions->so)
        {
            free(map->directions->so);
            map->directions->so = NULL;
        }
        if (map->directions->we)
        {
            free(map->directions->we);
            map->directions->we = NULL;
        }
        if (map->directions->ea)
        {
            free(map->directions->ea);
            map->directions->ea = NULL;
        }
    }
}