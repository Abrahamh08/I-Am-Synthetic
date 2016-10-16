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
    title[strcspn(title, "\n")] = 0;
    return title;
}

int main() {
    printf("!!!!\n"); srand(time(NULL)); glfwSetErrorCallback(error_callback);
    printf("!!!\n");
    if (!glfwInit()) {
        printf("ytho\n");
        exit(EXIT_FAILURE);
    }
    printf("everything is k\n");
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    char *title = getRandomTitle();
    GLFWwindow* window = glfwCreateWindow(640, 480, title, NULL, NULL);
    free(title);
    if (!window) {
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    printf("good good\n");
    glewExperimental = GL_TRUE;
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        printf("%s\n", glewGetErrorString(err));
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    printf("!\n");
    int width, height;
    printf("memee\n");
    glfwGetFramebufferSize(window, &width, &height);
    printf("meeeem\n");
    glViewport(0, 0, width, height);
    GLuint VBO;
    printf("mem\n");
    glGenBuffers(1, &VBO);
    printf("memr\n");
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    printf("derp\n");
    create();
    printf("meems\n");
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
