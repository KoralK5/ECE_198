#include <bits/stdc++.h>

using namespace std;

float randomFloat(float min, float max) {
    return (min + 1) + (((float) rand()) / (float) RAND_MAX) * (max - (min + 1));    
}

// function to generate random heart rate values (V)

int rate = 0;
int treshold = 10;
vector<float> voltages, times;

bool heartBeat(float n) {
	return (n >= treshold);
}

float heartRate(float startTime, float endTime) {
	return 60 / (endTime - startTime);
}

int lastBeat() {
	int n = voltages.size();
	for (int i=n-2; i>=0; i--) {
		// checks if the voltage at index i indicates a heart beat
		if (heartBeat(voltages[i])) {
			return i;
		}
	}

	// there is no previous heart beat
	return -1;
}

void heartBeat(float voltage, float time) {
	voltages.push_back(voltage);
	times.push_back(time);

	if (!heartBeat(voltage)) {
		return;
	}

	// the index of the last heart beat
	int beatIdx = lastBeat();

	if (beatIdx == -1) {
		return;
	}

	int n = voltages.size();
	rate = heartRate(times[beatIdx], times[n]);

	cout << rate << '\n';
}

int main() {
	srand(time(0)); // generating random values based on time

	for (int i=0; i<60; i++) {
		heartBeat(randomFloat(0, 15), i);
	}

	return 0;
}
