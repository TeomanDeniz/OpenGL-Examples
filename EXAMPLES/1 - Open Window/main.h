#ifndef MAIN_H
#	define MAIN_H 202501
struct s_game
{
	GLFWwindow		*window;
	unsigned int	screen_width;
	unsigned int	screen_height;
};

extern struct s_game	game;

#endif /* MAIN_H */