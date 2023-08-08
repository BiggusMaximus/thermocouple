class KalmanFilter
{
public:
    KalmanFilter(float initial_state, float initial_covariance, float process_noise, float measurement_noise)
    {
        state = initial_state;
        covariance = initial_covariance;
        Q = process_noise;
        R = measurement_noise;
    }

    float predict()
    {
        // Prediction step: Project the state forward
        // Here, we assume no control input, so we omit the control matrix
        state = state; // In a more complex model, you can add motion models here
        covariance += Q;

        return state;
    }

    float update(float measurement)
    {
        // Update step: Correct the predicted state using the measurement
        float kalman_gain = covariance / (covariance + R);
        state += kalman_gain * (measurement - state);
        covariance *= (1 - kalman_gain);

        return state;
    }

    float getState()
    {
        return state;
    }

private:
    float state;
    float covariance;
    float Q; // Process noise covariance
    float R; // Measurement noise covariance
};

float initial_state = 0;
float initial_covariance = 1;
float process_noise = 0.1;
float measurement_noise = 2.0;

KalmanFilter kf1(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf2(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf3(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf4(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf5(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf6(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf7(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf8(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf9(initial_state, initial_covariance, process_noise, measurement_noise);
KalmanFilter kf10(initial_state, initial_covariance, process_noise, measurement_noise);

float *kalmanThermocouple(float thermocouple_data[])
{

    kf1.predict();
    kf2.predict();
    kf3.predict();
    kf4.predict();
    kf5.predict();
    kf6.predict();
    kf7.predict();

    kf8.predict();
    kf9.predict();
    kf10.predict();

    static float data[10] = {
        kf1.update(thermocouple_data[0]),
        kf2.update(thermocouple_data[1]),
        kf3.update(thermocouple_data[2]),
        kf4.update(thermocouple_data[3]),
        kf5.update(thermocouple_data[4]),
        kf6.update(thermocouple_data[5]),
        kf7.update(thermocouple_data[6]),
        kf8.update(thermocouple_data[7]),
        kf9.update(thermocouple_data[8]),
        kf10.update(thermocouple_data[9])};

    return data;
}