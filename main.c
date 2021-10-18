#include "circularQueue.h"
#include <stdio.h>

int main() {
	CircularQueue* que = createCircularQueue(10);


	for (int i = 0; i < 7; ++i) {
		put(que, 1);
	}
}
