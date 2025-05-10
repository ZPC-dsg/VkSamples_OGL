#include <dvtxTest.h>
#include <bindableTest.h>
#include <testConstant.h>
#include <modeltest.h>
#include <stb_image.h>

int main() {
	init();

	ModelTest app("scene");
	app.start();

	fin();

	return 0;
}