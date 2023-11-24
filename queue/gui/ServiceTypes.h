#ifndef _QUEUE_GUI_SERVICE_TYPES_
#define _QUEUE_GUI_SERVICE_TYPES_

#include <cstdint>

struct Statistic {
	uint64_t tactCount = 0;
	double middleBusyProcessor = 0;
	uint64_t tactInactionCount = 0;
	uint64_t taskComplitedCount = 0;
	uint64_t taskInWorkCount = 0;
	uint64_t taskSkipedCount = 0;
	uint64_t taskCount = 0;
};

struct Task {
	int id;
	size_t tactCount;
	size_t procCount;
	size_t color;
};

struct Processor {
	Task task;
	size_t stepCount = 0;
	size_t taskTactCount = 0;
	size_t emptyTactCount = 0;

	bool isEmpty = true;
};

#endif _QUEUE_GUI_SERVICE_TYPES_