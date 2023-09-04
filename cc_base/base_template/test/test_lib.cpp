#include <iostream>
#include "gtest/gtest.h"
#include "../lib.h"

int main(int argc, char **argv) {
    SetupUserRoutes();
    svr.listen("0.0.0.0", 8080);
	//return RUN_ALL_TESTS();
}
