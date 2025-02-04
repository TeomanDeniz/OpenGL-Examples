/* **************************** [v] INCLUDES [v] **************************** */
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "main.h" /*
# struct s_game game;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

/* *************************** [v] PROTOTYPES [v] *************************** */
extern int	create_window(const char *const);
/* *************************** [^] PROTOTYPES [^] *************************** */

struct s_game	game =
{
	NULL,
	800,
	600
};

int
	main(void)
{

	if (!create_window("Test"))
		return (-1);

	// render loop
	while (!glfwWindowShouldClose(game.window))
	{
		// input
		if (glfwGetKey(game.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
			glfwSetWindowShouldClose(game.window, 1);

		// render
		glClearColor(1.0F, 1.0F, 1.0F, 1.0F); // COLOR
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(game.window);
		glfwPollEvents();
	}

	glfwTerminate();
	return (0);
}
