#include <glad/glad.h>
#include <GLFW/glfw3.h>

/* *************************** [v] PROTOTYPES [v] *************************** */
extern __inline__ void	on_resize(GLFWwindow *, const int, const int);
/* *************************** [^] PROTOTYPES [^] *************************** */

struct s_game
{
	GLFWwindow		*window;
	unsigned int	screen_width;
	unsigned int	screen_height;
} game =
{
	NULL,
	800,
	600
};

int
	main(void)
{
	// glfw: initialize and configure
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	game.window = glfwCreateWindow(
		game.screen_width,
		game.screen_height,
		"Test", NULL, NULL
	);

	if (game.window == NULL)
	{
		// Failed to create GLFW window
		glfwTerminate();
		return (-1);
	}

	glfwMakeContextCurrent(game.window);
	glfwSetFramebufferSizeCallback(game.window, on_resize);

	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		// Failed to initialize GLAD
		return (-1);
	}    

	// render loop
	while (!glfwWindowShouldClose(game.window))
	{
		// input
		{
			if (glfwGetKey(game.window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
				glfwSetWindowShouldClose(game.window, 1);
		}

		// render
		glClearColor(1.0F, 1.0F, 1.0F, 1.0F); // COLOR
		glClear(GL_COLOR_BUFFER_BIT);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		glfwSwapBuffers(game.window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	glfwTerminate();
	return (0);
}

extern __inline__ void
	on_resize(GLFWwindow *window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}