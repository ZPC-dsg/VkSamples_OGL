#include <dvtxTest.h>
#include <bindableTest.h>
#include <stb_image.h>

int main() {
	init();

	BindableTest app;
	app.start();

	fin();

	return 0;
}