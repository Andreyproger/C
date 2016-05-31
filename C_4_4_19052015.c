#include <stdio.h>

struct Time {
	int hours;
	int minuts;
	int sec;
};

void print_time(struct Time time) {
	printf("%02d:%02d:%02d\n", time.hours, time.minuts, time.sec);
}

struct Time inc_time(struct Time time, int sec) {
	time.sec += sec;
	while(time.sec >= 60){
		time.minuts++;
		time.sec -= 60;
	}
	while(time.minuts >= 60) {
		time.hours++;
		time.minuts -= 60;
	}
	while(time.hours >= 23)
		time.hours -= 23;
	return time;
}

int cmp_time(struct Time time1, struct Time time2) {
	if(time1.hours < time2.hours)
		return -1;
	else if(time1.hours > time2.hours)
		return 1;
	else {
		if(time1.minuts < time2.minuts)
			return -1;
		else if(time1.minuts > time2.minuts)
			return 1;
		else {
			if(time1.sec < time2.sec)
				return -1;
			else if(time1.sec > time2.sec)
				return 1;
			else {
				return 0;
			}
		}
	}

}

void swap_time(struct Time* time1, struct Time* time2) {
	int temp = time1->sec;
	time1->sec = time2->sec;
	time2->sec = temp;
	temp = time1->minuts;
	time1->minuts = time2->minuts;
	time2->minuts = temp;
	temp = time1->hours;
	time1->hours = time2->hours;
	time2->hours = temp;
}

int main() {

	struct Time time1, time2;
	time1.hours = 18, time2.hours = 18;
	time1.minuts = 58, time2.minuts = 32;
	time1.sec = 19, time2.sec = 19;
	print_time(time1);
	printf("\n");
	print_time(time2);
	printf("\n");

	printf("%d\n", cmp_time(time1, time2));

	time1 = inc_time(time1, 1024);
	print_time(time1);
	printf("\n");

	swap_time(&time1, &time2);
	print_time(time1);
	printf("\n");
	print_time(time2);
	printf("\n");

	return 0;

}
