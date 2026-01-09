#include "glad.h"
#include <GL/glut.h>

#include "glad.c"

// Clears the current window and draws a triangle.
void display() {
  if (!glClear) {
    printf("glClear not loaded.\n");
    return;
  }

  // Set every pixel in the frame buffer to the current clear color.
  glClear(GL_COLOR_BUFFER_BIT);

  // Drawing is done by specifying a sequence of vertices.  The way these
  // vertices are connected (or not connected) depends on the argument to
  // glBegin.  GL_POLYGON constructs a filled polygon.
  glBegin(GL_POLYGON);
  glColor3f(1, 0, 0);
  glVertex3f(-0.6, -0.75, 0.5);
  glColor3f(0, 1, 0);
  glVertex3f(0.6, -0.75, 0);
  glColor3f(0, 0, 1);
  glVertex3f(0, 0.75, 0);
  glEnd();

  // Flush drawing command buffer to make drawing happen as soon as possible.
  glFlush();
}

extern void __populate_libc_table();

// Initializes GLUT, the display mode, and main window; registers callbacks;
// enters the main event loop.
int main(int argc, char **argv) {
  printf("%d args\n", argc);
  void *glutLib = dlopen("libglut.so", RTLD_LAZY | RTLD_GLOBAL);
  if (!glutLib) {
    printf("glutLib null\n");
    return 0;
  }

  // void *glewLib = dlopen("libGLEW.so", RTLD_LAZY | RTLD_GLOBAL);
  // if (!glutLib) {
  //   printf("glewLib null\n");
  //   return 0;
  // }
  void (*glutInit)(int *pargc, char **argv) = dlsym(glutLib, "glutInit");
  if (!glutInit) {
    printf("glutInit null\n");
  }

  void (*glutInitDisplayMode)(unsigned int displayMode) =
      dlsym(glutLib, "glutInitDisplayMode");
  void (*glutInitWindowPosition)(int x, int y) =
      dlsym(glutLib, "glutInitWindowPosition");
  void (*glutInitWindowSize)(int width, int height) =
      dlsym(glutLib, "glutInitWindowSize");
  int (*glutCreateWindow)(const char *title) =
      dlsym(glutLib, "glutCreateWindow");
  void (*glutDisplayFunc)(void (*callback)(void)) =
      dlsym(glutLib, "glutDisplayFunc");
  void (*glutMainLoop)(void) = dlsym(glutLib, "glutMainLoop");

  // Use a single buffered window in RGB mode (as opposed to a
  // double-buffered window or color-index mode).
  int i = 0;
  glutInit(&i, NULL);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  // Position window at (80,80)-(480,380) and give it a title.
  glutInitWindowPosition(80, 80);
  glutInitWindowSize(400, 300);
  glutCreateWindow("A Simple Triangle");

  // Tell GLUT that whenever the main window needs to be repainted that it
  // should call the function display().
  glutDisplayFunc(display);

  gladLoadGL();

  // Tell GLUT to start reading and processing events.  This function
  // never returns; the program only exits when the user closes the main
  // window or kills the process.
  glutMainLoop();
}
