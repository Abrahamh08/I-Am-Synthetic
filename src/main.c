#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLFW/glfw3.h>

static void error_callback(int error, const char* description) {
    fprintf(stderr, "Error: %s,\n", description);
}

static void create() {
    glBegin(GL_TRIANGLES);
    glColor3f(
}

static void update() {
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
    srand(time(NULL));
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    char *title = getRandomTitle();
    GLFWwindow* window = glfwCreateWindow(640, 480, title, NULL, NULL);
    free(title);
    if (!window) {
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    create();
    while (!glfwWindowShouldClose(window)) {
        glfwSwapBuffers();
        glfwPollEvents();
        update();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
}
