
#include "App.h"

int main(int argc, char* argv[])
{
	NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
	int retVal = UIApplicationMain(argc, argv, nil, @"App");
	[pool release];
	return retVal;
}
