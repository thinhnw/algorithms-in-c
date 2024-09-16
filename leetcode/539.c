int timeToMinutes(char* time) {
    int hours, minutes;
    sscanf(time, "%d:%d", &hours, &minutes);
    return hours * 60 + minutes;
}

int compare(const void* a, const void* b) {
    int int_a = *(const int*)a;
    int int_b = *(const int*)b;
    return int_a - int_b;
}

int findMinDifference(char** timePoints, int timePointsSize) {
    int* minutes = (int*)malloc(timePointsSize * sizeof(int));
    for (int i = 0; i < timePointsSize; ++i) {
        minutes[i] = timeToMinutes(timePoints[i]);
    }
    qsort(minutes, timePointsSize, sizeof(int), compare);

    int result = minutes[0] + 24 * 60 - minutes[timePointsSize - 1];
    for (int i = 1; i < timePointsSize; ++i) {
        result = result > minutes[i] - minutes[i - 1] ? minutes[i] - minutes[i - 1] : result;
    }

    free(minutes);
    return result;
}