#define IX(i, j) ((i) + (N + 2) * (j))

export void setBoundaryCondition(uniform size_t N, uniform size_t b,
                                 uniform float x[]) {
    foreach (i = 1 ... N + 1) {
        x[IX(0, i)] = b == 1 ? -x[IX(1, i)] : x[IX(1, i)];
        x[IX(N + 1, i)] = b == 1 ? -x[IX(N, i)] : x[IX(N, i)];
        x[IX(i, 0)] = b == 2 ? -x[IX(i, 1)] : x[IX(i, 1)];
        x[IX(i, N + 1)] = b == 2 ? -x[IX(i, N)] : x[IX(i, N)];
    }
    x[IX(0, 0)] = 0.5f * (x[IX(1, 0)] + x[IX(0, 1)]);
    x[IX(0, N + 1)] = 0.5f * (x[IX(1, N + 1)] + x[IX(0, N)]);
    x[IX(N + 1, 0)] = 0.5f * (x[IX(N, 0)] + x[IX(N + 1, 1)]);
    x[IX(N + 1, N + 1)] = 0.5f * (x[IX(N, N + 1)] + x[IX(N + 1, N)]);
}

export void solveLinearSystem(uniform size_t N, uniform int b,
                              uniform float x[], uniform float x0[],
                              uniform float buffer[], uniform float a,
                              uniform float c) {
    uniform size_t dx = 16, dy = 16;
    uniform size_t xBuckets = (N + (dx - 1)) / dx;
    uniform size_t yBuckets = (N + (dy - 1)) / dy;
    uniform size_t nTasks = xBuckets * yBuckets;

    for (int k = 0; k < 40; k++) {
        foreach_tiled (j = 1 ... N + 1, i = 1 ... N + 1) {
            //for (size_t i = 1; i < N + 1; ++i) {
                buffer[IX(i, j)] =
                    (x0[IX(i, j)] + a * (x[IX(i - 1, j)] + x[IX(i + 1, j)] +
                                         x[IX(i, j - 1)] + x[IX(i, j + 1)])) /
                    c;
            //}
        }
        setBoundaryCondition(N, b, buffer);

        uniform size_t len = (N + 2) * (N + 2);
        foreach (i = 0 ... len) { x[i] = buffer[i]; }
    }
}
