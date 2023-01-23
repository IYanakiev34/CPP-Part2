#include "main.ih"

int main(int argc, char **argv)
{
    int numPrimes = atoi(argv[1]);
    bool isFinished = false;

    // Start the dot thread, compute primes and track start/end time
    std::thread dotThread(displayDots, std::ref(isFinished));

    auto start = std::chrono::system_clock::now();
    std::vector <size_t> primes = findPrimes(numPrimes, isFinished);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    time_t startTime = std::chrono::system_clock::to_time_t(start);
    time_t endTime = std::chrono::system_clock::to_time_t(end);

    dotThread.join();

    // Print the primes and the time information
    std::copy(primes.begin(), primes.end(),
              std::ostream_iterator<size_t>(std::cout, " "));
    std::cout << "\n\n" << "Starting time: "
              << std::ctime(&startTime)
              << "Ending time: "
              << std::ctime(&endTime)
              << "Computation of " << numPrimes << " primes took "
              << elapsed_seconds.count() << " seconds\n";
}