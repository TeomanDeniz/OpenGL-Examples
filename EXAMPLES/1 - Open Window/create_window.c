
/* **************************** [v] INCLUDES [v] **************************** */
#include <glad/glad.h> /*
#    int gladLoadGLLoader(GLADloadproc);
#   void glViewport(int, int, int, int);
#        */
#include <GLFW/glfw3.h> /*
#    int glfwInit(void);
#   void glfwTerminate(void);
#   void glfwWindowHint(int, int);
#>>>>>>> (GLFWwindow)
#^^^^^^^ *glfwCreateWindow(int, int, const char *, GLFWmonitor *, GLFWwindow *);
#   void glfwMakeContextCurrent(GLFWwindow *);
#   void glfwSetFramebufferSizeCallback(GLFWwindow *, GLFWframebuffersizefun);
#>>>>>>> (GLADloadproc)
#^^^^^^^ glfwGetProcAddress(const char *name);
#        */
#include "main.h" /*
# struct s_game game;
#        */
/* **************************** [^] INCLUDES [^] **************************** */

static void
	on_resize(GLFWwindow *window, const int width, const int height)
{
	glViewport(0, 0, width, height);
}

int
	create_window(const char *const title)
{
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
		title, NULL, NULL
	);

	if (game.window == NULL)
	{
		// Failed to create GLFW window
		glfwTerminate();
		return (0);
	}

	glfwMakeContextCurrent(game.window);
	glfwSetFramebufferSizeCallback(game.window, on_resize);

	// glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		return (0); // Failed to initialize GLAD

	return (1);
}