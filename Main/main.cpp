#include <dvtxTest.h>
#include <bindableTest.h>
#include <testConstant.h>
#include <stb_image.h>

int main() {
	init();

	TestConstant app;
	app.start();

	fin();

	return 0;
}