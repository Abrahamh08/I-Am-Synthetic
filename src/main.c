#define GLEW_STATIC
#include <GL/glew.h>
#ifdef __APPLE__
#  include <OpenGL/gl.h>
#  include <OpenGL/glext.h>
#else
#  include "GL/GL.h"
#endif
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

char *getRandomTitle() {
    char titleSize = 40;
    char *title = malloc(titleSize);
    char line[titleSize];
    char count = 0;
    FILE *fp = fopen("titles.txt", "r");
    while (fgets(line, titleSize, fp) != NULL) {
        count++;
        printf("%f\n", (float)RAND_MAX);
        printf("%d\n", rand());
        printf("%f\n", (float) rand() / (float)RAND_MAX);
        if ((float) rand() / (float)RAND_MAX <= (1.0 / count))
            strcpy(title, line);
    }
    fclose(fp);
    return title;
}

int main() {
    printf("!!!!");
    glewExperimental = GL_TRUE;
    #ifndef __APPLE__
    if (glewInit() != GLEW_OK) {
        printf("!!");
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    #endif
    srand(time(NULL));
    glfwSetErrorCallback(error_callback);
    printf("!!!");
    if (!glfwInit())
        exit(EXIT_FAILURE);
    printf("!");
    char *title = getRandomTitle();
    GLFWwindow* window = glfwCreateWindow(640, 480, title, NULL, NULL);
    free(title);
    if (!window) {
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    int width, height;
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
