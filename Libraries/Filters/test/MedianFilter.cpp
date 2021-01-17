#include <Arduino.h>
#include <ArduinoUnitTests.h>

#include "MedianFilter.hpp"

bool	TestForArray(int nums[], int samplecount, int expected)
{
	MedianFilter filter(samplecount);
	
	filter.Reset();
	
	for (int i = 0; i < samplecount; i++) {
	    filter.NewReading(nums[i]);
	}
	const int16_t f_avg = filter.GetFilteredSignal();

	return (f_avg == expected);
}

unittest(PeakFilter)
{
	// how to turn -std=c++0x on?
	int nums[] = {1, 1, 1, 5};
	assertTrue(TestForArray(nums, sizeof(nums)/sizeof(int), 1));

	int nums1[] = {1};
	assertTrue(TestForArray(nums1, sizeof(nums1)/sizeof(int), 1));

	int nums2[] = {1, 5, 3, 2};
	assertTrue(TestForArray(nums2, sizeof(nums2)/sizeof(int), 3));

	int nums3[] = {-500, 100, 500, 100, 100};
	assertTrue(TestForArray(nums3, sizeof(nums3)/sizeof(int), 100));
}

unittest_main()
