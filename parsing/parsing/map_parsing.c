
#include "parsing.h"

int	check_wall_sides(char *map)
{
	int	i;

	i = ft_strlen(map) - 1;
	while (ft_is_space(map[i]) && i >= 0)
		i--;
	if (map[i] != '1')
	{
		return put_error("MAP ISN'T SURROUNDED BY WALLS");
	}
	return 0;
}

int 	check_wall_inside(char **map, int i, int j)
{
	if (map[i][j - 1] == ' ' || map[i][j + 1] == ' ' || map[i - 1][j] == ' '
		|| map[i + 1][j] == ' ')
	{
		//exit(0);
		return put_error("MAP ISN'T SURROUNDED BY WALLS");
	}
	return 0;
}

int	check_sides_wall(char *map)
{
	int	i;

	if (!map)
		return 1;
	i = 0;
	while (map[i])
	{
		if (!ft_is_player(map[i]))
			return put_error("MAP ISN'T SURROUNDED BY WALLS");
		i++;
	}
	return 0;
}

int	check_empty_line(char **str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (str[i])
	{
		if (str[i][0] == ';' || skipp_spaces(str[i], '1') == -1)
			s = 1;
		else if (str[i][0] != ';' && s)
			return put_error("THERE IS AN EMPTY LINE");
		i++;
	}
	return 0;
}

int	map_parsing(t_map **map)
{
	int	j;
	int	i;

	i = 0;
	if ((*map)->map[i])
		 if(check_sides_wall((*map)->map[i]) == 1)
		 	return 1;
	//exit(0);
	while ((*map)->map[i])
	{
		j = 0;
		while ((*map)->map[i][j])
		{
			//exit(0);
			if (!ft_is_player((*map)->map[i][j]))
			{
				//exit(0);
				 if(check_wall_inside((*map)->map, i, j) == 1)
				 	return 1;
			}
			j++;
		}
		i++;
	}
	if ((*map)->map[i])
	{
		i--;
		 if(check_sides_wall((*map)->map[i]) == 1)
		 	return 1;
	}
	return check_empty_line((*map)->map);
}
