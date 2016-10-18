#define GLEW_STATIC
#include <GL/glew.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>
#include <time.h>

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s,\n", description);
}

static void create() {
    struct Buttons_s {
        char *x;
        char *y;
    } Buttons_default = {"x"};
    typedef struct Buttons_s Buttons;
    Buttons chapterSelectBtn = Buttons_default;
    printf("%s", chapterSelectBtn.x);
}

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1)+strlen(s2) + 1);
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

char *getRandomTitle(char* path) {
    char titleSize = 40;
    char *title = malloc(titleSize);
    char line[titleSize];
    char count = 0;
    FILE *fp = fopen(concat(path, "/titles.txt"), "r");
    while (fgets(line, titleSize, fp) != NULL) {
        count++;
        if ((float) rand() / (float)RAND_MAX <= (1.0 / count))
            strcpy(title, line);
    }
    fclose(fp);
    title[strcspn(title, "\n")] = 0;
    return title;
}

int main(int argc, char *argv[]) {
    const char kPathSeparator =
    #ifdef _WIN32
        '\\';
        #else
        '/';
    #endif
    srand(time(NULL)); glfwSetErrorCallback(error_callback);
    if (!glfwInit()) {
        exit(EXIT_FAILURE);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    printf("meems\n");
    printf(argv[0]);
    int nameLen = strlen(argv[0]) - (strrchr(argv[0], kPathSeparator) - argv[0]);
    char substr[strlen(argv[0]) - nameLen + 1];
    strncpy(substr, argv[0], sizeof(substr));
    substr[sizeof substr - 1] = 0;
    printf("derp\n");
    char *title = getRandomTitle(substr);
    GLFWwindow* window = glfwCreateWindow(640, 480, title, NULL, NULL);
    free(title);
    if (!window) {
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    printf("test\n");
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("%s\n", glewGetErrorString(err));
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    int width, height;
    printf("test2\n");
    glfwGetFramebufferSize(window, &width, &height);
    glViewport(0, 0, width, height);
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    create();
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
